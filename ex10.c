#include <stdio.h>
#include <stdlib.h>

void echorite(char **args) {
    if (args[1] == NULL || args[2] == NULL) {
        printf("Usage: <command> <<file_path>> <<new_content>>\n");
        return;
    }

    FILE *file = fopen(args[1], "w");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }

    fprintf(file, "%s", args[2]);

    fclose(file);

    printf("File content overwritten successfully.\n");
}

int main(int argc, char *argv[]) {
    echorite(argv);

    return 0;
}
