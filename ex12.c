#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void wordCount(char **args) {
    if (args[1] == NULL || args[2] == NULL) {
        printf("Usage: <command> [-l | -w] <file_path>\n");
        return;
    }

    FILE *file = fopen(args[2], "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }

    int lines = 0;
    int words = 0;
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        lines++;

        char *token = strtok(buffer, " \t\n");
        while (token != NULL) {
            words++;
            token = strtok(NULL, " \t\n");
        }
    }

    fclose(file);

    if (strcmp(args[1], "-l") == 0) {
        printf("Number of lines: %d\n", lines);
    } else if (strcmp(args[1], "-w") == 0) {
        printf("Number of words: %d\n", words);
    } else {
        printf("Error: Invalid option. Please use -l or -w.\n");
    }
}

int main(int argc, char *argv[]) {
    wordCount(argv);

    return 0;
}
