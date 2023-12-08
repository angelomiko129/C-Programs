/*Group 9 Coding Challenge 5 (Simple Payroll System using C Structures)
Val D. Angbengco
James Aizard B. Ramirez
Angelo Miko A. Botabara
Mark Andrei B. Muyna
Christian Joseph C. Ramirez*/

#include <stdio.h>
#include <string.h>
#include <ctype.h> // library to use the function toupper

// defining a constant variable
#define MAX_ID_ARR 20
#define MAX_EMP_NAME 50
#define MAX_EMP_STATUS 15
#define MAX_NUM_OF_EMP 10

// array structure declaration
struct Employees
{
    char emp_id[MAX_ID_ARR];
    char emp_name[MAX_EMP_NAME];
    char emp_status[MAX_EMP_STATUS];
    double emp_basic;
    double emp_net;
};

// function declaration
void try_Again(int numOfEmp, struct Employees employees[]);
void transactionIDSelection(int numOfEmp, struct Employees employees[]);
void addNewEmployee(int numOfEmp, struct Employees employees[]);
void computePayRoll(int numOfEmp, struct Employees employees[]);
void summarizePayroll(int numOfEmp, struct Employees employees[]);
void exitProgram();

// global variable declaration
int transactionID;
char tryAgain;
int i;
int counter = 0; // counter variable to track the number of employees added

int main()
{
    // array structure variable declaration named employees
    struct Employees employees[MAX_NUM_OF_EMP];

    do
    {
        printf("\n|---------------------------------------|\n");
        printf("|              Main Program             |\n");
        printf("|---------------------------------------|\n");
        printf("|[1] Add New Employee                   |\n");
        printf("|[2] Compute Payroll                    |\n");
        printf("|[3] Summarize Payroll                  |\n");
        printf("|[4] Exit Program                       |\n");
        printf("|---------------------------------------|\n\n");

        printf("Enter transaction ID: ");
        scanf("%d", &transactionID);
        transactionIDSelection(MAX_NUM_OF_EMP, employees);

        printf("\n");
    } while (tryAgain == 'N' || tryAgain == 'n'); // If Y, try again the chosen function. If N, return to the Main program.

    return 0;
}

// function to tryAgain
void try_Again(int numOfEmp, struct Employees employees[])
{
    if (transactionID != 4)
    {
        printf("\nTry again [Y/N]: ");
        scanf(" %c", &tryAgain);
        printf("\n---------------------------------------------------------------\n");

        if (tryAgain == 'Y' || tryAgain == 'y')
            transactionIDSelection(MAX_NUM_OF_EMP, employees);
    }
}

// function to select a transaction option
void transactionIDSelection(int numOfEmp, struct Employees employees[])
{
    switch (transactionID)
    {
    case 1:
        printf("\n---------------------------------------------------------------\n");
        printf("[1] Add New Employee\n\n");
        addNewEmployee(MAX_NUM_OF_EMP, employees);
        break;
    case 2:
        printf("\n---------------------------------------------------------------\n");
        printf("\n[2] Compute Payroll\n\n");
        computePayRoll(MAX_NUM_OF_EMP, employees);
        try_Again(MAX_NUM_OF_EMP, employees);
        break;
    case 3:
        printf("\n---------------------------------------------------------------\n");
        printf("\n[3] Summarize Payroll\n\n");
        summarizePayroll(MAX_NUM_OF_EMP, employees);
        try_Again(MAX_NUM_OF_EMP, employees);
        break;
    case 4:
        printf("\n---------------------------------------------------------------\n");
        printf("\n[4] Exit Program\n\n");
        exitProgram();
        break;
    default:
        printf("\nInvalid transaction ID!\n");
        break;
    }
}

