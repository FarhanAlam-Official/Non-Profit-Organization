#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <windows.h> // For Sleep function

// Define the user structure
struct user
{
    char full_name[50];
    char email[50];
    char username[50];
    char password[25];
    char phone_number[25];
};
// Define a structure for project data
struct Project
{
    char projectCode[100];
    char projectName[100];
    char projectStartDate[20];
    char projectEndDate[20];
    char location[100];
    char projectManager[100];
    char leadOrganization[100];
    char beneficiaries[100];
    int budgetAllocated;
    int budgetUtilized;
    int timeAllotted;
    int timeUtilized;
    int staffAllotted;
    int staffUtilized;
};
// Delay function in milliseconds
void delay(int milliseconds)
{
    Sleep(milliseconds);
}
// Function prototypes
void register_user(FILE *fp);
int login_user(FILE *fp);
void introduction(FILE *fp);
void completed_project(FILE *fp);
void on_going_projects(FILE *fp);
void update_on_going_projects(FILE *fp);

int main()
{
    FILE *fp;
    int choice;
    int login_success;
    int exitProgram = 0; // Loop control variable
    fp=fopen("login.dat","r");
    login_success=login_user(fp);
    if(login_success!=1)
    {
        exit(1);
    }

    do
    {
        system("cls");
        printf("\t\t\t\t==============================================================================================\n");
        printf("\n\t\t\t\t                                  Welcome to RBK Foundation                                   \n");
        printf("                                                                                                   ");
        printf("\n\t\t\t\t                               -We Believe in a Better Tomorrow                                    \n\n");
        printf("\t\t\t\t==============================================================================================\n\n");

        printf("\n\t\t\t\t\t\t\t\t    **** Main Menu ****\n\n\n\n");
        printf("\n\t\t\t\t\t\t\t\t 1. Registration\n");
        printf("\n\t\t\t\t\t\t\t\t 2. Introduction of the NGO\n");
        printf("\n\t\t\t\t\t\t\t\t 3. Information of Completed Projects\n");
        printf("\n\t\t\t\t\t\t\t\t 4. Ongoing Project Details\n");
        printf("\n\t\t\t\t\t\t\t\t 5. Update_Ongoing Project Details\n");
        printf("\n\t\t\t\t\t\t\t\t 6. Exit");

        printf("\n\n\n\t\t\t\t==============================================================================================\n\n");

        printf("\n\n\t\t\t\t\t\t\t\t Please enter your choice:");
        scanf("%d", &choice);

        FILE *fp;

        switch (choice)
        {
        case 1:
            fp = fopen("new_user.dat", "a+");
            if (fp == NULL)
            {
                printf("Error opening file for registration\n");
                exit(1);
            }
            register_user(fp);
            fclose(fp);
            break;
        case 2:
            fp = fopen("ngo.dat", "r");
            if (fp == NULL)
            {
                printf("Error opening file for NGO introduction\n");
                exit(1);
            }
            introduction(fp);
            fclose(fp);
            break;
        case 3:
            fp = fopen("completed_projects.dat", "r");
            if (fp == NULL)
            {
                printf("Error opening file for completed projects\n");
                exit(1);
            }
            completed_project(fp);
            fclose(fp);
            break;
        case 4:
            fp = fopen("ongoing_projects.dat", "r");
            if (fp == NULL)
            {
                printf("Error opening file for ongoing projects\n");
                exit(1);
            }
            on_going_projects(fp);
            fclose(fp);
            break;
        case 5:
            fp= fopen("ongoing_projects.dat", "r");

            // Check if the file was opened successfully
            if (fp == NULL)
            {
                printf("Failed to open the file.\n");
                return 1;
            }
            update_on_going_projects(fp);
            break;
        case 6:
            exitProgram = 1; // Set the exit flag to exit the program
            break;
        default:
            printf("Invalid choice\n");
        }
    }
    while (!exitProgram);   // Continue looping until exit flag is set

    return 0;
}

