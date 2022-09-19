// Problem 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

/* Problem 1 main function
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
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Problem 2

double DegreeToRadian(double degree) // degree to radians convertion
{

    double O_d = 3.14159265 / 180;
    return (O_d * degree);
}

double input(char s[]) // converting the input string in acual input
{
    char *ptr;
    double ret;

    ret = strtod(s, &ptr);                                                                // separate the number part from the input string
    if (*(ptr + 1) == 'S' || *(ptr + 1) == 'W' || *(ptr + 1) == 's' || *(ptr + 1) == 'w') // for south and west direction we will considar the value as negative
    {
        ret = ret * -1;
    }

    return DegreeToRadian(ret);
}

double find_distance(char s1[], char s2[], char s3[], char s4[]) // actual function to fin distance in km
{
    double lat1, log1, lat2, log2;
    lat1 = input(s1);
    log1 = input(s2);
    lat2 = input(s3);
    log2 = input(s4);

    // based on Haversine Formula

    double dlong = log2 - log1;
    double dlat = lat2 - lat1;

    double ans = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlong / 2), 2);

    ans = 2 * asin(sqrt(ans));

    // Radius of Earth in
    // Kilometers, R = 6371
    // Use R = 3956 for miles
    long double R = 6371;

    // Calculate the result
    ans = ans * R;

    return ans;
}

/* Problem 2 main function
int main()
{
    char s1[30], s2[30], s3[30], s4[30];
    while (3)
    {
        printf("Input the Latitude value of source location: ");
        gets(s1);
        printf("Input the Longitude value of source location: ");
        gets(s2);
        printf("Input the Latitude value of destination location: ");
        gets(s3);
        printf("Input the Longitude value of destination  location: ");
        gets(s4);

        printf("\n Distance is=%lf KM\n", find_distance(s1, s2, s3, s4));
    }
}
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Problem 3
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

/* Problem 3 main function
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

} */