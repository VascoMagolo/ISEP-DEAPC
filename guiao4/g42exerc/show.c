#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    
    if (argc == 3) {
        FILE *file=fopen(argv[1], "r");
    }
    if (argc == 2) {
        FILE *file=fopen(argv[1], "r");
    }
    else {
        printf("Invalid number of arguments.\n");
        printf("Usage: %s file_name N\n", argv[0]);
        return 1;
    }
    return 0;
}