/* Problem statement 1
Suppose there are two roads,
Road 1: ABC Road, represented by equation 5x + y - 3 = 0
Road 2: XYZ Road, represented by equation 2x + 3y + 1 = 0
These two roads meet each other at a chowk, called 123 Chowk.
Determine at which angle , these two roads meet each other at chowk.
What you have to do :
Create a Program which determines angle at which these roads meet at 123 Chowk.
#include<stdio.h>
#include<conio.h>
void main(){
double angle_at_chowk;
/* We all know that, there is no function named find_angle exists, so you have to create a
library for that. 
angle_at_chowk = find_angle(parameter1, parameter2,......);
printf("Angle at which these roads meets at 123 Chowk: %lf\n",angle_at_chowk); */





#include <stdio.h>
#include <math.h>
void swap(double *a, double *b);
double slop(char s[]);
double find_angle(char s1[], char s2[]);

void swap(double *a, double *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
double slop(char s[]) // to calculate the slop of a given equation Y=mX+c
{
    int sine = 1, flagx = 0, flagy = 0, i = 0;
    // sine is to check the value is positive / negative
    double xc = 0, yc = 0;

    // xc to store the coficent value of x
    // yc to store the coficent value of y
    for (i = 0; s[i] != '\0'; i++) // traverseing the equation aX + bY + c = 0
    {
        if (s[i] == '-') // if - arrive sine=-1
        {
            sine = -1;
        }
        else if (flagx == 0) // flagx = 0 represent that calculating the coficient value of x is not complete yet
        {
            if (s[i] >= '0' && s[i] <= '9') // calculating the value of coficient of x
            {
                int temp;
                temp = s[i] - '0';
                xc = xc * 10 + temp;
            }
            else if (s[i] == '+') // if + arrive sine=1
            {

                sine = 1;
            }
            else // s[i] is not a number means calculating the value of coficient x is complete now
            {
                if (xc == 0) // the coficient value of x is must be >=1 (Y=mX+c)
                {
                    xc = 1;
                }

                if (sine < 0) // if sine < 0 that means the coficient value of x is negative
                {
                    xc *= -1;
                }
                flagx = 1; // flagx = 1 represent the calcualtion of coficient value of x is completed
            }
        }
        else // when flagx=1
        {
            if (s[i] >= '0' && s[i] <= '9') // calculating the value of coficient of y
            {
                int temp;
                temp = s[i] - '0';
                yc = yc * 10 + temp;
            }
            else if (s[i] == '+') // if + arrive we have nothing to do
            {
                // do nothing
                sine = 1;
            }
            else // s[i] is not a number means calculating the value of coficient y is complete now
            {
                if (yc == 0) // the coficient value of x is must be >=1 (Y=mX+c)
                {
                    yc = 1;
                }
                if (sine < 0) // if sine < 0 that means the coficient value of y is negative
                {
                    yc *= -1;
                }
                flagy = 1; // flagy = 1 represent the calcualtion of coficient value of y is completed
            }
        }
        if (flagy == 1 && flagx == 1) // when both Xc and Yc calculated we can terminate the loop
        {
            break;
        }
    }

    for (int i = 0; s[i] != '\0'; i++) // either the input format is (aX + bY + c=0) or (bY + aX +c=0) we can compute correct ans
    {
        if (s[i] == 'y')
        {
            swap(&xc, &yc); 
            break;
        }
        else if (s[i] == 'x')
        {
            break;
        }
    }

    return -1 * (xc / yc); // maintaining the sine as we consider the as Xc*X+Yc*Y+c=0
}

double find_angle(char s1[], char s2[]) // Actualfunction
{
    double M1, M2;
    M1 = slop(s1);
    M2 = slop(s2);
    double angle = ((M2 - M1) / (1 + M1 * M2));
    if (angle < 0)
    {
        angle = angle * -1;
    }

    // Calculate tan inverse of the angle

    double t = atan(angle);

    // radian to degree
    double ans = (t * 180) / 3.14159265;

    // return the ans
    return ans;
}
int main()
{
    char s1[100], s2[100];

    while (3)
    {
        puts("Please input the 1st eq (a*X + b*Y + C= 0) : ");
        gets(s1);
        puts("Please input the 2nd eq (a*X + b*Y + C= 0) : ");
        gets(s2);
        puts("\nAngle (degree): ");
        printf("%f\n", find_angle(s1, s2));
    }
}