void register_user(FILE *fp)
{
    struct user newuser;
    system("cls");

    printf("\t\t\t\t==============================================================================================\n");
    printf("\n\t\t\t\t                                       RBK Foundation                                   \n");
    printf("                                                                                                   ");
    printf("\n\t\t\t\t                               -We Believe in a Better Tomorrow                                    \n\n");
    printf("\t\t\t\t==============================================================================================\n\n");

    printf("\n\n\n");

    printf("\t\t\t\t\t\t\t\t    **** Registration ****\n\n\n");

    printf("\n\t\t\t\t\t\t\t\tEnter your Full name: ");
    scanf("%s", newuser.full_name);

    printf("\n\t\t\t\t\t\t\t\tEnter your Email: ");
    scanf("%s", newuser.email);

    printf("\n\t\t\t\t\t\t\t\tEnter your Phone number: ");
    scanf("%s", newuser.phone_number);

    printf("\n\t\t\t\t\t\t\t\tEnter a Username: ");
    scanf("%s", newuser.username);

    printf("\n\t\t\t\t\t\t\t\tEnter a Password: ");
    scanf("%s", newuser.password);

    // Write the new user data to the file
    fprintf(fp, "%s %s %s %s %s\n", newuser.full_name, newuser.email, newuser.phone_number, newuser.username, newuser.password);

    printf("\n\n\n\t\t\t\t\t\t\t Congratulation ,Registration successful !!\n\n\n");
    printf("\n\n\t\t\t\t\t\t\t\t Press any key to return to main menu.....");
    getch();
}

// Implement the login_user function with username and password validation
int login_user(FILE *fp)
{
    struct user users[100]; // Assuming you won't have more than 100 users
    int numusers = 0;
    char username[50];
    char password[25];
    int maxAttempts=3;
    int loginAttempts = 1; // Count of login attempts

    // Read user data from the file into the users array
    while (fscanf(fp, "%s %s %s %s %s",
                  users[numusers].full_name,
                  users[numusers].email,
                  users[numusers].phone_number,
                  users[numusers].username,
                  users[numusers].password) != EOF)
    {
        numusers++;
    }

    while (loginAttempts <= maxAttempts)
    {
        system("cls");
        printf("\t\t\t\t==============================================================================================\n");
        printf("\n\t\t\t\t                                  Welcome to RBK Foundation                                   \n");
        printf("                                                                                                   ");
        printf("\n\t\t\t\t                               -We Believe in a Better Tomorrow                                    \n\n");
        printf("\t\t\t\t==============================================================================================\n\n");

        printf("\n\n\n");

        printf("\t\t\t\t\t\t\t\t**** Login ****\n\n\n");
        // Prompt for username and password
        printf("\n\n\t\t\t\t\t\t\t   Username: ");
        scanf("%s", username);
        printf("\n\n\t\t\t\t\t\t\t   Password: ");
        scanf("%s", password);
        printf("\n\n\n");

        // Check if the entered username and password match any user
        for (int i = 0; i < numusers; i++)
        {
            if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0)
            {
                printf("\n\t\t\t\t\t\t\t\t\t Login successful!\n");
                printf("\n\n\t\t\t\t\t\t\t\t\t Welcome, %s!\n\n\n", users[i].full_name);
                delay(3000);
                return 1; // Login successful
            }
        }
        printf("\n\t\t\t\t\t\t\t\t\t Login failed !!!\n");
        printf("\n\t\t\t\t\t\t\t\t Invalid Username or Password.\n\n\n");
        printf("\n\n\t\t\t\t\t\t\t\t Attempt %d of %d\n", loginAttempts, maxAttempts);
        delay(2000);
        loginAttempts++;
    }

    printf("\n\n\t\t\t\t\t\t Maximum login attempts reached. Exiting...\n");
    delay(4000);
    return 0; // Login failed
}

