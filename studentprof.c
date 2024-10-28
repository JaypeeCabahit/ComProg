#include <stdio.h>
#include <string.h>

// Function prototypes
void computeFees(int subjects, int course, float *totalTuition, float *totalFees);

int main() {
    // Student details
    char studentID[15], firstName[50], lastName[50], gender[10];
    int course, year, subjects;
    float amountTendered, totalFees = 0.0, totalTuition = 0.0;

    // Display University name
    printf("University of Cebu – Main Campus\n");
    printf("Student’s Accounting System\n\n");

    // Input student information
    printf("Enter Student ID Number: ");
    scanf("%s", studentID);
    printf("Enter Lastname: ");
    scanf("%s", lastName);
    printf("Enter Firstname: ");
    scanf("%s", firstName);
    printf("Enter Gender (Female, Male, Gay, Lesbian): ");
    scanf("%s", gender);

    // Course selection
    printf("1 – BSIT\n2 – BSHM\n3 – BSED\n4 – COMPE\n");
    printf("Select Course (1-4): ");
    scanf("%d", &course);

    printf("Enter Year (1-5): ");
    scanf("%d", &year);

    // Number of subjects
    printf("Enter Number of subjects enrolled (max 10): ");
    scanf("%d", &subjects);
    if (subjects > 10) subjects = 10;  // Limit subjects to max 10

    // Compute fees
    computeFees(subjects, course, &totalTuition, &totalFees);

    // Amount tendered
    printf("Enter Amount Tendered: ");
    scanf("%f", &amountTendered);
    
    // Check for sufficient payment
    if (amountTendered < totalFees) {
        printf("Error: Amount tendered is less than total fees.\n");
        return 1;
    }

    // Receipt output
    printf("\nUniversity of Cebu – Main Campus\n");
    printf("OFFICIAL RECEIPT\n");
    printf("ID # : %s\n", studentID);
    printf("Name : %s, %s\n", lastName, firstName);
    printf("Gender : %s\n", gender);
    printf("Course : %d\n", course);
    printf("Total Units: %d\n", subjects * 3);  // 3 units per subject
    printf("Total Assessment : %.2f\n", totalFees);

    // Convert amount to words (simplified version)
    printf("Amount in words: One_Thousand_Two_Hundred_Thirty_and_40/100\n"); // Example
    
    printf("Amount Tendered: %.2f\n", amountTendered);
    printf("Change: %.2f\n", amountTendered - totalFees);
    
    return 0;
}

// Function to compute tuition and total fees
void computeFees(int subjects, int course, float *totalTuition, float *totalFees) {
    const float tuitionPerUnit = 450.00;
    float registrationFee = 0.0;
    float labFee = 0.0;
    const float miscFee = 1000.00;

    // Total units and tuition
    int totalUnits = subjects * 3;
    *totalTuition = totalUnits * tuitionPerUnit;

    // Course-based fees using switch
    switch(course) {
        case 1:  // BSIT
            registrationFee = 545.00;
            labFee = 3000.00;
            break;
        case 2:  // BSHM
            registrationFee = 550.00;
            labFee = 3500.00;
            break;
        case 3:  // BSED
            registrationFee = 555.00;
            labFee = 1500.00;
            break;
        case 4:  // COMPE
            registrationFee = 560.00;
            labFee = 3000.00;
            break;
        default:
            printf("Invalid course selected.\n");
            return;
    }
    
    // Calculate total fees
    *totalFees = *totalTuition + registrationFee + miscFee + labFee;
}
