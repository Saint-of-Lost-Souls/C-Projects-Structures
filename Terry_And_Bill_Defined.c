#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_DIMENSIONS 3

// Struct declaration //

struct GuyStruct
{
    char *name;
    bool active;
    int dimensions;
    double pos[MAX_DIMENSIONS]; // cannot use imcomplete array, but see **FLEXIBLE ARRAY MEMBER**
};

typedef struct // Anonymous structure
{
    char *name;
    bool active;
    int dimensions;
    double pos[MAX_DIMENSIONS];
} GuyAnonymous;

typedef struct Guy // Best practice
{
    char *name;
    bool active;
    int dimensions;
    double pos[MAX_DIMENSIONS];
} Guy;

typedef struct Motorcycle
{
    char *model;
    double speed;
    Guy owner;
} Motorcycle;


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
    Guy terry, bill; // terry and bill will now store all of the variables declared in struct
    Motorcycle moto;

    moto.model = "Honda";
    moto.speed = 300;
    moto.owner.name = "Andrea";

    terry.name = "Terry Crews";
    terry.active = true;
    terry.dimensions = 3;
    terry.pos[0] = 1;
    terry.pos[1] = 2;
    terry.pos[2] = 3;

    bill.name = "Bill Murray";
    bill.active = true;
    bill.dimensions = 3;
    bill.pos[0] = 3;
    bill.pos[1] = 2;
    bill.pos[2] = 1;

    if (!terry.active || !bill.active)
    {
        printf("%s isn't active!\n", !terry.active ? terry.name : bill.name);
        return EXIT_FAILURE;
    }

    if (terry.dimensions != bill.dimensions)
    {
        printf("%s and %s are in different dimensions!\n", terry.name, bill.name);
        return EXIT_FAILURE;
    }

    printf("The distance between %s and %s is: %.1f\n",
           terry.name, bill.name, calcDistance(terry.dimensions, terry.pos, bill.pos));

    printf("\n\n");
    return EXIT_SUCCESS;
}
