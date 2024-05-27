#include <stdio.h>

void read(char **args) {
    if (args[1] == NULL) {
        printf("Usage: <command> <<file_path>>\n");
        return;
    }

    FILE *file = fopen(args[1], "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    read(argv);

    return 0;
}
