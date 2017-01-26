#include <stdio.h>
#include <stdlib.h>
#include "answer07.h"

void Find_maze_dimensions(FILE *fptr, int *nrow, int *ncol)
{
   int ch;
   *nrow = *ncol = 0;
   fseek(fptr, 0, SEEK_SET);
   while ((ch = fgetc(fptr)) != '\n'){
      *ncol = *ncol + 1;
   }
   fseek(fptr, 0, SEEK_SET);
   while ((ch = fgetc(fptr)) != EOF){
      if (ch == '\n') {
         *nrow = *nrow + 1;
      }
   }
}

int Find_opening_location(FILE *fptr)
{
   fseek(fptr, 0, SEEK_SET);
   int location = 0;
   int ch;
   while ((ch = fgetc(fptr)) != ' '){
      location = location + 1;
   }
   return location;
}

int Count_path_locations(FILE *fptr)
{
   int ch;
   fseek(fptr, 0, SEEK_SET);
   int count = 0;
   while ((ch = fgetc(fptr)) != EOF){
      if (ch == ' ') {
         count = count + 1;
      }
   }
   return count;
}

char Get_location_type(FILE *fptr, int row, int col) {
   int ch;
   fseek(fptr, 0, SEEK_SET);
   int count;
   for (count = 0; count < row; count++){
      while ((ch = fgetc(fptr)) != '\n'){}
   }
   for (count = 0; count < col; count++){
      ch = fgetc(fptr);
   }
   ch = fgetc(fptr);
   return (char)ch;
}

int Represent_maze_in_one_line(char *filename, FILE *fptr)
{
   FILE *wfp;
   int count = 0;
   int ch;
   
   wfp = fopen(filename, "w");
   if (wfp == NULL) {
      fclose(wfp);
      return EXIT_FAILURE;
   }
   
   fseek(fptr, 0, SEEK_SET);
   fseek(wfp, 0, SEEK_SET);

   while ((ch = fgetc(fptr)) != EOF){
      if (ch != '\n' && ch != EOF){
         fputc(ch, wfp);
         count = count + 1;
      }
   }
   fclose(wfp);
   return count;
}
