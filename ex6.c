#include <stdio.h>
#include <stdlib.h>

void deleteFile(char *path) {
    int status;

    status = remove(path);

    if (status == 0) {
        printf("File deleted successfully.\n");
    } else {
        printf("Unable to delete the file.\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    deleteFile(argv[1]);

    return 0;
}
