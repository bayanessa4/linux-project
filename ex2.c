#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** splitNullTerminated(char* str) {
    int count = 0;
    char** tokens = NULL;
    char* token = str;

    // Counting the number of tokens
    while (*token != '\0') {
        count++;
        while (*token != '\0') {
            token++; // Move to the next character
        }
        token++; // Move past the null character
    }

    // Allocating memory for array of strings
    tokens = (char**)malloc((count + 1) * sizeof(char*));
    if (tokens == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Splitting the string into tokens
    token = str;
    for (int i = 0; i < count; i++) {
        tokens[i] = (char*)malloc(strlen(token) + 2); // +2 for the token and \0
        if (tokens[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        strcpy(tokens[i], token);
        strcat(tokens[i], "\\0"); // Append "\0" to the token
        while (*token != '\0') {
            token++;
        }
        token++; // Move past the null character
    }

    // Setting the last element of array to NULL
    tokens[count] = NULL;

    return tokens;
}

int main() {
    char str[] = "cd\0OneDrive\0-\0Ariel\0University\0";
    char** tokens = splitNullTerminated(str);

    // Printing the array of strings
    printf("Tokens = [");
    for (int i = 0; tokens[i] != NULL; i++) {
        printf("%s, ", tokens[i]);
        free(tokens[i]); // Freeing memory allocated for each token
    }
    printf("NULL]\n");

    // Freeing memory allocated for array of strings
    free(tokens);

    return 0;
}
