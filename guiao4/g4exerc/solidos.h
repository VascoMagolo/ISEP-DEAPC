const int PI = 3.14159;
typedef struct cone {
    float raio;
    float altura;
} cone;

typedef struct cilindro {
    float raio;
    float altura;
} cilindro;

float volume_cone (cone c);
float volume_cilin (cilindro c); 