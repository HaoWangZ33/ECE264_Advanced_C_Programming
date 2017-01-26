#include <stdlib.h>
#include <stdio.h>
#include "bmp.h"

int Is_BMP_Header_Valid(BMP_Header* header, FILE *fptr) {
	if (header->type != 0x4d42) {
		return FALSE;
	}
	if (header->offset != BMP_HEADER_SIZE) {
		return FALSE;
	}
	if (header->DIB_header_size != DIB_HEADER_SIZE) {
		return FALSE;
	}
	if (header->planes != 1) {
		return FALSE;
	}
	if (header->compression != 0) {
		return FALSE;
	}
	if (header->ncolours != 0) {
		return FALSE;
	}
	if (header->importantcolours != 0) {
		return FALSE;
	}
	if (header->bits != 24 && header->bits != 16) {
		return FALSE;
	}
	fseek(fptr, 0, SEEK_END);
	int size = ftell(fptr);
	int remainder = ((header->width) * (header->bits / 8)) % 4;
	int width = (header->width) * (header->bits / 8);
	if (remainder == 0) {
		width = width;
	} else if (remainder == 1) {
		width = width + 3;
	} else if (remainder == 2) {
		width = width + 2;
	} else {
		width = width + 1;
	}
	if (header->imagesize != (header->height * width)) {
		return FALSE;
	}
	if (header->size != size) {
		return FALSE;
	}
	return TRUE;
}

BMP_Image *Read_BMP_Image(FILE* fptr) {
	if (fptr == NULL) {
		fprintf(stderr, "File pointer is invalid.\n");
		return NULL;
	}
	fseek(fptr, 0, SEEK_SET);
	BMP_Image *bmp_image = malloc(sizeof(*bmp_image));
	if (bmp_image == NULL) {
		fprintf(stderr, "Malloc fail.\n");
		return NULL;
	}
	int read = fread(&(bmp_image->header), 1, 54, fptr);
	if (read == 54) {
		int valid = Is_BMP_Header_Valid(&(bmp_image->header), fptr);
		if (valid == TRUE) {
			bmp_image->data = malloc(sizeof(unsigned char) * (bmp_image->header.imagesize));
			if (bmp_image->data == NULL) {
				fprintf(stderr, "Malloc fail.\n");
				free(bmp_image);
				return NULL;
			}
			fseek(fptr, 54, SEEK_SET);
			long long int read2 = fread((bmp_image->data), 1, (bmp_image->header.imagesize), fptr);
			if (read2 == bmp_image->header.imagesize) {
				return bmp_image;
			}
		}
	}
	Free_BMP_Image(bmp_image);
	return NULL;
}

int Write_BMP_Image(FILE* fptr, BMP_Image* image) 
{
	if (fptr == NULL) {
		fprintf(stderr, "File pointer is invalid.\n");
		return FALSE;
	}
	fseek(fptr, 0, SEEK_SET);
	int check1, check2;
	check1 = fwrite(&(image->header), 1, 54, fptr);
	fseek(fptr, 54, SEEK_SET);
	check2 = fwrite(image->data, 1, image->header.imagesize, fptr);
	if ((check1 == 54) && (check2 == image->header.imagesize)) {
		return TRUE;
	} else {
		return FALSE;
	}
}

void Free_BMP_Image(BMP_Image* image) {
	free(image->data);
	free(image);
}

// Given a BMP_Image, create a new image that is a reflection 
// of the given image
// It could be a horizontal reflection (with the vertical mirror 
// being placed at the center of the image) 
// It could be a vertical reflection (with the horizontal mirror
// being placed at the center of the image)
// It could be a horizontal reflection followed by a vertical
// reflection (or equivalently, a vertical reflection followed by
// horizontal reflection).
// hrefl == 1 implies that a horizontal reflection should take place
// hrefl == 0 implies that a horizontal reflection should not take place
// vrefl == 1 implies that a vertical reflection should take place
// vrefl == 0 implies that a vertical reflection should not take place

BMP_Image *Reflect_BMP_Image(BMP_Image *image, int hrefl, int vrefl)
{
	if (image == NULL) {
		fprintf(stderr, "BMP_Image pointer is invalid.\n");
		return NULL;
	}
	BMP_Image *t_image = malloc(sizeof(*t_image));
	if (t_image == NULL) {
		fprintf(stderr, "Malloc fail.\n");
		return NULL;
	}
	t_image->header = image->header;
	t_image->data = malloc(sizeof(unsigned char) * (t_image->header.imagesize));
	int count = 0;
	int count1 = 0;
	int count2 = 0;
	int width_byte = (image->header.width) * (image->header.bits / 8);
	int remainder = width_byte % 4;
	int pad;
	int width_pix = image->header.width;
	unsigned char temp;
	if (remainder == 0) {
		width_byte = width_byte;
		pad = 0;
	} else if (remainder == 1) {
		width_byte = width_byte + 3;
		pad = 3;
	} else if (remainder == 2) {
		width_byte = width_byte + 2;
		pad = 2;
	} else {
		width_byte = width_byte + 1;
		pad = 1;
	}
	unsigned char (*pointer_row)[width_byte] = (unsigned char(*)[width_byte])image->data;
	unsigned char (*t_pointer_row)[width_byte] = (unsigned char(*)[width_byte])t_image->data;
	unsigned char (*t_pointer)[image->header.bits / 8];
	if (hrefl == 0 && vrefl == 0) {
		for (count = 0; count < t_image->header.imagesize; count++) {
			t_image->data[count] = image->data[count];
		}
	}
	if (vrefl == 1) {
		for (count = 0; count < image->header.height; count++) {
			for (count1 = 0; count1 < width_byte; count1++) {
				t_pointer_row[count][count1] = pointer_row[image->header.height - count - 1][count1];
			}
		}
	}
	if (hrefl == 1) {
		if (vrefl == 0) {
			for (count = 0; count < t_image->header.imagesize; count++) {
				t_image->data[count] = image->data[count];
			}
		}
		for (count = 0; count < image->header.height; count++) {
			t_pointer = (unsigned char (*)[image->header.bits / 8])t_pointer_row[count];
			for (count1 = 0; count1 < (width_pix/2); (count1)++) {
				for (count2 = 0; count2 < (image->header.bits / 8); (count2)++) {
					temp = t_pointer[count1][count2];
					t_pointer[count1][count2] = t_pointer[width_pix - count1 - 1][count2];
					t_pointer[width_pix - count1 - 1][count2] = temp;
				}
			}
		}
	}
	return t_image;
}

