#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <string.h>

// Function to check if a directory exists
int directory_exists(const char *path) {
    struct stat st;
    return (stat(path, &st) == 0 && S_ISDIR(st.st_mode));
}

// Function to generate random numbers and write them to a file
void generate_random_numbers(const char *file_path, int start, int end, int size) {
    FILE *file = fopen(file_path, "w");
    if (!file) {
        perror("Error opening file");
        return;
    }

    // Seed the random number generator
    srand(time(NULL));

    // Generate and write random numbers to the file
    for (int i = 0; i < size; i++) {
        int random_number = (rand() % (end - start + 1)) + start;
        fprintf(file, "%d\n", random_number);
    }

    fclose(file);
    printf("Random numbers successfully written to %s\n", file_path);
}

int main() {
    char file_path[256] = "./inputs/input72k.txt";
    int start = 1;
    int end = 65536;
    int size;

    // Prompt user for the number of random numbers to generate
    printf("Enter how many random numbers to generate: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        fprintf(stderr, "Invalid size entered.\n");
        return 1;
    }

    // Ensure the directory exists
    char directory[256];
    strncpy(directory, file_path, strrchr(file_path, '/') - file_path);
    directory[strrchr(file_path, '/') - file_path] = '\0';

    if (!directory_exists(directory)) {
        fprintf(stderr, "The directory %s does not exist. Please create the directory and try again.\n", directory);
        return 1;
    }

    // Generate and save random numbers
    generate_random_numbers(file_path, start, end, size);

    return 0;
}
