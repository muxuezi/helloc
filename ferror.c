#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

extern int errno ;

int main ()
{
   int dividend = 20;
   int divisor = 0;
   int quotient; 
   FILE * pf;
   int errnum;
   pf = fopen ("unexist.txt", "rb");
   if (pf == NULL)
   {
      errnum = errno;
      fprintf(stderr, "Value of errno: %d\n", errno);
      perror("Error printed by perror");
      fprintf(stderr, "Error opening file: %s\n", strerror( errnum ));
   }
   else
   {
      fclose (pf);
   }

   if( divisor == 0){
      fprintf(stderr, "Division by zero! Exiting...\n");
      exit(-1);
      //exit(EXIT_FAILURE);
   }
   quotient = dividend / divisor;
   fprintf(stderr, "Value of quotient : %d\n", quotient );
   exit(0);
   //exit(EXIT_SUCCESS);
   return 0;
}
