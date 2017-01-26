#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmp.h"

int main(int argc, char ** argv)
{
	if (argc != 3) {
		fprintf(stderr, "Too few/too much arguments.\n");
		return EXIT_FAILURE;
	}
	FILE* infile = fopen(argv[1], "r");
	if (infile == NULL) {
		fprintf(stderr, "Unable to open file for read.\n");
		return EXIT_FAILURE;
	}
	BMP_Image* image = Read_BMP_Image(infile);
	fclose(infile);
	if (image == NULL) {
		fprintf(stderr, "Failure to read.\n");
		return EXIT_FAILURE;
	}
	BMP_Image* new_image = NULL;
	if (image->header.bits == 16) {
		new_image = Convert_16_to_24_BMP_Image(image);
	} else {
		new_image = Convert_24_to_16_BMP_Image(image);
	}
	if (new_image == NULL) {
		fprintf(stderr, "Failure to convert.\n");
		return EXIT_FAILURE;
	}
	FILE* outfile = fopen(argv[2], "w");
	if (outfile == NULL) {
		fprintf(stderr, "Unable to open file for write.\n");
		Free_BMP_Image(image);
		Free_BMP_Image(new_image);
		return EXIT_FAILURE;
	}
	int check = Write_BMP_Image(outfile, new_image);
	fclose(outfile);
	Free_BMP_Image(image);
	Free_BMP_Image(new_image);
	if (check == TRUE) {
		return EXIT_SUCCESS;
	} else {
		return EXIT_FAILURE;
	}
}
