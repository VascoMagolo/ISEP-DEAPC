#ifndef SOLIDOS_H
#define SOLIDOS_H
#define PI 3.14159
typedef struct {
    float radius;
    float height;
} cone;

typedef struct {
    float radius;
    float height;
} cylinder;

typedef struct {
    float radius;
} sphere;

typedef struct {
    float lenght;
    float width;
    float height;
} parallelepiped;

float volume_cone (cone c);
float volume_cilin (cylinder c); 
float volume_sphere (sphere s);
float volume_parallelepiped (parallelepiped p);
cone new_cone(int n);

#endif
