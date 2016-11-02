#include<stdio.h>
#include "test.txt"
main() {

   FILE *fs;
   char buff[255];

   fs = fopen("test.txt", "r");
   fscanf(fs, "%s", buff);
   printf("1 : %s\n", buff );

   fgets(buff, 255, (FILE*)fs);
   printf("2: %s\n", buff );
   
   fgets(buff, 255, (FILE*)fs);
   printf("3: %s\n", buff );

   fclose(fs);
}


