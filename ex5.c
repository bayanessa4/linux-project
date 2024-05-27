#include <stdio.h>
#include <stdlib.h>

void copyFile(char *source, char *destination) {
    FILE *sourceFile, *destinationFile;
    char ch;

    sourceFile = fopen(source, "r");
    if (sourceFile == NULL) {
        printf("Unable to open source file\n");
        return;
    }

    destinationFile = fopen(destination, "w");
    if (destinationFile == NULL) {
        fclose(sourceFile);
        printf("Unable to create destination file\n");
        return;
    }

    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destinationFile);
    }

    printf("File copied successfully\n");

    fclose(sourceFile);
    fclose(destinationFile);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_file_path> <destination_file_path>\n", argv[0]); 
        return 1;
    }

    copyFile(argv[1], argv[2]);

    return 0;
}


// how to run ex5.exe "D:\software engineer\C Lang\bahjat.txt" "D:\software engineer\C Lang\lvsa4e"