void introduction(FILE *fp)
{
    system("cls");
    char line[256];

    printf("\t\t\t\t==============================================================================================\n");
    printf("\n\t\t\t\t                                  Welcome to RBK Foundation                                   \n");
    printf("                                                                                                   ");
    printf("\n\t\t\t\t                               -We Believe in a Better Tomorrow                                    \n\n");
    printf("\t\t\t\t==============================================================================================\n\n");

    printf("\n\n\n");

    printf("\t\t\t\t\t\t\t\t**** Introduction of the NGO ****\n\n\n");

    // Read and display the introduction from the file
    while (fgets(line, sizeof(line), fp))
    {
        printf("%s", line);
    }

    printf("\n\n");
    printf("\n\n\t\t\t\t\t\t\t\t Press any key to return to main menu.....");
    getch();
}

void completed_project(FILE *fp)
{
    system("cls");
    char line[256];
    int isProjectStarted = 0;

    printf("\t\t\t\t==============================================================================================\n");
    printf("\n\t\t\t\t                                  Welcome to RBK Foundation                                   \n");
    printf("                                                                                                   ");
    printf("\n\t\t\t\t                               -We Believe in a Better Tomorrow                                    \n\n");
    printf("\t\t\t\t==============================================================================================\n\n");

    printf("\n\n\n");

    printf("\t\t\t\t\t\t\t\t**** Completed Projects ****\n\n\n");

    // Read and display each completed project
    while (fgets(line, sizeof(line), fp))
    {
        if (strstr(line, "Project:") != NULL)
        {
            // Start of a new project
            isProjectStarted = 1;
            printf("\n");
        }
        else if (isProjectStarted)
        {
            // Display the project details
            printf("%s", line);
        }
    }

    printf("\n\n");
    printf("\n\n\t\t\t\t\t\t\t\t Press any key to return to main menu.....");
    getch();
}

