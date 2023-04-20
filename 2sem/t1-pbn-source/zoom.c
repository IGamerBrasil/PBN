/*
 * Nomes = Lucas Chagas e Lucas Machado
 * Data = 18/04/2023
*/
#include <stdio.h>
#include <stdlib.h>
#include "lib_ppm.h"

int main()
{
	struct image_s data;
	struct image_s *image = &data;

	struct image_s data1;
	struct image_s *imageOriginal = &data1;
	int i, j, r;

	r = read_ppm("lena.ppm", imageOriginal);
	if (r == 0)
	{
		matrizPix(imageOriginal);
	}

	r = new_ppm(image, imageOriginal->width*3, imageOriginal->height*3);	

	//algoritmo exclusivamente para matrizes de subpixels de 3 linhas e colunas
	if (r == 0){
		int y = 0;
		 for (j = 0; j < imageOriginal->height; j++){
			int x = 0;
			for (i = 0; i < imageOriginal->width; i++){
				
				int r1 = imageOriginal->pix[j * imageOriginal->width + i].matrizSub[0][0];
				int r2 = imageOriginal->pix[j * imageOriginal->width + i].matrizSub[1][0];
				int r3 = imageOriginal->pix[j * imageOriginal->width + i].matrizSub[2][0];	

				int g1 = imageOriginal->pix[j * imageOriginal->width + i].matrizSub[0][1];
				int g2 = imageOriginal->pix[j * imageOriginal->width + i].matrizSub[1][1];				
				int g3 = imageOriginal->pix[j * imageOriginal->width + i].matrizSub[2][1];

				int b1 = imageOriginal->pix[j * imageOriginal->width + i].matrizSub[0][2];
				int b2 = imageOriginal->pix[j * imageOriginal->width + i].matrizSub[1][2];
				int b3 = imageOriginal->pix[j * imageOriginal->width + i].matrizSub[2][2];	

				 image->pix[y * image->width + x].r = r1;
				 image->pix[y * image->width + x].g = 0;
				 image->pix[y * image->width + x].b = 0;	

				 image->pix[(y+1) * image->width + x].r = r2;
				 image->pix[(y+1) * image->width + x].g = 0;
				 image->pix[(y+1) * image->width + x].b = 0;	

				 image->pix[(y+2) * image->width + x].r = r3;
				 image->pix[(y+2) * image->width + x].g = 0;
				 image->pix[(y+2) * image->width + x].b = 0;	

				 image->pix[y * image->width + (x+1)].r = 0;
				 image->pix[y * image->width + (x+1)].g = g1;
				 image->pix[y * image->width + (x+1)].b = 0;	

				 image->pix[(y+1) * image->width + (x+1)].r = 0;
				 image->pix[(y+1) * image->width + (x+1)].g = g2;
				 image->pix[(y+1) * image->width + (x+1)].b = 0;	

				 image->pix[(y+2) * image->width + (x+1)].r = 0;
				 image->pix[(y+2) * image->width + (x+1)].g = g3;
				 image->pix[(y+2) * image->width + (x+1)].b = 0;	

				 image->pix[y * image->width + (x+2)].r = 0;
				 image->pix[y * image->width + (x+2)].g = 0;
				 image->pix[y * image->width + (x+2)].b = b1;	

				 image->pix[(y+1) * image->width + (x+2)].r = 0;
				 image->pix[(y+1) * image->width + (x+2)].g = 0;
				 image->pix[(y+1) * image->width + (x+2)].b = b2;	

				 image->pix[(y+2) * image->width + (x+2)].r = 0;
				 image->pix[(y+2) * image->width + (x+2)].g = 0;
				 image->pix[(y+2) * image->width + (x+2)].b = b3;	

				x+=3;
			}
			y+=3;
		}	
		write_ppm("lena_test.ppm", image);
		free_ppm(image);
		free_ppm(imageOriginal);
	}

	return 0;
}