#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments are provided
    if (argc < 2 || argc > 3) {
        printf("Invalid number of arguments.\n");
        printf("Usage: %s file_name [N]\n", argv[0]);
        return 1;
    }

    // Openning the file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        perror(", Error opening file");
        return 1;
    }

    // Count the number of lines in the file, not necessary but useful
    int count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }
    printf("Number of lines: %d\n", count);

    // If N is provided, use it, otherwise use 5
    int N = (argc == 3) ? atoi(argv[2]) : 5;

    // Rewind the file, basically it resets the pointer of the file
    rewind(file);

    // Print N lines at a time
    char line[100];
    for (int i = 0; i < count; i++) {
        for (int x = 0; x < N; x++) {
            if (fgets(line, 100, file) == NULL) {
                fprintf(stderr, "Error reading file\n");
                perror(",Error reading file");
                fclose(file);
                return 1;
            }
            printf("%s", line);
        }
        while (getchar() != '\n');
    }

    // Close the file
    fclose(file);

    return 0;
}
