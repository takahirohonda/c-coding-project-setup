#include <stdio.h>
#include <stdlib.h>

//  dynamic resizing approach is better than reading the file twice
// We can read file twice to allocate memory first when
// (1) If you need absolute memory efficiency (avoiding realloc() overhead).
// (2) If the file is small and you want exact malloc() once.
int main() {
    FILE *file = fopen("data.txt", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int capacity = 2;  // Initial capacity
    int n = 0;

    // Allocate initial space for array of lines
    char **lines = malloc(capacity * sizeof(char *));
    if (!lines) {
        perror("Memory allocation failed");
        fclose(file);
        return 1;
    }

    // Read file line-by-line, reallocating if needed
    while ((read = getline(&line, &len, file)) != -1) {
        // Trim newline if present
        if (line[read - 1] == '\n') {
            line[read - 1] = '\0';  // Replace newline with null terminator
        }

        if (n >= capacity) {  // Resize array if needed
            capacity *= 2;
            lines = realloc(lines, capacity * sizeof(char *));
            if (!lines) {
                perror("Memory reallocation failed");
                fclose(file);
                return 1;
            }
        }

        lines[n] = malloc(read + 1);  // Allocate exact memory for the line
        strcpy(lines[n], line);
        n++;
    }

    free(line);  // Free getline buffer
    fclose(file);

    // Print stored lines
    printf("File Contents (with newlines removed):\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", lines[i]);  // Print each line without the trailing newline
        free(lines[i]);  // Free each stored line
    }

    free(lines);  // Free the array

    return 0;
}