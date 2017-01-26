#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer04.h"

int main(int argc, char ** argv)
{
	FILE* infile;
	long int* array;
	charnode* head;

	if (argc != 5) {
		fprintf(stderr, "Usage: ./pe10 inputfile outputfile1 outputfile2 outputfile3\n");
		return EXIT_FAILURE;
	}
   
	infile = fopen(argv[1], "r");
	if (infile == NULL) {
		fprintf(stderr, "Failure to open inputfile");
		return EXIT_FAILURE;
	}

	array = (long int*)malloc(sizeof(*array) * 256);
	if (array == NULL) {
		fclose(infile);
		fprintf(stderr, "Malloc fail");
		return EXIT_FAILURE;
	}
	read_file(array, infile);
	fclose(infile);

	head = construct_list(array);
	free(array);
	

	charnode_destroy(head);
	return EXIT_SUCCESS;
}
