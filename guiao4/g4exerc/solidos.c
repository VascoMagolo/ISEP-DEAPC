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

cone new_cone(int n){
    cone cone;
    printf("Enter the height of the cone number %d: ", n);
    scanf("%f", &cone.height);
    printf("Enter the radius of the cone number %d: ", n);
    scanf("%f", &cone.radius);
    return cone;
}