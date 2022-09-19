/* Problem statemant 2 

Saurabh Sir stays in Bhopal,
Prateek Sir stays in Bangalore.
Using GPS:
Latitude and Longitude values of Bhopal as 23.259933 N, 77.412613 E.
Latitude and Longitude values of Bangalore as 12.9716 N, 77.5946 E.
Calculate distance between Saurabh Sir and Prateek Sir.
#include<stdio.h>
#include<conio.h>
void main(){
double distance;
/* We all know that, there is no function named find_distance exists, so you have to
include this function in your library.
distance = find_distance(parameter1, parameter2,.......);
printf("Distance Between Saurabh Sir and Prateek Sir: %lf\n",distance);
} */




#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double DegreeToRadian(double degree);
double input(char s[]);
double find_distance(char s1[], char s2[], char s3[], char s4[]);

double DegreeToRadian(double degree) // degree to radians convertion
{

    double O_d = 3.14159265 / 180;
    return (O_d * degree);
}

double input(char s[]) // converting the input string in acual input
{
    char *ptr;
    double ret;

    ret = strtod(s, &ptr);      // separate the number part from the input string
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
