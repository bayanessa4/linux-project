#include <stdio.h>
#include <stdlib.h>

void echo(char **args) {
    if (args[1] == NULL || args[2] == NULL) {
        printf("Usage: <command> <<file_path>> <<string_to_append>>\n");
        return;
    }

    FILE *file = fopen(args[1], "a");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }

    fprintf(file, "%s\n", args[2]);

    fclose(file);

    printf("String appended to file successfully.\n");
}

int main(int argc, char *argv[]) {
    echo(argv);

    return 0;
}
