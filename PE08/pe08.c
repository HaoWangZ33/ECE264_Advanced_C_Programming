#include <stdio.h>
#include <stdlib.h>
#include "answer08.h"

int main(int argc, char ** argv)
{
   FILE *rfp;

   rfp = fopen(argv[1], "r");
   if (rfp == NULL) {
      fclose(rfp);
      return EXIT_FAILURE;
   }

   Maze* original;
   original = Read_maze_from_2Dfile(rfp);
   printf("read successful \n");
   
   Maze* row_s;
   int count_row = 0;
   row_s = Expand_maze_row(original);
   count_row = Write_maze_to_2Dfile(argv[2], row_s);
   printf("row_s count = %d \n", count_row);
   
   Maze* col_s;
   int count_col = 0;
   col_s = Expand_maze_column(original);
   count_col = Write_maze_to_2Dfile(argv[3], col_s);
   printf("col_s count = %d \n", count_col);

   Deallocate_maze_space(original);
   Deallocate_maze_space(row_s);
   Deallocate_maze_space(col_s);

   fclose(rfp);
   return EXIT_SUCCESS;
}

