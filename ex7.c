#include <stdio.h>
#include <string.h>

void mypipe(char *input, char **arg1, char **arg2) {
    char *token;

    // Find the first occurrence of '|' in the input string
    token = strtok(input, "|");
    
    // Split the input string by '|'
    if (token != NULL) {
        *arg1 = strdup(token);
        token = strtok(NULL, "|");
        if (token != NULL) {
            *arg2 = strdup(token);
        }
    }
}

int main() {
    char input[1000];
    char *arg1[100];
    char *arg2[100];
    
    // Prompt user for input
    printf("Input: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character

    // Split input by pipe character
    mypipe(input, arg1, arg2);

    // Display the results
    printf("Argument 1: %s\n", *arg1);
    printf("Argument 2: %s\n", *arg2);

    return 0;
}
