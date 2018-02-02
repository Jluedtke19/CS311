#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main( int argc, char** argv ) {
    char *test;
    char *x [] = {"ab", "bc", "cd"};

    char *str = "blablabla";
    char c = 'H';

    size_t len = strlen(str);
    char *str2 = malloc(len + 1 + 1 );

    strcpy(str2, str);
    str2[len] = c;
    str2[len + 1] = '\0';

    //printf( "%s\n", str2 );
    //printf("%zu\n", strlen(str2));
    memset(str2, 0, sizeof str2);
    //printf("%s\n", str2);
    //printf("%lu\n", sizeof(int));

    int i, n;
   int *a;

  n = 10;

   a = (int*)calloc(n, sizeof(int));
   for( i=0 ; i < n ; i++ ) {
      a[i] = i;
   }

   for( i=0 ; i < n ; i++ ) {
      //printf("%d ",a[i]);
   }
   free( a );

   int ret = 0;
   char *num = "abcdefghijklmnopqrstuvwxyz";
   for(int j = 0; j < strlen(num); j++){
     ret += (int)num[i];
   }
   //printf("%d\n", (ret % 5000) );
   printf("%d\n", (char) "'");

   return(0);



 }
