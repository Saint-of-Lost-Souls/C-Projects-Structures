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
    double pos[MAX_DIMENSIONS];
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
    // Implicit initialisation //

    Guy terry =
        {
            "Terry Crews",
            true,
            3,
            {1, 2, 3}};

    // Explicit intialisation // Best practice

    Guy bill =
        {
            .name = "Bill Murray",
            .active = true,
            .dimensions = 3,
            .pos = {3, 2, 1},
        };

    Motorcycle moto =
        {
            .model = "Honda",
            .speed = 300,
            .owner = {
                .name = "Andrea",
                .dimensions = 3,
                .active = true,
                .pos = {1, 2, 3}},
        };
    // Copy a whole structure with =
    Guy anotherGuy = {.name = "noone", .active = false};
    anotherGuy = bill;

    printf("anotherGuy.name = %s\n", anotherGuy.name);

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

    printf("And the %s motorcycle is running at %.1f km/h and is driven by %s\n", moto.model, moto.speed, moto.owner.name);

    moto = (Motorcycle){.model = "Ducati", .speed = 200}; // Discarded all info that isn't listed
    printf("And the %s motorcycle is running at %.1f km/h and is driven by %s", moto.model, moto.speed, moto.owner.name);

    printf("\n\n");
    return EXIT_SUCCESS;
}
