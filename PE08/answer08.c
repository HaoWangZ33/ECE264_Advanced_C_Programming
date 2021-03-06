#include <stdio.h>
#include <stdlib.h>
#include "answer08.h"

Maze *Allocate_maze_space(int nrow, int ncol)
{
   Maze *result;
   result = malloc(sizeof(*result));
   if (result == NULL){
      return NULL;}

   result->nrow = nrow;
   result->ncol = ncol;

   result->maze_array = malloc(sizeof(*(result->maze_array)) * nrow);
   if (result->maze_array == NULL){
      free(result);
      return NULL;}

   int i = 0;
   for(i = 0; i < nrow; i++){
      result->maze_array[i] = malloc(sizeof(char) * ncol);
      if (result->maze_array[i] == NULL){
         int fi;
         for(fi = 0; fi < i; fi++){
            free(result->maze_array[fi]);
         }
         free(result->maze_array);
         free(result);
         return NULL;
      }
   }

   return result;
}

void Deallocate_maze_space(Maze *maze)
{
   int i = 0;
   for (i = 0; i < maze->nrow; i++){
      free(maze->maze_array[i]);
   }
   free(maze->maze_array);
   free(maze);
}

Maze *Read_maze_from_2Dfile(FILE *fptr)
{
   int ch;
   int nrow = 0;
   int ncol = 0;

   fseek(fptr, 0, SEEK_SET);
   while ((ch = fgetc(fptr)) != '\n'){
      ncol = ncol + 1;
   }
   fseek(fptr, 0, SEEK_SET);
   while ((ch = fgetc(fptr)) != EOF){
      if (ch == '\n') {
         nrow = nrow + 1;
      }
   }

   Maze* maze;
   maze = Allocate_maze_space(nrow, ncol);
   if (maze == NULL){
      return NULL;
   }

   int count_row = 0;
   int count_col = 0;
   fseek(fptr, 0, SEEK_SET);
   while ((ch = fgetc(fptr)) != EOF){
      if (ch == '\n'){
         count_row = count_row + 1;
         count_col = 0;
      } else {
         maze->maze_array[count_row][count_col] = ch;
         count_col = count_col + 1;
      }
   }

   return maze;
}

int Write_maze_to_2Dfile(char *filename, const Maze *maze)
{
   FILE *wfp;
   int count = 0;
   
   wfp = fopen(filename, "w");
   if (wfp == NULL) {
      fclose(wfp);
      return EXIT_FAILURE;
   }
   
   fseek(wfp, 0, SEEK_SET);

   int i = 0;
   int j = 0;

   for (i = 0; i < maze->nrow; i++){
      for (j = 0; j < maze->ncol; j++){
         fputc(maze->maze_array[i][j], wfp);
         count = count + 1;
      }
      fputc('\n', wfp);
      count = count + 1;
   }

   fclose(wfp);
   return count;
}

Maze *Expand_maze_row(const Maze *maze)
{
   Maze* new_maze;
   int nrow;
   int ncol;
   nrow = 2 * (maze->nrow) - 1;
   ncol = maze->ncol;
   new_maze = Allocate_maze_space(nrow, ncol);
   if (new_maze == NULL){
      return NULL;
   }

   int i = 0;
   int j = 0;
   for (i = 0; i < maze->nrow; i++){
      for (j = 0; j < ncol; j++){
         new_maze->maze_array[i][j] = maze->maze_array[i][j];
      }
   }
   for (i = maze->nrow; i < new_maze->nrow; i++){
      for (j = 0; j < ncol; j++){
         new_maze->maze_array[i][j] = maze->maze_array[((maze->nrow - 2) - (i - maze->nrow))][j];
      }
   }

   return new_maze;
}

Maze *Expand_maze_column(const Maze *maze)
{
   Maze* new_maze;
   int nrow;
   int ncol;
   nrow = maze->nrow;
   ncol = 2 * (maze->ncol) - 1;
   new_maze = Allocate_maze_space(nrow, ncol);
   if (new_maze == NULL){
      return NULL;
   }

   int i = 0;
   int j = 0;
   for (i = 0; i < nrow; i++){
      for (j = 0; j < maze->ncol; j++){
         new_maze->maze_array[i][j] = maze->maze_array[i][j];
      }
   }
   for (i = 0; i < nrow; i++){
      for (j = maze->ncol; j < new_maze->ncol; j++){
         new_maze->maze_array[i][j] = maze->maze_array[i][((maze->ncol - 2) - (j - maze->ncol))];
      }
   }

   int row = nrow / 2;
   int col = maze->ncol - 1;
   new_maze->maze_array[row][col] = ' ';
   if (new_maze->maze_array[row][col-1] == 'X'){
      do{
         row = row;
         col = col - 1;
         new_maze->maze_array[row][col] = ' ';
      }while((new_maze->maze_array[row-1][col] == 'X') && (new_maze->maze_array[row+1][col] == 'X') && (new_maze->maze_array[row][col-1] == 'X'));
   }
   if (new_maze->maze_array[row][col+1] == 'X'){
      do{
         row = row;
         col = col + 1;
         new_maze->maze_array[row][col] = ' ';
      }while((new_maze->maze_array[row-1][col] == 'X') && (new_maze->maze_array[row+1][col] == 'X') && (new_maze->maze_array[row][col+1] == 'X'));
   }

   return new_maze;
}

