/* file:          lib_ppm.h
 * description:   PPM library
 * date:          03/2023
 * author:        Sergio Johann Filho <sergio.johann@acad.pucrs.br>
 */

struct pixel_s {
	unsigned char r, g, b;
	int matrizSub[3][3];
};

struct image_s {
	int width;
	int height;
	struct pixel_s *pix;
};

void matrizPix(struct image_s *image);
int read_ppm(char *file, struct image_s *image);
int write_ppm(char *file, struct image_s *image);
int new_ppm(struct image_s *image, int width, int height);
int free_ppm(struct image_s *image);