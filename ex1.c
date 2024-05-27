#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

#ifdef _WIN32
    #include <winsock2.h>
    #include <windows.h>
    #include <direct.h>
    #define getcwd _getcwd
    #pragma comment(lib, "ws2_32.lib")

    void initialize_winsock() {
        WSADATA wsaData;
        int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
        if (result != 0) {
            fprintf(stderr, "WSAStartup failed with error: %d\n", result);
            exit(EXIT_FAILURE);
        }
    }

    void cleanup_winsock() {
        WSACleanup();
    }
#endif

char* getLocation() {
    char* username;
    char hostname[1024];
    char* cwd = (char*)malloc(1024);

    #ifdef _WIN32
        if (gethostname(hostname, sizeof(hostname)) == SOCKET_ERROR) {
            fprintf(stderr, "gethostname failed with error: %d\n", WSAGetLastError());
            free(cwd);
            return NULL;
        }
    #endif
    
    if (getcwd(cwd, 1024) != NULL) {
        printf("Current working dir: %s\n\n", cwd);
    } else {
        perror("getcwd");
        free(cwd);
        return NULL;
    }

    printf("%s\n", hostname);
    printf("%s\n", cwd);
    
    return cwd;
}

int main() {
    #ifdef _WIN32
        initialize_winsock();
    #endif

    char* path = getLocation();
    if (path != NULL) {
        printf("\nYou are in: %s\n\n", path);
        free(path); // Free the allocated memory
    }

    #ifdef _WIN32
        cleanup_winsock();
    #endif
    return 0;
}
