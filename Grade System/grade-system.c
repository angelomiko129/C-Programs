/*Group 9 Coding Challenge 3 (Grade System)
Val Angbengco
Mark Andrei Muyna
James Aizard Ramirez
Angelo Miko Botabara
Christian Joseph Ramirez */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 8
#define PASSING_GRADE 75

//function declaration//
void nineGrades(int grades[]);
void generateGrades(int grades[]);
void displayGrades(int grades[]);
void searchGrade(int grades[]);
void sortGrades(int grades[]);
void computeAverage(int grades[]);
void countPassGrades(int grades[]);
void countFailGrades(int grades[]);
void runChoice();
void selectionStatement();

int grades[ARRAY_SIZE];
char choice, continueChoice;

int main() {
    nineGrades(grades);
}
//display selections//
void nineGrades(int grades[]) {
    generateGrades(grades);

    do{
        
        printf("\n=================================\n");
        displayGrades(grades);
        printf("\n");
        
        printf("A. Search for Specific Grade\n");
        printf("B. Sort Grades\n");
        printf("C. Compute Average Grade\n");
        printf("D. Count Number of PASS Grades\n");
        printf("E. Count Number of FAIL Grades\n");
        printf("F. Exit\n");
       
        printf("\nEnter your choice: ");
        scanf(" %c", &choice);
        printf("=================================\n");
        
        selectionStatement();
       
    }while(continueChoice == 'Y');
}
//create new or display again//
void runChoice(){
    scanf("%c", &continueChoice);
    if (continueChoice == 'N') {
        displayGrades(grades);
        selectionStatement();
    }
}
//selection of given operation // 
void selectionStatement(){
        if(choice == 'A'){
            printf("\n");
            printf("A. Search for Specific Grade\n\n");
            searchGrade(grades);
            runChoice();
        }
        else if(choice == 'B'){
            printf("\n");
            printf("B. Sort Grades\n\n");
            sortGrades(grades);
            runChoice();
        }
        else if(choice == 'C'){
            printf("\n");
             printf("C. Compute Average Grade\n\n");
            computeAverage(grades);
            runChoice();
        }
        else if(choice == 'D'){
            printf("\n");
            printf("D. Count Number of PASS Grades\n\n");
            countPassGrades(grades);
            runChoice();
        }
        else if(choice == 'E'){
            printf("\n");
            printf("E. Count Number of FAIL Grades\n\n");
            countFailGrades(grades);
            runChoice();
        }
        else if(choice == 'F'){
            printf("\n");
            printf("\n\nThank You!\nPress Esc to exit...");
            exit(1);
        }
        else{
            printf("\n");
            printf("Invalid choice");
            runChoice();
        }
        
}

//make list of grades in random//
void generateGrades(int grades[]) {
    srand(time(NULL));

    for (int i = 0; i < ARRAY_SIZE; i++) {
        grades[i] = rand() % 51 + 50; // Generates random number from 50 to 100//
        
    }
}
//display list of grades //
void displayGrades(int grades[]) {
    printf("List of Grades: \n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d\t ", grades[i]);
    }
    printf("\n");
}
//find the specific grade selected by user//
void searchGrade(int grades[]) {
    int count = 0;
    int search;
    printf("Enter the grade you want to search for: ");
    scanf("%d", &search);

    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (grades[i] == search) {
        count++;
        }
    }
    if (count == 0) {
        printf("\nResult: Not found!\n");
    } else {
        printf("\nResult: %d occurence(s)\n", count);
        
    
    }
    printf("\nPress Y to return to Operations, press N to try again: ");
    runChoice();
    
}
//sort in ascending and descending//
void sortGrades(int grades[]) {
    int temp, user, i, j;
    
    printf("Sorting Operation:\n[1] Ascending\n[2] Descending\nEnter Operation: ");
    scanf("%d", &user);
    
    if(user == 1){
        printf("\nGrades sorted in ascending order.\n");
        for (i = 0; i < ARRAY_SIZE - 1; i++) {
        for (j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (grades[j] > grades[j + 1]) {
                temp = grades[j];
                grades[j] = grades[j + 1];
                grades[j + 1] = temp;
                
            }
        }
        }
        displayGrades(grades);
        printf("\nPress Y to return to Operations, press N to try again: ");
        runChoice();
    }
    else if(user == 2){
        printf("\nGrades sorted in descending order.\n");
        for (i = 0; i < ARRAY_SIZE - 1; i++) {
            for (j = 0; j < ARRAY_SIZE - i - 1; j++) {
                if (grades[j] < grades[j + 1]) {
                    temp = grades[j];
                    grades[j] = grades[j + 1];
                    grades[j + 1] = temp;
                   
                }
            }
        }
        displayGrades(grades);
        printf("\nPress Y to return to Operations, press N to try again: ");
        runChoice();
    }
    
    
    
}
//compute total average of selected grades//
void computeAverage(int grades[]) {
    int sum = 0;
    float average;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += grades[i];
    }
    

    average = (float) sum / ARRAY_SIZE;
    printf("Average Grade: %.0f%%\n", average);
    printf("\nPress Y to return to Operations, press N to try again: ");
    runChoice();
}
//count how many grades has passed 75%//
void countPassGrades(int grades[]) {
    int passCount = 0;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (grades[i] >= PASSING_GRADE) {
            passCount++;
        }
    }

    printf("Count: %d\n", passCount);
    printf("\nPress Y to return to Operations, press N to try again: ");
    runChoice();
}
//count how many grades failed //
void countFailGrades(int grades[]) {
    int failCount = 0;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (grades[i] < PASSING_GRADE) {
            failCount++;
        }
    }

    printf("Count: %d\n", failCount);
    printf("\nPress Y to return to Operations, press N to try again: ");
    runChoice();
}