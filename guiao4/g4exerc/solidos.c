#include <stdio.h>
#include "solidos.h"

float volume_cone(cone c) {
    return (1.0/3.0) * c.altura * PI * c.raio * c.raio;
}