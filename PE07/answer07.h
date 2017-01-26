#ifndef PE07_H
#define PE07_H 

#define WALL 'X'
#define PATH ' '

/* The __attribute__ mechanism attaches characteristics to function 
   declarations to allow the compiler to perform more error checking.
   In this exercise, all parameters that are storing addresses should 
   be non-NULL.  */

#include <stdio.h>

/* Determine the dimensions of the maze contain in file. */
/* The maze will always be of the correct format */
/* the number of rows is to be stored at location pointed to by nrow */ 
/* the number of ncol is to be stored at location pointed to by ncol */

void Find_maze_dimensions(FILE *fptr, int *nrow, int *ncol)
			__attribute__((nonnull));

/* Determine the column location of the top opening */
/* You may assume that the maze is of the correct format */

int Find_opening_location(FILE *fptr)
			__attribute__((nonnull (1)));

/* Count the number of locations that are PATH  */
/* A location is a PATH if it is a space, ' ', or PATH */
/* You may assume that the maze is of the correct format */

int Count_path_locations(FILE *fptr)
			__attribute__((nonnull (1)));

/* Return the type of location: WALL or PATH, i.e. 'X' or ' ' */
/* In other words, return the character in the file for that location */ 
/* The location is specified by its row-column coordinates. */
/* The coordinates are specified by row and col */
/* These coordinates will always be valid for the given maze */
/* You do not have to worry about the coordinates being out of range */
/* You may assume that the maze is of the correct format */

char Get_location_type(FILE *fptr, int row, int col)
			__attribute__((nonnull (1)));
 
/* Given a filename, re-represent the maze in the file pointer fptr */
/* in a single line */
/* The return value should be the number of characters written into the */
/* the new file */
/* if the writing to a file fails, you should return -1 */ 
/* You may assume that the maze is of the correct format */

int Represent_maze_in_one_line(char *filename, FILE *fptr)
			__attribute__((nonnull));

#endif
