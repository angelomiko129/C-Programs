/*Group 9 Midterm Examination (Salary System)
Val Angbengco
Mark Andrei Muyna
James Aizard Ramirez
Angelo Miko Botabara
Christian Joseph Ramirez */

#include <stdio.h>

//function declaration
float calculateAllowancesDeductions(float basicSalary, float *hra, float *da, float *ea, float *ta, float *ss, float *levy);
float calculateTotalAllowances(float hra, float da, float ea, float ta);
float calculateTotalDeductions(float ss, float levy);
float calculateGrossSalary(float basicSalary, float totalAllowances);
float calculateNetSalary(float grossSalary, float totalDeductions);


int main() {
    float basicSalary, hra, da, ea, ta, ss, levy, totalAllowances, totalDeductions, grossSalary, netSalary;

    printf("Enter the basic salary: ");
    if (scanf("%f", &basicSalary) != 1) {
        printf("Invalid input. Please enter a numeric value for the basic salary.\n");
        return 0;
    }

// function call
    calculateAllowancesDeductions(basicSalary, &hra, &da, &ea, &ta, &ss, &levy);
    totalAllowances = calculateTotalAllowances(hra, da, ea, ta);
    totalDeductions = calculateTotalDeductions(ss, levy);
    grossSalary = calculateGrossSalary(basicSalary, totalAllowances);
    netSalary = calculateNetSalary(grossSalary, totalDeductions);

    printf("===============================\n");
    printf("\nSalary Details\n");
    printf("===============================\n\n");
    printf("Basic Salary: \t\t%.2f\n", basicSalary);
    printf("===============================\n\n");
    
    printf("HRA: \t\t\t%.2f\n", hra);
    printf(" DA: \t\t\t%.2f\n", da);
    printf(" EA: \t\t\t%.2f\n", ea);
    printf(" TA: \t\t\t%.2f\n", ta);
    printf("===============================\n\n");
    printf("Total Allowances: \t%.2f\n", totalAllowances);
    printf("===============================\n\n");
    
    printf("  SS: \t\t\t%.2f\n", ss);
    printf("Levy: \t\t\t%.2f\n", levy);
    printf("===============================\n\n");
    printf("Total Deductions: \t%.2f\n", totalDeductions);
    printf("===============================\n\n");
    printf("Gross Salary: \t\t%.2f\n", grossSalary);
    printf("Net Salary: \t\t%.2f\n", netSalary);
    printf("===============================\n\n");
    printf("Group: \t\t\t9\n");
    printf("===============================\n\n");

    return 0;
}

// function definition

// Function to calculate each item in allowances and deductions
float calculateAllowancesDeductions(float basicSalary, float *hra, float *da, float *ea, float *ta, float *ss, float *levy) {
    *hra = 0.15 * basicSalary;
    *da = 0.1 * basicSalary;
    *ea = 0.05 * basicSalary;
    *ta = 0.12 * basicSalary;
    *ss = 0.07 * basicSalary;
    *levy = 0.01 * basicSalary;

    return *hra, *da, *ea, *ta, *ss, *levy;
}

// Function to calculate the total allowances
float calculateTotalAllowances(float hra, float da, float ea, float ta) {
    return hra + da + ea + ta;
}

// Function to calculate the total deductions
float calculateTotalDeductions(float ss, float levy) {
    return ss + levy;
}

// Function to calculate the gross salary
float calculateGrossSalary(float basicSalary, float totalAllowances) {
    return basicSalary + totalAllowances;
}

// Function to calculate the net salary
float calculateNetSalary(float grossSalary, float totalDeductions) {
    return grossSalary - totalDeductions;
}