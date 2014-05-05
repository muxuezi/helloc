/* Program 5.2 from PTRTUT10.HTM 6/13/97 */
#include <stdio.h>
#include <string.h>

/* the structure type */
struct tag{
    char lname[20];                         /* last name */
    char fname[20];                         /* last name */
    int age;                                        /* last name */
    float rate;                                    /*e.g. 12.75 per hour */
};

struct tag my_struct;                     /* define the structure */
void show_name(struct tag *p); /* function prototype */

int main(void)
{
    struct tag *st_ptr;                     /* a pointer to a structure */
    st_ptr = &my_struct;                 /* point the pointer to my_struct */
    strcpy(my_struct.lname,"Jensen");
    strcpy(my_struct.fname,"Ted");
    printf("\n%s ",my_struct.fname);
    printf("%s\n",my_struct.lname);
    my_struct.age = 63;
    show_name(st_ptr);                 /* pass the pointer */
    return 0;
}

void show_name(struct tag *p)
{
    printf("\n%s ", p->fname);     /* p points to a structure */
    printf("%s ", p->lname);
    printf("%d\n", p->age);
}