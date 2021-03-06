#include <stdio.h>
#include <stdlib.h>
#include "answer07.h"

int main(int argc, char ** argv)
{
   int nrow;
   int ncol;
   FILE *rfp;
   int open_location;
   int count_path;
   char location_type;
   int char_count;

   rfp = fopen(argv[1], "r");
   if (rfp == NULL) {
      fclose(rfp);
      return EXIT_FAILURE;
   }

   Find_maze_dimensions(rfp, &nrow, &ncol);
   printf("dimension: row: %d col: %d \n", nrow, ncol);

   open_location = Find_opening_location(rfp);
   printf("open: %d \n", open_location);

   count_path = Count_path_locations(rfp);
   printf("path count: %d \n", count_path);

   location_type = Get_location_type(rfp, 1, 1);
   printf("location 1,1 is type %c \n", location_type);
   location_type = Get_location_type(rfp, 2, 2);
   printf("location 2,2 is type %c \n", location_type);

   char_count = Represent_maze_in_one_line(argv[2], rfp);
   printf("total char count: %d \n", char_count);
     
   fclose(rfp);
   return EXIT_SUCCESS;
}

