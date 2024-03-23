#include <stdio.h>
#include "solidos.h"
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
    cone cone;
    cylinder cylinder;
    sphere sphere;
    parallelepiped parallelepiped;
    if (strcmp(argv[1], "-cone") == 0)
    {
        if (argc != 4)
        {
            printf("Invalid number of arguments.\n");
            return 1;
        }
        cone.height = atof(argv[2]);
        cone.radius = atof(argv[3]);
        printf("Volume of cone: %.2f\n", volume_cone(cone));
    }
    else if (strcmp(argv[1], "-cylinder") == 0)
    {
        if (argc != 4)
        {
            printf("Invalid number of arguments.\n");
            return 1;
        }
        cylinder.height = atof(argv[2]);
        cylinder.radius = atof(argv[3]);
        printf("Volume of cylinder: %.2f\n", volume_cilin(cylinder));
    }
    else if (strcmp(argv[1], "-sphere") == 0)
    {
        if (argc != 3)
        {
            printf("Invalid number of arguments.\n");
            return 1;
        }
        sphere.radius = atof(argv[2]);
        printf("Volume of sphere: %.2f\n", volume_sphere(sphere));
    }
    else if (strcmp(argv[1], "-parallelepiped") == 0)
    {
        if (argc != 5)
        {
            printf("Invalid number of arguments.\n");
            return 1;
        }
        parallelepiped.lenght = atof(argv[2]);
        parallelepiped.width = atof(argv[3]);
        parallelepiped.height = atof(argv[4]);
        printf("Volume of parallelepiped: %.2f\n", volume_parallelepiped(parallelepiped));
    }
    else if (strcmp(argv[1], "-help") == 0)
    {
        if (argc != 2)
        {
            printf("Invalid number of arguments.\n");
            return 1;
        }
        printf("Usage command:  ./volume -solid_name <height_value> <radius_value> <lenght_value> <width_value>\n");
        printf("Available solides: cone(2), cylinder(2), sphere(1), parallelepiped(3)\n");
        printf("Note that the amount of values varies on the solid that you want. \n");
        return 0;
    }
    else
    {
        printf("Command Error.\n");
        printf("Use -help for more information.\n");
        return 1;
    }

    return 0;
}