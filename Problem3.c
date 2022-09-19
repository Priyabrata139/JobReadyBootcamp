/* Problem staemant 3

Looking at an above image, actually that image is zoomed up version of pdf file.
As we see there is ‘A’ shaped character, it has three vertices which has coordinate
(20.077,11.598) , (26.526, 90.138) , (23.674, 32.579).
We have to cover the area under ‘A’ shaped character and colour it black.
Calculate area under ‘A’ shaped character
#include<stdio.h>
#include<conio.h>
void main(){
double area;
/* We all know that, there is no function named find_distance exists, so you have to
include this function in your library.

area_under_A = find_area(parameter1, parameter2,.......);
printf("Area to be coloured black: %lf\n",area_under_A);
}

 */



#include <stdio.h>
#include <stdlib.h>
double mod(double d); 
double find_area(char s1[], char s2[], char s3[]);

double mod(double d) // takeing always positive value
{
    if (d < 0)
    {
        return -1 * d;
    }
}
double find_area(char s1[], char s2[], char s3[]) // actual function
{
    double x1, x2, x3, y1, y2, y3;
    char *ptr1, *ptr2, *ptr3, *ptr4, *ptr5, *ptr6;
    x1 = strtod(s1 + 1, &ptr1);
    y1 = strtod(ptr1 + 1, &ptr2);
    x2 = strtod(s2 + 1, &ptr3);
    y2 = strtod(ptr3 + 1, &ptr4);
    x3 = strtod(s3 + 1, &ptr5);
    y3 = strtod(ptr5 + 1, &ptr6);

    return mod((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2);
}


int main()
{
    char s1[30], s2[30], s3[30];
    puts("------ Enter the cordinates in this formate:(x,y) ----\n");
    puts("1st point cordinates (x,y): ");
    gets(s1);
     puts("\n2nd point cordinates (x,y): ");
    gets(s2);
     puts("\n3rd point cordinates (x,y): ");
    gets(s3);
    printf("\n Area is =%lf\n", find_area(s1, s2, s3));
    
}