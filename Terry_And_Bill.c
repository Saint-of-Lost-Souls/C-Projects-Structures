#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

double calcDistance(int dimensions, double a[dimensions], double b[dimensions])
{
    double square_distance = 0;
    for (int i = 0; i < dimensions; i++)
    {
        square_distance += pow(a[i] - b[i], 2);
    }
    return sqrt(square_distance);
    
}
int main()
{

    // Let's calculate the distance between these two complete strangers //

    char terry_name[] = "Terry Crews";
    bool terry_active = true; // Is Terry active?
    int terry_dimensions = 3; // How many dimensions does Terry occupy?
    double terry_pos[] = {1, 2, 3};

    char bill_name[] = "Bill Murray";
    bool bill_active = true;
    int bill_dimensions = 3;
    double bill_pos[] = {3, 2, 1};

    if (!terry_active || !bill_active)
    {
        printf("%s isn't active!\n", !terry_active ? terry_name : bill_name);
        return EXIT_FAILURE;
    }
    
    if (terry_dimensions != bill_dimensions)
    {
        printf("%s and %s are in different dimensions!\n", terry_name, bill_name);
        return EXIT_FAILURE;
    }

    printf("The distance between %s and %s is: %.1f\n", 
            terry_name, bill_name, calcDistance(terry_dimensions, terry_pos, bill_pos));

    


    printf("\n\n");
    return EXIT_SUCCESS;
}
