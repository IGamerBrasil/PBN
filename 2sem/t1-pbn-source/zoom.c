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
				
				// printf("x = %d y = %d\n\n",x,y);
				int r1 = imageOriginal->pix[j * imageOriginal->width + i].matrizSub[0][0];
				int r2 = imageOriginal->pix[j * imageOriginal->width + i].matrizSub[1][0];
				int r3 = imageOriginal->pix[j * imageOriginal->width + i].matrizSub[2][0];	

				// printf("r1 = %d, r2 = %d, r3 = %d\n\n",r1,r2,r3);	

				int g1 = imageOriginal->pix[j * imageOriginal->width + i].matrizSub[0][1];
				int g2 = imageOriginal->pix[j * imageOriginal->width + i].matrizSub[1][1];				
				int g3 = imageOriginal->pix[j * imageOriginal->width + i].matrizSub[2][1];

				// printf("g1 = %d, g2 = %d, g3 = %d\n\n",g1,g2,g3);	

				int b1 = imageOriginal->pix[j * imageOriginal->width + i].matrizSub[0][2];
				int b2 = imageOriginal->pix[j * imageOriginal->width + i].matrizSub[1][2];
				int b3 = imageOriginal->pix[j * imageOriginal->width + i].matrizSub[2][2];	

				// printf("b1 = %d, b2 = %d, b3 = %d\n\n",b1,b2,b3);
	
				 image->pix[y * image->width + x].r = r1;
				 image->pix[y * image->width + x].g = 0;
				 image->pix[y * image->width + x].b = 0;	

				// printf("Matriz\n\n");	

				// printf("(%d,%d) r = %d g = %d b = %d\n", y, x, image->pix[y * image->width + x].r,
				// 											 image->pix[y * image->width + x].g,
				// 											 image->pix[y * image->width + x].b);	
				 image->pix[(y+1) * image->width + x].r = r2;
				 image->pix[(y+1) * image->width + x].g = 0;
				 image->pix[(y+1) * image->width + x].b = 0;	
				// printf("(%d,%d) r = %d g = %d b = %d\n", y, x+1, image->pix[y * image->width + (x+1)].r,
				// 											   image->pix[y * image->width + (x+1)].g,
				// 											   image->pix[y * image->width + (x+1)].b);	
				 image->pix[(y+2) * image->width + x].r = r3;
				 image->pix[(y+2) * image->width + x].g = 0;
				 image->pix[(y+2) * image->width + x].b = 0;	
				// printf("(%d,%d) r = %d g = %d b = %d\n", y, x+2, image->pix[y * image->width + (x+2)].r,
				// 											   image->pix[y * image->width + (x+2)].g,
				// 											   image->pix[y * image->width + (x+2)].b);	
				 image->pix[y * image->width + (x+1)].r = 0;
				 image->pix[y * image->width + (x+1)].g = g1;
				 image->pix[y * image->width + (x+1)].b = 0;	
				// printf("(%d,%d) r = %d g = %d b = %d\n", y+1, x, image->pix[(y+1) * image->width + x].r,
				// 											   image->pix[(y+1) * image->width + x].g,
				// 											   image->pix[(y+1) * image->width + x].b);	
				 image->pix[(y+1) * image->width + (x+1)].r = 0;
				 image->pix[(y+1) * image->width + (x+1)].g = g2;
				 image->pix[(y+1) * image->width + (x+1)].b = 0;	
				// printf("(%d,%d) r = %d g = %d b = %d\n", y+1, x+1, image->pix[(y+1) * image->width + (x+1)].r,
				// 											   image->pix[(y+1) * image->width + (x+1)].g,
				// 											   image->pix[(y+1) * image->width + (x+1)].b);	
				 image->pix[(y+2) * image->width + (x+1)].r = 0;
				 image->pix[(y+2) * image->width + (x+1)].g = g3;
				 image->pix[(y+2) * image->width + (x+1)].b = 0;	
				// printf("(%d,%d) r = %d g = %d b = %d\n", y+1, x+2, image->pix[(y+1) * image->width + (x+2)].r,
				// 											   image->pix[(y+1) * image->width + (x+2)].g,
				// 											   image->pix[(y+1) * image->width + (x+2)].b);	
				 image->pix[y * image->width + (x+2)].r = 0;
				 image->pix[y * image->width + (x+2)].g = 0;
				 image->pix[y * image->width + (x+2)].b = b1;	
				// printf("(%d,%d) r = %d g = %d b = %d\n", y+2, x, image->pix[(y+2) * image->width + x].r,
				// 											   image->pix[(y+2) * image->width + x].g,
				// 											   image->pix[(y+2) * image->width + x].b);	
				 image->pix[(y+1) * image->width + (x+2)].r = 0;
				 image->pix[(y+1) * image->width + (x+2)].g = 0;
				 image->pix[(y+1) * image->width + (x+2)].b = b2;	
				// printf("(%d,%d) r = %d g = %d b = %d\n", y+2, x+1, image->pix[(y+2) * image->width + (x+1)].r,
				// 											 	   image->pix[(y+2) * image->width + (x+1)].g,
				// 											       image->pix[(y+2) * image->width + (x+1)].b);	
				 image->pix[(y+2) * image->width + (x+2)].r = 0;
				 image->pix[(y+2) * image->width + (x+2)].g = 0;
				 image->pix[(y+2) * image->width + (x+2)].b = b3;	
				// printf("(%d,%d),  r = %d g = %d b = %d\n", y+2, x+2, image->pix[(y+2) * image->width + (x+2)].r,
				// 											       image->pix[(y+2) * image->width + (x+2)].g,
				// 											       image->pix[(y+2) * image->width + (x+2)].b);
				// printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
				x+=3;
				// printf("i = %d\n",i);
				// printf("x = %d\n\n",x);
			}
			y+=3;
			// printf("j = %d\n",j);	
			// printf("y = %d\n\n",y);
		}	
		// printf("terminou");
		write_ppm("test.ppm", image);
		free_ppm(image);
		free_ppm(imageOriginal);
	}

	return 0;
}