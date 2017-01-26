#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmp.h"

int main(int argc, char ** argv)
{
	if (argc < 3) {
		fprintf(stderr, "Too few arguments.\n");
		return EXIT_FAILURE;
	}
	int count = 0;
	int horizontal = 0;
	int vertical = 0;
	for (count = 1; count < (argc - 2); count++) {
		if (strcmp(argv[count], "-h") == 0) {
			horizontal++;
		} else if (strcmp(argv[count], "-v") == 0) {
			vertical++;
		} else {
			fprintf(stderr, "Invalid option.\n");
			return EXIT_FAILURE;
		}
	}
	FILE* infile = fopen(argv[argc - 2], "r");
	if (infile == NULL) {
		fprintf(stderr, "Unable to open file for read.\n");
		return EXIT_FAILURE;
	}
	BMP_Image* image = Read_BMP_Image(infile);
	if (image == NULL) {
		fprintf(stderr, "Failure to read.\n");
		fclose(infile);
		return EXIT_FAILURE;
	}
	fclose(infile);
	FILE* outfile = fopen(argv[argc - 1], "w");
	if (outfile == NULL) {
		fprintf(stderr, "Unable to open file for write.\n");
		Free_BMP_Image(image);
		return EXIT_FAILURE;
	}
	BMP_Image* result = Reflect_BMP_Image(image, horizontal%2, vertical%2);
	int check = Write_BMP_Image(outfile, result);
	fclose(outfile);
	Free_BMP_Image(image);
	Free_BMP_Image(result);
	if (check == TRUE) {
		return EXIT_SUCCESS;
	} else {
		return EXIT_FAILURE;
	}
}
