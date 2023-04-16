#include <stdio.h>
#include "lib_ppm.h"

int main()
{
	struct image_s data;
	struct image_s *image = &data;
	int i, j, r;

	r = read_ppm("lena.ppm", image);
	//algoritmo exclusivamente para matrizes de subpixels de 3 linhas e colunas
	if (r == 0)
	{
		printf("width: %d, height: %d\n", image->width, image->height);
		image->height = image->height*3;
		image->height = image->width*3;
		for (j = 0; j < image->height; j++)
		{
			for (i = 0; i < image->width; i++)
			{
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
				}

				if(g >= 0 && g <= 74){
					novaMatriz[0][1] = 0;
					novaMatriz[1][1] = 0;
					novaMatriz[2][1] = 0;
				}
				else if (g >= 75 && g <= 134){
					novaMatriz[0][1] = 0;
					novaMatriz[1][1] = b;
					novaMatriz[2][1] = 0;
				}
				else if(g >= 135 && g <= 179){
					novaMatriz[0][1] = g;
					novaMatriz[1][1] = 0;
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
				}
				
				int mdRed = (novaMatriz[0][0]+novaMatriz[1][0]+novaMatriz[2][0])/3;
				int mdGreen = (novaMatriz[0][1]+novaMatriz[1][1]+novaMatriz[2][1])/3;
				int mdBlue = (novaMatriz[0][2]+novaMatriz[1][2]+novaMatriz[2][2])/3;

				printf("r%d, g%d, b%d\nr%d,g%d,b%d\nr%d,g%d,b%d\n",novaMatriz[0][0],novaMatriz[0][1],novaMatriz[0][2],
																   novaMatriz[1][0],novaMatriz[1][1],novaMatriz[1][2],
																   novaMatriz[2][0],novaMatriz[2][1],novaMatriz[2][2]);
				printf("medias: r = %d, g = %d, b = %d\n\n", mdRed, mdGreen, mdBlue);

				image->pix[j * image->width + i].g = mdGreen;
				image->pix[j * image->width + i].r = mdRed;
				image->pix[j * image->width + i].b = mdBlue;
																   
			}
		}

		write_ppm("lena_copy.ppm", image);

		free_ppm(image);
	}

	r = new_ppm(image, 675, 428);

	if (r == 0)
	{
		image->pix[100 * image->width + 125].r = 255;
		image->pix[27 * image->width + 440].g = 255;

		image->pix[371 * image->width + 10].r = 100;
		image->pix[371 * image->width + 10].g = 100;
		image->pix[371 * image->width + 10].b = 0;

		write_ppm("test.ppm", image);
		free_ppm(image);
	}

	return 0;
}