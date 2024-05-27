#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h> 
#include <conio.h>  

void cd(char **args) {
    if (args[1] == NULL) {
        printf("Expected argument to \"cd\"\n");
        return;
    }

    for (int i = 0; args[i] != NULL; i++) {
        printf("args[%d] = %s\n", i, args[i]);
    }

    int length = 0;
    for (int i = 1; args[i] != NULL; i++) {
        length += strlen(args[i]) + 1; // Add 1 for space or null terminator
    }

    char *path = (char *)malloc(length * sizeof(char));
    if (path == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    strcpy(path, args[1]);

    for (int i = 2; args[i] != NULL; i++) {
        strcat(path, " "); // Add space separator
        strcat(path, args[i]); // Concatenate the argument
    }

    printf("Changing directory to: %s\n", path);

    if (chdir(path) != 0) {
        perror("chdir");
    }
    free(path);
}

int main(int argc, char **argv) {
    cd(argv);
    printf("Press any key to exit...\n");
    _getch(); 

    return 0;
}
