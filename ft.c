#include<stdio.h>
#include "test1.txt"
main() {

   FILE *ft;
   char buff[255];

   fs = fopen("test1.txt", "r");
   fscanf(ft, "%s", buff);
   printf("1 : %s\n", buff );

   fgets(buff, 255, (FILE*)ft);
   printf("2: %s\n", buff );
   
   fgets(buff, 255, (FILE*)ft);
   printf("3: %s\n", buff );

   fclose(ft);
}


