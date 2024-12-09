#include <stdio.h>
#include <stdlib.h>

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

void createVite() {
    char name[100];
    char vitecommand[256];
//    char cdcommand[256];

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

// Main Function

int main() {
    checkNodeVersion();
    checkNPMVersion();
    createVite();
    return 0;
}