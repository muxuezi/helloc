#include <stdio.h>

int factorial(unsigned int i)
{
   if(i <= 1)
   {
      return 1;
   }
   return i * factorial(i - 1);
}

int fibonaci(int i)
{
   if(i == 0)
   {
      return 0;
   }
   if(i == 1)
   {
      return 1;
   }
   return fibonaci(i-1) + fibonaci(i-2);
}

int  main()
{

    int i;
    printf( "Enter a value :");
    scanf("%d", &i);
    printf("Factorial of %d is %d\n", i, factorial(i));
    for (i = 0; i < 10; i++)
    {
       printf("%d\t", fibonaci(i));
    }
    printf("\n");
    return 0;
}
