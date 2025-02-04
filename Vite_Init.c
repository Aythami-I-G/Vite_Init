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
        printf("Node.Js is not installed. Download Node.Js from the main web page https://nodejs.org/en/download/prebuilt-installer. \n");
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
    // Change folder using chdir (cd command doesnt work)
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
        return;
}
    //Installing NPM packages
        
        //Axios 
        void installAxios(){
            // Install the Axios project using npm install
           printf("Installing 'Axios'. \n");
            int result = system("npm i axios");
            if (result == 0) {
                printf("'Axios' successfully installed.\n");
            } else {
                printf("An error ocurred, 'axios' installation has failed.\n");
            }
            return;
        }
        //React Router Dom
        void installRouter(){
            // Install the React Router Dom project using npm install 
            printf("Installing 'react-router-dom'. \n");
            int result = system("npm i react-router-dom");
            if (result == 0) {
                printf("'react-router-dom' successfully installed.\n");
            } else {
                printf("An error ocurred, 'react-router-dom' installation has failed.\n");
            }
            return;
        }
        //Express
                void installExpress(){
            // Install the Express project using npm install
            printf("Installing 'express'. \n");
            int result = system("npm i express");
            if (result == 0) {
                printf("'express' successfully installed.\n");
            } else {
                printf("An error ocurred, 'express' installation has failed.\n");
            }
            return;
        }
        //Morgan
                void installMorgan(){
            // Install the Morgan project using npm install     
            printf("Installing 'morgan'. \n");
            int result = system("npm i morgan");
            if (result == 0) {
                printf("'morgan' successfully installed.\n");
            } else {
                printf("An error ocurred, 'morgan' installation has failed.\n");
            }
            return;
        }
        //Json-server
                void installServer(){
            // Install the Json-server project using npm install    
            printf("Installing 'json-server'. \n");
            int result = system("npm i json-server");
            if (result == 0) {
                printf("'json-server' successfully installed.\n");
            } else {
                printf("An error ocurred, 'json-server' installation has failed.\n");
            }
            return;
        }
        //Jsonwebtoken
                void installWebToken(){
            // Install the Jsonwebtoken project using npm install    
            printf("Installing 'jsonwebtoken'. \n");
            int result = system("npm i jsonwebtoken");
            if (result == 0) {
                printf("'jsonwebtoken' successfully installed.\n");
            } else {
                printf("An error ocurred, 'jsonwebtoken' installation has failed.\n");
            }
            return;
        }
        //Sequelize
                void installSequelize(){
            // Install the Sequelize project using npm install    
            printf("Installing 'sequelize'. \n");
            int result = system("npm install --save sequelize");
            if (result == 0) {
                printf("'sequelize' successfully installed.\n");
            } else {
                printf("An error ocurred, 'sequelize' installation has failed.\n");
            }
            return;
        }
        //cors
                void installCors(){
            // Install the cors project using npm install    
            printf("Installing 'cors'. \n");
            int result = system("npm i cors");
            if (result == 0) {
                printf("'cors' successfully installed.\n");
            } else {
                printf("An error ocurred, 'cors' installation has failed.\n");
            }
            return;
        }
        //prop-types
                void installProptypes(){
            // Install the prop-types project using npm install    
            printf("Installing 'prop-types'. \n");
            int result = system("npm install --save prop-types");
            if (result == 0) {
                printf("'prop-types' successfully installed.\n");
            } else {
                printf("An error ocurred, 'prop-types' installation has failed.\n");
            }
            return;
        }
        //Prettier
                void installPrettier(){
            // Install the Prettier project using npm install    
            printf("Installing 'prettier'. \n");
            int result = system("npm i prettier");
            if (result == 0) {
                printf("'prettier' successfully installed.\n");
            } else {
                printf("An error ocurred, 'prettier' installation has failed.\n");
            }
            return;
        }

int main() {
    char name[256];
    checkNodeVersion();
    checkNPMVersion();
    createVite(name);
    installVite(name);
    installAxios(name);
    installRouter(name);
    installExpress(name);
    installMorgan(name);
    installServer(name);
    installWebToken(name);
    installSequelize(name);
    installCors(name);
    installProptypes(name);
    installPrettier(name);
    return 0;
}