void on_going_projects(FILE *fp)
{
    system("cls");
    struct Project project; // Declare a variable of the Project structure type
    printf("\t\t\t\t==============================================================================================\n");
    printf("\n\t\t\t\t                                  Welcome to RBK Organization                                   \n");
    printf("                                                                                                   ");
    printf("\n\t\t\t\t                               -We Believe in a Better Tomorrow                                    \n\n");
    printf("\t\t\t\t==============================================================================================\n\n");

    printf("\n\n\n");

    printf("\t\t\t\t\t\t\t\t**** Ongoing Projects ****\n\n\n");

    // Read and display data for each project in a loop
    while (fscanf(fp, "%s %s %s %s %s %s %s %s %d %d %d %d %d %d",
                  project.projectCode, project.projectName, project.projectStartDate, project.projectEndDate,
                  project.location, project.projectManager, project.leadOrganization,
                  project.beneficiaries, &project.budgetAllocated, &project.budgetUtilized,
                  &project.timeAllotted, &project.timeUtilized, &project.staffAllotted, &project.staffUtilized) !=EOF)
    {

        // Display the read data with appropriate labels
        printf("\n\n\n\n\t\t\t\t\t\t Project Code:       %s\n\n", project.projectCode);
        printf("\t\t\t\t\t\t Project Name       :%s\n\n", project.projectName);
        printf("\t\t\t\t\t\t Project Start Date :%s\n\n", project.projectStartDate);
        printf("\t\t\t\t\t\t Project End Date   :%s\n\n", project.projectEndDate);
        printf("\t\t\t\t\t\t Location           :%s\n\n", project.location);
        printf("\t\t\t\t\t\t Project Manager    :%s\n\n", project.projectManager);
        printf("\t\t\t\t\t\t Lead Organization  :%s\n\n", project.leadOrganization);
        printf("\t\t\t\t\t\t Beneficiaries      :%s\n\n", project.beneficiaries); // Beneficiaries as a string
        printf("\t\t\t\t\t\t Budget Allocated   :Rs.%d\n\n", project.budgetAllocated);
        printf("\t\t\t\t\t\t Budget Utilized    :Rs.%d\n\n", project.budgetUtilized);
        printf("\t\t\t\t\t\t Time Allotted      :%d Months\n\n", project.timeAllotted); // Time Allotted as an integer
        printf("\t\t\t\t\t\t Time Utilized      :%d Months\n\n", project.timeUtilized); // Time Utilized as an integer
        printf("\t\t\t\t\t\t Staff Allotted     :%d Employees\n\n", project.staffAllotted);
        printf("\t\t\t\t\t\t Staff Utilized     :%d Employees\n\n", project.staffUtilized);
        printf("\n\n"); // Add a newline to separate project data
    }
     char ch;
                printf("\t\t\t\t\t\t\t Do you want to update details of any project? (Y/N): ");
                scanf(" %c", &ch);

                if (ch == 'y' || ch == 'Y')
                {
                    update_on_going_projects(fp);
                }
                else{
                 printf("\n\n\t\t\t\t\t\t\t\t Press any key to return to main menu.....");
        getch();
                }
}
void update_on_going_projects(FILE *fp)
    {
        system("cls");
        printf("\t\t\t\t==============================================================================================\n");
        printf("\n\t\t\t\t                                  Welcome to RBK Organization                                   \n");
        printf("                                                                                                   ");
        printf("\n\t\t\t\t                               -We Believe in a Better Tomorrow                                    \n\n");
        printf("\t\t\t\t==============================================================================================\n\n");

        printf("\n\n\n");

        printf("\t\t\t\t\t\t\t  **** Updating Ongoing Projects ****\n\n\n");
        struct Project project; // Declare a variable of the Project structure type
        // Create a temporary file
        FILE *tempFile = fopen("temp.dat", "w");
        if (tempFile == NULL)
        {
            printf("Failed to create a temporary file.\n");
            fclose(fp);
            return 1;
        }

        // Ask the user for a project code to update
        char targetProjectCode[100];
        printf("\t\t\t\t\t\t Enter the project code you want to update: ");
        scanf("%s", targetProjectCode);

        int found = 0; // Flag to indicate if the project was found

        // Read and display data for each project in a loop
        while (fscanf(fp, "%s %s %s %s %s %s %s %s %d %d %d %d %d %d",
                      project.projectCode, project.projectName, project.projectStartDate, project.projectEndDate,
                      project.location, project.projectManager, project.leadOrganization,
                      project.beneficiaries, &project.budgetAllocated, &project.budgetUtilized,
                      &project.timeAllotted, &project.timeUtilized, &project.staffAllotted, &project.staffUtilized) !=EOF)
        {
            // Check if the project code matches the target code
            if (strcmp(project.projectCode, targetProjectCode) == 0)
            {
                found = 1; // Set the flag to indicate the project was found

                // Display the read data with appropriate labels
                printf("\n\n\n\n\t\t\t\t\t\t Project Code:       %s\n\n", project.projectCode);
                printf("\t\t\t\t\t\t Project Name       :%s\n\n", project.projectName);
                printf("\t\t\t\t\t\t Project Start Date :%s\n\n", project.projectStartDate);
                printf("\t\t\t\t\t\t Project End Date   :%s\n\n", project.projectEndDate);
                printf("\t\t\t\t\t\t Location           :%s\n\n", project.location);
                printf("\t\t\t\t\t\t Project Manager    :%s\n\n", project.projectManager);
                printf("\t\t\t\t\t\t Lead Organization  :%s\n\n", project.leadOrganization);
                printf("\t\t\t\t\t\t Beneficiaries      :%s\n\n", project.beneficiaries); // Beneficiaries as a string
                printf("\t\t\t\t\t\t Budget Allocated   :Rs.%d\n\n", project.budgetAllocated);
                printf("\t\t\t\t\t\t Budget Utilized    :Rs.%d\n\n", project.budgetUtilized);
                printf("\t\t\t\t\t\t Time Allotted      :%d Months\n\n", project.timeAllotted); // Time Allotted as an integer
                printf("\t\t\t\t\t\t Time Utilized      :%d Months\n\n", project.timeUtilized); // Time Utilized as an integer
                printf("\t\t\t\t\t\t Staff Allotted     :%d Employees\n\n", project.staffAllotted);
                printf("\t\t\t\t\t\t Staff Utilized     :%d Employees\n\n", project.staffUtilized);
                printf("\n\n"); // Add a newline to separate project data
                char ch;
                printf("\t\t\t\t\t\t\t Do you want to update resources for this project? (Y/N): ");
                scanf(" %c", &ch);

                if (ch == 'y' || ch == 'Y')
                {
                    // Ask the user if they want to update resources
                    int choice;
                    printf("\n\n\n\t\t\t\t\t\t\t What do you want to update?\n");
                    printf("\n\t\t\t\t\t\t\t 1.  Budget Utilized\n");
                    printf("\n\t\t\t\t\t\t\t 2.  Time Utilized\n");
                    printf("\n\t\t\t\t\t\t\t 3.  Staff Utilized\n");
                    printf("\n\t\t\t\t\t\t\t 4.  All Resources\n");
                    printf("\n\t\t\t\t\t\t\t 0.  No Updates\n");
                    printf("\n\t\t\t\t\t\t\t Enter your choice: ");
                    scanf("%d", &choice);

                    if (choice == 1)
                    {
                        printf("\n\n\t\t\t\t\t\t Enter the new Budget Utilized: ");
                        scanf("%d", &project.budgetUtilized);
                    }
                    else if (choice == 2)
                    {
                        printf("\n\n\t\t\t\t\t\t Enter the new Time Utilized: ");
                        scanf("%d", &project.timeUtilized);
                    }
                    else if (choice == 3)
                    {
                        printf("\n\n\t\t\t\t\t\t Enter the new Staff Utilized: ");
                        scanf("%d", &project.staffUtilized);
                    }
                    else if (choice == 4)
                    {
                        printf("\n\n\t\t\t\t\t\t Enter the new Budget Utilized: ");
                        scanf("%d", &project.budgetUtilized);
                        printf("\n\n\t\t\t\t\t\t Enter the new Time Utilized: ");
                        scanf("%d", &project.timeUtilized);
                        printf("\n\n\t\t\t\t\t\t Enter the new Staff Utilized: ");
                        scanf("%d", &project.staffUtilized);
                    }
                }

            }
            // Write the project data to the temporary file
            fprintf(tempFile, "%s %s %s %s %s %s %s %s %d %d %d %d %d %d\n",
                    project.projectCode, project.projectName, project.projectStartDate, project.projectEndDate,
                    project.location, project.projectManager, project.leadOrganization,
                    project.beneficiaries, project.budgetAllocated, project.budgetUtilized,
                    project.timeAllotted, project.timeUtilized, project.staffAllotted, project.staffUtilized);
        }

        // Close both files
        fclose(fp);
        fclose(tempFile);

        // Remove the old file and rename the temporary file if the project was found
        if (found)
        {
            if (remove("ongoing_projects.dat") == 0 && rename("temp.dat", "ongoing_projects.dat") == 0)
            {
                printf("\n\n\t\t\t\t\t\t\t\t Project Details updated successfully.\n");
            }
            else
            {
                printf("\n\n\t\t\t\t\t\t\t\t Project Details not updated successfully.\n");
            }
        }
        else
        {
            printf("\n\n\t\t\t\t\t\t\t     Project with code '%s' not found.\n", targetProjectCode);
        }
        printf("\n\n\t\t\t\t\t\t\t   Press any key to return to main menu.....");
        getch();
    }