// function to add new employee details to the database or to its proper index
void addNewEmployee(int numOfEmp, struct Employees employees[])
{
    while (counter < numOfEmp) // will loop until user input the desired number of employees information
    {
        printf("Enter Employee ID: ");
        scanf("%s", employees[counter].emp_id);
        getchar();
        fflush(stdin);

        printf("Enter Employee name: ");
        fgets(employees[counter].emp_name, sizeof(employees[counter].emp_name), stdin);
        employees[counter].emp_name[strcspn(employees[counter].emp_name, "\n")] = '\0';

        for (int j = 0; employees[counter].emp_name[j] != '\0'; j++)
        {
            employees[counter].emp_name[j] = toupper(employees[counter].emp_name[j]); // converting user input jumbled letters to upper case
        }

        printf("Employment status [A] Contractual [B] Casual [C] Regular: ");
        scanf(" %c", &employees[counter].emp_status[counter]);
        fflush(stdin);

        if (employees[counter].emp_status[counter] == 'A' || employees[counter].emp_status[counter] == 'a')
        {
            strcpy(employees[counter].emp_status, "CONTRACTUAL");
            employees[counter].emp_basic = 10000.00;
        }
        else if (employees[counter].emp_status[counter] == 'B' || employees[counter].emp_status[counter] == 'b')
        {
            strcpy(employees[counter].emp_status, "CASUAL");
            employees[counter].emp_basic = 15000.00;
        }
        else if (employees[counter].emp_status[counter] == 'C' || employees[counter].emp_status[counter] == 'c')
        {
            strcpy(employees[counter].emp_status, "REGULAR");
            employees[counter].emp_basic = 25000.00;
        }

        printf("\n---------------------------------------------------------------\n");

        printf("\nNew employee record is successfully saved into the database!\n");

        printf("\nEmployee ID:\t\t %s\n", employees[counter].emp_id);
        printf("Employee name:\t\t %s\n", employees[counter].emp_name);
        printf("Employment status:\t %s\n", employees[counter].emp_status);
        printf("Basic salary:\t\t %.2f\n", employees[counter].emp_basic);

        counter++; // increment the counter variable to move to the next index

        printf("\nTry again [Y/N]: ");
        scanf(" %c", &tryAgain);
        printf("\n---------------------------------------------------------------\n");

        if (tryAgain == 'N' || tryAgain == 'n')
            break; // return to main program if user choose No
    }
}

// function to compute for net salary and display the updated details
void computePayRoll(int numOfEmp, struct Employees employees[])
{
    char inputEmpID[MAX_ID_ARR];
    printf("Enter Employee ID: ");
    scanf("%s", inputEmpID);
    fflush(stdin);

    int found = 0; // track the employee ID if it exist

    for (i = 0; i < numOfEmp; i++)
    {
        if (strcmp(inputEmpID, employees[i].emp_id) == 0) // compare the inputted employee ID to find with the stored employee ID
        {
            found = 1;

            printf("\nEmployee name:\t\t %s\n", employees[i].emp_name);
            printf("Employment status:\t %s\n", employees[i].emp_status);
            printf("Basic salary:\t\t %.2f\n", employees[i].emp_basic);

            // if employee status comparison is true compute their net salary based on the given value
            if (strcmp(employees[i].emp_status, "CONTRACTUAL") == 0)
            {
                employees[i].emp_net = employees[i].emp_basic * 1.05;
            }
            else if (strcmp(employees[i].emp_status, "CASUAL") == 0)
            {
                employees[i].emp_net = employees[i].emp_basic * 1.10;
            }
            else if (strcmp(employees[i].emp_status, "REGULAR") == 0)
            {
                employees[i].emp_net = employees[i].emp_basic * 1.20;
            }

            printf("Net salary:\t\t %.2f\n", employees[i].emp_net);

            break; // exit the loop/prompt after finding the employee ID
        }
    }

    if (!found) // if the employee ID is not found print no record found
    {
        printf("\nNo record Found!\n");
    }
}

// function to summarize payroll for all added employees
void summarizePayroll(int numOfEmp, struct Employees employees[])
{
    for (i = 0; i < counter; i++)
    {
        printf("\nEmployee ID:\t\t %s\n", employees[i].emp_id);
        printf("Employee name:\t\t %s\n", employees[i].emp_name);
        printf("Employment status:\t %s\n", employees[i].emp_status);
        printf("Basic salary:\t\t %.2f\n", employees[i].emp_basic);

        if (employees[i].emp_net > 0.1) // will print the net salary if employees net salary is greater than 0.1 else not
        {
            printf("Net salary:\t\t %.2f\n", employees[i].emp_net);
        }
        printf("-------------------------------------------\n");
    }
}

// function to end the program
void exitProgram()
{
    printf("Press any key to terminate the execution of the program...");
    getchar();
    scanf("%c");
}