#include <stdio.h>
#include <stdlib.h>

void moveFile(char *sourcePath, char *destinationPath) {
    FILE *sourceFile, *destinationFile;
    char buffer[1024];
    size_t bytes;

    // Open source file for reading
    sourceFile = fopen(sourcePath, "rb");
    if (sourceFile == NULL) {
        printf("Error: Unable to open source file.\n");
        return;
    }

    // Open destination file for writing
    destinationFile = fopen(destinationPath, "wb");
    if (destinationFile == NULL) {
        printf("Error: Unable to open destination file.\n");
        fclose(sourceFile);
        return;
    }

    // Read from source file and write to destination file
    while ((bytes = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0) {
        fwrite(buffer, 1, bytes, destinationFile);
    }

    // Close files
    fclose(sourceFile);
    fclose(destinationFile);

    printf("File moved successfully.\n");
}

int main(int argc, char *argv[]) {
    // Check if source path and destination path are provided
    if (argc != 3) {
        printf("Usage: %s <source_path> <destination_path>\n", argv[0]);
        return 1;
    }

    // Call moveFile function with source path and destination path arguments
    moveFile(argv[1], argv[2]);

    return 0;
}


//./move source_file.txt destination_file.txt
