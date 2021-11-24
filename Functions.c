#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_DIMENSIONS 3

typedef struct Guy
{
    char *name;
    bool active;
    int dimensions;
    double pos[MAX_DIMENSIONS]; // cannot use imcomplete array, but see flexible array member/* data */
    struct Guy *friend;
} Guy;


Guy createTerry()
{
    return(Guy) {
        .name = "Terry Crews",
        .pos = {1, 2, 3},
        .dimensions = 3,
        .active = true,
    };    
}
Guy *allocBruce()
{
    Guy *bruce = malloc(sizeof(Guy));
    if (!bruce)
    {
        return NULL;
    }
    // Settings
    bruce->name = "Bruce Campbell";
    bruce->active = true;
    bruce->dimensions = 3;
    // bruce->pos[0] = 1;
    // bruce->pos[1] = 2;
    // bruce->pos[2] = 3;
    double pos[] = {3, 2, 1};
    memcpy(bruce->pos, pos, sizeof(pos));
    bruce->friend = NULL;
    return bruce;    
}

void deactivateGuy(Guy g) // Deactivate struct
{
    g.active = false;
}

void deactivateGuyPtr(Guy *pg) // Deactivate pointer to struct
{
    pg->active = false;
}
int main()
{
    system("cls");

    Guy terry = createTerry();
    terry.friend = allocBruce();

    deactivateGuy(terry);
    deactivateGuyPtr(&terry);
    

    printf("\n\n");
    return EXIT_SUCCESS;
}
