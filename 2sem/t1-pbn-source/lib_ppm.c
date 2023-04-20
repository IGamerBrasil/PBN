/* file:          lib_ppm.c
 * description:   PPM library
 * date:          03/2023
 * author:        Sergio Johann Filho <sergio.johann@acad.pucrs.br>
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lib_ppm.h"


int read_ppm(char *file, struct image_s *image)
{
	FILE *fptr;
	char *t;
	char buf[128];
	int r, d, i, j;
	struct pixel_s *img_data;
	
	fptr = fopen(file, "rb");
	if (!fptr)
		return -1;
		
	t = fgets(buf, sizeof(buf), fptr);struct image_s data;
	struct image_s *image = &data;

	struct image_s data1;
	struct image_s *imageOriginal = &data1;
	if (!t)
		goto failread;
	
	if (strncmp(buf, "P6\n", 3) != 0)
		goto failread;

        do {
		t = fgets(buf, sizeof(buf), fptr);
		if (!t)
			goto failread;
				
	} while (strncmp(buf, "#", 1) == 0);
	
        r = sscanf(buf, "%u %u", &image->width, &image->height);
        if (r < 2)
		goto failread;

        r = fscanf(fptr, "%u", &d);
        if ((r < 1) || (d != 255))
		goto failread;
		
        fseek(fptr, 1, SEEK_CUR);
        
        img_data = malloc(image->width * image->height * sizeof(struct pixel_s));
        if (!img_data)
		goto failread;
        
        image->pix = img_data;
        
        for (j = 0; j < image->height; j++)
		for (i = 0; i < image->width; i++)
			fread(&img_data[j * image->width + i], 3, 1, fptr);
	
	fclose(fptr);

	return 0;
	
failread:
	fclose(fptr);
	
	return -1;
}


int write_ppm(char *file, struct image_s *image)
{
	FILE *fptr;
	int i, j;
	
	fptr = fopen(file, "wb");
	if (!fptr)
		return -1;
		
	fprintf(fptr, "P6\n%d %d\n255\n", image->width, image->height);
        for (j = 0; j < image->height; j++)
		for (i = 0; i < image->width; i++)
			fwrite(&image->pix[j * image->width + i], 3, 1, fptr);

	fclose(fptr);
	
	return 0;
}


int new_ppm(struct image_s *image, int width, int height)
{
	struct pixel_s *img_data;

	image->width = width;
	image->height = height;
	
        img_data = malloc(image->width * image->height * sizeof(struct pixel_s));
        if (!img_data)
		return -1;
        
        image->pix = img_data;
        memset(image->pix, 0, image->width * image->height * sizeof(struct pixel_s));
	
	return 0;
}


int free_ppm(struct image_s *image)
{
	if (image->pix) {
		free(image->pix);
		
		return 0;
	}
	
	return -1;
}

void matrizPix(struct image_s *image){
	for (int j = 0; j < image->height; j++){
		for (int i = 0; i < image->width; i++){
			
			int g = image->pix[j * image->width + i].g;
			int r = image->pix[j * image->width + i].r;
			int b = image->pix[j * image->width + i].b;

			int novaMatriz[3][3];

			if(r >= 0 && r <= 74){
				novaMatriz[0][0] = 0;
				novaMatriz[1][0] = 0;
				novaMatriz[2][0] = 0;
			}
			else if (r >= 75 && r <= 134){
				novaMatriz[0][0] = 0;
				novaMatriz[1][0] = r;
				novaMatriz[2][0] = 0;
			}
			else if(r >= 135 && r <= 179){
				novaMatriz[0][0] = r;
				novaMatriz[1][0] = 0;
				novaMatriz[2][0] = r;
			}else{
				novaMatriz[0][0] = r;
				novaMatriz[1][0] = r;
				novaMatriz[2][0] = r;
			}

			if(g >= 0 && g <= 74){
				novaMatriz[0][1] = 0;
				novaMatriz[1][1] = 0;
				novaMatriz[2][1] = 0;
			}
			else if (g >= 75 && g <= 134){
				novaMatriz[0][1] = 0;
			}
			else if(g >= 135 && g <= 179){
				novaMatriz[0][1] = g;
				novaMatriz[1][1] = 0;
				novaMatriz[2][1] = g;
			}else{
				novaMatriz[0][1] = g;
				novaMatriz[1][1] = g;
				novaMatriz[2][1] = g;
			}

			if(b >= 0 && b <= 74){
				novaMatriz[0][2] = 0;
				novaMatriz[1][2] = 0;
				novaMatriz[2][2] = 0;
			}
			else if (b >= 75 && b <= 134){
				novaMatriz[0][2] = 0;
				novaMatriz[1][2] = b;
				novaMatriz[2][2] = 0;
			}
			else if(b >= 135 && b <= 179){
				novaMatriz[0][2] = b;
				novaMatriz[1][2] = 0;
				novaMatriz[2][2] = b;
			}else{
				novaMatriz[0][2] = b;
				novaMatriz[1][2] = b;
				novaMatriz[2][2] = b;
			}
							   
			for (int k = 0; k < 3; k++) {
				for(int l = 0; l < 3; l++){
      				image->pix[j * image->width + i].matrizSub[l][k] = novaMatriz[l][k];
				}
    		}
			// printf("Imagem tem largura %d e altura %d\n",image->width,image->height);
			// printf("r = %03d, g = %03d, b = %03d\n\n",r,g,b);
			// printf("(%d,%d)\nr%03d,g%03d,b%03d\nr%03d,g%03d,b%03d\nr%03d,g%03d,b%03d\n\n",j,i,image->pix[j * image->width + i].matrizSub[0][0],image->pix[j * image->width + i].matrizSub[0][1],image->pix[j * image->width + i].matrizSub[0][2],
			// 																				image->pix[j * image->width + i].matrizSub[1][0],image->pix[j * image->width + i].matrizSub[1][1],image->pix[j * image->width + i].matrizSub[1][2],
			// 																				image->pix[j * image->width + i].matrizSub[2][0],image->pix[j * image->width + i].matrizSub[2][1],image->pix[j * image->width + i].matrizSub[2][2]);
		}
	}
}
