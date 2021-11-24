#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DIMENSIONS 3

typedef struct Guy
{
    char *name;
    bool active;
    int dimensions;
    double pos[MAX_DIMENSIONS]; // cannot use imcomplete array, but see flexible array member/* data */
    struct Guy *friend;
} Guy;


int main()
{
    system("cls");

    Guy terry = {
        .name = "Terry Crews",
        .pos = {3, 2, 1},
        .dimensions = 3,
        .active = true,
    };

    Guy *firstGuy = &terry;

    // Accessing the struct directly
    printf("Guy's name: %s\n", terry.name);
    // Accessing the struct through pointers using the indirection operator *
    printf("Guy's name: %s\n", (*firstGuy).name);
    // Accessing the struct through pointers using the arrow operator
    printf("Guy's name: %s\n", firstGuy->name);
    printf("Guy's position: %.1f, %.1f, %.1f\n", firstGuy->pos[0],
                                                 firstGuy->pos[1],
                                                 firstGuy->pos[2]);
    
    // Walking a single linked list
    firstGuy->friend = malloc(sizeof(Guy)); // Allocating a portion of memory from the heap that's big enough to store a struct of type guy
    firstGuy->friend->name = "Bill Murray";
    firstGuy->friend->active = false;

    //Go through the list... manually... (not best practice)
    firstGuy->friend->friend = malloc(sizeof(Guy)); // Allocating a portion of memory from the heap that's big enough to store a struct of type guy
    firstGuy->friend->friend->name = "Bruce Campbell";
    firstGuy->friend->friend->active = true;

    // Allocating an array of guys
    int num = 10;
    Guy *manyGuys = malloc(num * sizeof(Guy)); // Allocated 10 memory blocks the size of Guy

    manyGuys[0].name = "Oni";
    manyGuys[0].friend = &terry; // Oni's friends are also Bill's friends

    // Accessing the 2nd element of manyGuys using pointers
    (manyGuys + 1)->name = "Pearl";
    printf("manyGuys[1].name = %s\n", manyGuys[1].name);
    





    printf("\n\n");
    return EXIT_SUCCESS;
}
