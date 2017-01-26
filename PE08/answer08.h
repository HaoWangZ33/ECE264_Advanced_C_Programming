#ifndef PE08_H
#define PE08_H 

#define WALL 'X'
#define PATH ' '

#include <stdio.h>

/* a structure for storing a maze                         */
/* int nrow: number of rows in the maze                   */  
/* int ncol: number of columns in the maze                */
/* char **maze: a two-dimensional array to store the maze */ 
/* Note that the ncol should not count '\n', even if your */
/* implementation stores '\n' in maze_array               */
/* In other words, nrow and ncol account for only         */
/* characters that correspond to WALL or PATH             */

typedef struct _Maze {
   int nrow;
   int ncol;
   char **maze_array;  
} Maze;

// allocate space from heap memory for the user-defined structure Maze, and
// allocate nrow x ncol maze and store the address in the structure (in maze_array)
// also assign nrow and ncol fields in the structure accordingly
// if allocation fails, return NULL
// if allocation fails, you are also responsible for freeing the memory
// allocated in this function before the failure
// may assume that nrow and ncol are > 0

Maze *Allocate_maze_space(int nrow, int ncol);

// free the memory used for the maze
// you may assume that maze is not NULL, and all memory addresses are valid

void Deallocate_maze_space(Maze *maze)
			__attribute__((nonnull));
 
/* Read maze in a multi-line file and store the necessary information */
/* into a 2D array of characters.  The address of the 2D array and the */
/* dimensions of the 2D array should be stored in a Maze structure allocated */
/* from the heap memory */
/* if the allocation fails, should return NULL */

Maze *Read_maze_from_2Dfile(FILE *fptr)
			__attribute__((nonnull));

/* Write the maze into a multi-line file */
/* the maze has to stay intact */

int Write_maze_to_2Dfile(char *filename, const Maze *maze)
			__attribute__((nonnull));

/* Expand the maze from nrow x ncol to (2nrow - 1) x ncol */
/* the top half of the maze is the same as the original maze */
/* the bottom half of the maze is a reflection of the original maze */
/* You have to allocate space for a new maze */
/* the nrow and ncol fields of the new maze have to be assigned accordingly */
/* if you can't expand the maze because of memory issue, NULL should be */
/* returned */
/* the original maze has to stay intact */

Maze *Expand_maze_row(const Maze *maze)
			__attribute__((nonnull));

/* Expand the maze from nrow x ncol to nrow x 2ncol - 1 */
/* the left half of the maze is the same as the original maze */
/* the right half of the maze is a reflection of the original maze */
/* moreover, you have to create an opening between the left and right halves */
/* the opening should be at the middle row of the maze */
/* the opening must also be accessible from one of the paths in the */
/* new maze */
/* to do that, you have to convert some locations that are WALL to PATH */
/* starting from the new opening to the left and to the right until you reach */
/* a location that is adjacent to a location that is PATH */
/* You have to allocate space for a new maze */
/* the nrow and ncol fields of the new maze have to be assigned accordingly */
/* if you can't expand the maze because of memory issue, NULL should be */
/* returned */
/* the original maze has to stay intact */

Maze *Expand_maze_column(const Maze *maze)
			__attribute__((nonnull));

/* the following functions will be defined by instructors   */
/* you do not have to define these functions                */
/* if you have to create your own function in this exercise */
/* do not name your functions with a prefix of "__"         */

Maze *__Allocate_maze_space(int nrow, int ncol);

void __Deallocate_maze_space(Maze *maze)
			__attribute__((nonnull));
 
Maze *__Read_maze_from_2Dfile(FILE *fptr)
			__attribute__((nonnull));

int __Write_maze_to_2Dfile(char *filename, const Maze *maze)
			__attribute__((nonnull));

Maze *__Expand_maze_row(const Maze *maze)
			__attribute__((nonnull));

Maze *__Expand_maze_column(const Maze *maze)
			__attribute__((nonnull));

#endif
