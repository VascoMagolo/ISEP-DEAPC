#include <stdio.h>
#include "solidos.h"
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    if (argc != 2)
    {
        printf("Invalid number of arguments.\n");
        printf("Usage: %s <number of cones>\n", argv[0]);
        return 1;
    }
    cone *v=(cone *)calloc(atoi(argv[1]),sizeof(cone));
    
   for (int i = 0; i < atoi(argv[1]); i++)
    {
    new_cone(v+i);
    }

    printf("Cones created: %d\n", atoi(argv[1]));
    for (int i = 0; i < atoi(argv[1]); i++)
    {
        printf("Cone %d: radius %.2f, height %.2f ,volume %.2f\n", i+1, v[i].radius, v[i].height, volume_cone(v[i]));
    }
    free(v);
    return 0;
}   