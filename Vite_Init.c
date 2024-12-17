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
        void installAxios(const char *name) {
            if (chdir(name) == 0) {
            printf("Changed directory to: %s\n", name);

            // Install the React project using npm install
            printf("Installing 'Axios'. \n");
            int result = system("npm i axios");

            if (result == 0) {
                printf("'Axios' successfully installed.\n");
            } else {
                printf("An error ocurred, 'axios' installation has failed.\n");
            }
        } else {
            perror("Failed to change directory");
            }
            return;
        }
        //React Router Dom
                void installRouter(const char *name) {
            if (chdir(name) == 0) {
                printf("DO you want to install 'React-router-dom@6'");
                int result = system("npm install react-router-dom@6");

                if (result == 0) {
                    printf("Installing react-router-dom@6\n");
                } else {
                    printf("An error ocurred, 'React Router Dom' installation has failed.\n");
                }
            } else {
                perror("Failed to change directory");
            }
                return;
        }
        //Express
                void installExpress(const char *name) {
            if (chdir(name) == 0) {
                printf("DO you want to install 'express'");
                int result = system("npm install express");

                if (result == 0) {
                    printf("Installing express\n");
                } else {
                    printf("An error ocurred, 'express' installation has failed.\n");
                }
            } else {
                perror("Failed to change directory");

            }
                return;
        }
        //Morgan
                void installMorgan(const char *name) {
            if (chdir(name) == 0) {
                printf("DO you want to install 'morgan'");
                int result = system("npm install morgan");

                if (result == 0) {
                    printf("Installing morgan\n");
                } else {
                    printf("An error ocurred, 'morgan' installation has failed.\n");
                }
            } else {
                perror("Failed to change directory");

            }
                return;
        }
        //Json-server
                        void installServer(const char *name) {
            if (chdir(name) == 0) {
                printf("DO you want to install 'json-server'");
                int result = system("npm install json-server");

                if (result == 0) {
                    printf("Installing json-server\n");
                } else {
                    printf("An error ocurred, 'Json-server' installation has failed.\n");
                }
            } else {
                perror("Failed to change directory");

            }
                return;
        }
        //Jsonwebtoken
                void installWebToken(const char *name) {
            if (chdir(name) == 0) {
                printf("DO you want to install 'jsonwebtoken'");
                int result = system("npm install jsonwebtoken");

                if (result == 0) {
                    printf("Installing jsonwebtoken\n");
                } else {
                    printf("An error ocurred, 'Jsonwebtoken' installation has failed.\n");
                }
            } else {
                perror("Failed to change directory");

            }
                return;
        }
        //Sequelize
                void installSequelize(const char *name) {
            if (chdir(name) == 0) {
                printf("DO you want to install 'sequelize'");
                int result = system("npm install sequelize");

                if (result == 0) {
                    printf("Installing sequlize\n");
                } else {
                    printf("An error ocurred, 'sequelize' installation has failed.\n");
                }
            } else {
                perror("Failed to change directory");

            }
                return;
        }
        //cors
                void installCors(const char *name) {
            if (chdir(name) == 0) {
                printf("DO you want to install 'cors'");
                int result = system("npm install cors");

                if (result == 0) {
                    printf("Installing cors\n");
                } else {
                    printf("An error ocurred, 'cors' installation has failed.\n");
                }
            } else {
                perror("Failed to change directory");

            }
                return;
        }
        //Proptipes
                void installProptipes(const char *name) {
            if (chdir(name) == 0) {
                printf("DO you want to install 'proptipes'");
                int result = system("npm install proptipes");

                if (result == 0) {
                    printf("Installing proptipes depencies\n");
                } else {
                    printf("An error ocurred, 'proptipes' installation has failed.\n");
                }
            } else {
                perror("Failed to change directory");

            }
                return;
        }
        //Perttier
                        void installPrettier(const char *name) {
            if (chdir(name) == 0) {
                printf("DO you want to install 'prettier'");
                int result = system("npm install prettier");

                if (result == 0) {
                    printf("Installing Prettier depencies\n");
                } else {
                    printf("An error ocurred, 'prettier' installation has failed.\n");
                }
            } else {
                perror("Failed to change directory");

            }
                return;
        } 

int main() {
    char name[100];
    checkNodeVersion();
    checkNPMVersion();
    createVite(name);
    installVite(name);
    installAxios(name);
    installCors(name);
    installExpress(name);
    installMorgan(name);
    installPrettier(name);
    installProptipes(name);
    installRouter(name);
    installSequelize(name);
    installServer(name);
    installWebToken(name); 
    return 0;
}