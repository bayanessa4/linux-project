#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void logOut(char *str) {
    // Removing leading and trailing whitespace
    int start = 0;
    int end = strlen(str) - 1;
    while (str[start] == ' ') {
        start++;
    }
    while (str[end] == ' ' && end >= start) {
        end--;
    }

    // Null-terminate the trimmed string
    str[end + 1] = '\0';

    // Check if the command contains the word "exit"
    if (strstr(str + start, "exit") != NULL) {
        printf("Exiting the terminal...\n");
        exit(EXIT_SUCCESS); // Exit the program successfully
    } else {
        printf("Invalid command: %s\n", str);
    }
}

int main() {
    char input1[] = "exit";
    char input2[] = "  exit  ";
    char input3[] = "exit now";
    char input4[] = "exit gracefully";
    char input5[] = "I want to exit";
    char input6[] = "quit";
    
    logOut(input1);
    logOut(input2);
    logOut(input3);
    logOut(input4);
    logOut(input5);
    logOut(input6);

    return 0;
}
