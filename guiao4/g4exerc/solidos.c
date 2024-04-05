#include <stdio.h>
#include "solidos.h"
#include <math.h>

float volume_cone(cone c) {
    return ((1.0/3.0) * (c.height) * (PI) * (pow(c.radius, 2)));   
}
float volume_cilin(cylinder c) {
    return ((c.height) * (PI) * (pow(c.radius, 2)));
}

float volume_sphere(sphere e) {
    return ((4.0/3.0) * (PI) * (pow(e.radius, 3)));
}

float volume_parallelepiped(parallelepiped s) {
    return (s.lenght * s.width * s.height);
}

void new_cone(cone *c) {
    printf("Insert the radius of the cone: ");
    scanf("%f", &c->radius);
    printf("Insert the height of the cone: ");
    scanf("%f", &c->height);
}