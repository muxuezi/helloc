#include <stdio.h>
main()
{
int array[] = {4,8,6,7};
int *array_ptr = array;
printf(" first element: %i\n", *++array_ptr);
printf("second element: %i\n", ++(*array_ptr));
printf(" third element: %i\n", *array_ptr);
return 0;
}
