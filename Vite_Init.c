#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#ifdef _WIN32
#include <io.h>
#define access _access
#else
#include <unistd.h>
#endif

//Functions
void checkNodeVersion() {
    char command[256];
    FILE *fp = popen("node -v", "r"); // Run the command and open a pipe to read the output
    if (fp == NULL) {
        return;
    }

    // Read the output of the command
    if (fgets(command, sizeof(command), fp) != NULL) {
        printf("Node.js version: %s", command);
    } else {
        printf("Node.Js is not installed. Download Node.Js from the main web page https://nodejs.org/en/download/prebuilt-installer.\n");
    }

    pclose(fp);
}

void checkNPMVersion() {
    char command[256];
    FILE *fp = popen("npm -v", "r");
    if (fp == NULL) {
        return;
    }

    if (fgets(command, sizeof(command), fp) != NULL) {
        printf("npm version: %s", command);
    }  else {
        printf("npm is not installed \n");
    }

    pclose(fp);
}

void createVite(char *name) {
    char vitecommand[256];

    // Get the project name from the user
    printf("Enter the project name: ");
    scanf("%99s", name);
    // Construct the cmdlet command
    snprintf(vitecommand, sizeof(vitecommand), "npm create vite@latest %s -- --template react", name);

    // Execute the cmdlet command using popen
    FILE *fp = popen(vitecommand, "r");
    if (fp == NULL) {
        perror("Failed to run command");
        return;
    }
   
    // Display the output of the command
    while (fgets(vitecommand, sizeof(vitecommand), fp) != NULL) {
        printf("%s", vitecommand); // Print the command output
    }

    // Close the file pointer and check the result
    int status = pclose(fp);
    if (status == 0) {
        printf("The React Vite project '%s' has been successfully created.\n", name);
    } else {
        printf("An error occurred while creating the React Vite project '%s'.\n", name);
    }
        return;
}  

void installVite(const char *name) {
    // Chenge folder using chdir (cd command doesnt work)
    if (chdir(name) == 0) {
        printf("Changed directory to: %s\n", name);

        // Install the React project using npm install
        printf("Running 'npm install'...\n");
        int result = system("npm install");

        if (result == 0) {
            printf("'npm install' completed successfully.\n");
        } else {
            printf("An error occurred while running 'npm install'.\n");
        }
    } else {
        perror("Failed to change directory");
    }
}

int main() {
    char name[100];
    checkNodeVersion();
    checkNPMVersion();
    createVite(name);
    installVite(name);
    return 0;
}