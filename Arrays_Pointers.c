#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_DIMENSIONS 3

typedef struct GuyPoint
{
    char *name;
    char *job;
    bool active;
    int dimensions;
    double pos[MAX_DIMENSIONS]; 
    struct Guy *friend;
} GuyPoint;

typedef struct GuyArray
{
    char *name;
    char job[64];
    bool active;
    int dimensions;
    double pos[MAX_DIMENSIONS]; 
    struct Guy *friend;
} GuyArray;

int main()
{
    system("cls");
    printf("sizeof(GuyPoint): %lld\n", sizeof(GuyPoint));
    printf("sizeof(GuyArray): %lld\n", sizeof(GuyArray));

    GuyPoint terryPoint = {
        .name = "Terry Crews",
        .job = "I lift things",        
    };

    terryPoint.job = "Terry loves yoghurt";

    GuyArray terryArray = {
        .name = "Terry Crews",
        .job = "I lift things", 
    };

    // terryArray.job = "Terry loves yoghurt"; WRONG!
    strcpy(terryArray.job, "Terry loves yoghurt", sizeof(terryArray.job) - 1); // remember the NULL character




    printf("\n\n");
    return EXIT_SUCCESS;
}
