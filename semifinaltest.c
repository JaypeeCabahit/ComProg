#include <stdio.h>
#include <string.h>

void convertToWords(int num, char *result);

int main() {
    char studentID[20];
    char firstName[30];
    char lastName[30];
    char gender[10];
    char courseCode[5];
    
    int course;
    int year;
    int subjectsEnrolled;
    
    float amountTendered;
    float totalTuition;
    float registrationFee;
    float miscellaneousFee;
    float laboratoryFee;
    float totalUnits;
    float totalAssessment;
    char amountInWords[200] = "";

    const float tuitionPerUnit = 450.00;

    /* Set fees based on course selection */
    float registrationFees[] = {545.00, 550.00, 555.00, 560.00};
    float miscellaneousFees[] = {1000.00, 1000.00, 1000.00, 1000.00};
    float laboratoryFees[] = {3000.00, 3500.00, 1500.00, 3000.00};

    printf("University of Cebu – Main Campus\n");
    printf("Student's Accounting System\n\n");

    /* Input student info */
    printf("Enter Student ID Number: ");
    scanf("%s", studentID);
    printf("Enter Firstname: ");
    scanf("%s", firstName);
    printf("Enter Lastname: ");
    scanf("%s", lastName);
    printf("Enter Gender (Female, Male, Gay, Lesbian): ");
    scanf("%s", gender);
    printf("Select Course:\n1 - BSIT\n2 - BSHM\n3 - BSED\n4 - COMPE\nCourse: ");
    scanf("%d", &course);
    printf("Enter Year (1 to 5): ");
    scanf("%d", &year);
    printf("Enter Number of Subjects Enrolled: ");
    scanf("%d", &subjectsEnrolled);

    /* Calculate total units and total tuition */
    totalUnits = subjectsEnrolled * 3; // 3 units per subject
    totalTuition = totalUnits * tuitionPerUnit;
    registrationFee = registrationFees[course - 1];
    miscellaneousFee = miscellaneousFees[course - 1];
    laboratoryFee = laboratoryFees[course - 1];

    totalAssessment = totalTuition + registrationFee + miscellaneousFee + laboratoryFee;

    /* Prompt for amount tendered, ensuring it meets the minimum requirement */
    do {
        printf("Enter Amount Tendered (Must be no less than %.2f): ", totalAssessment);
        scanf("%f", &amountTendered);
        
        if (amountTendered < totalAssessment) {
            printf("Error! Your amount tendered must be NO LESS than the total assessment of %.2f.\n", totalAssessment);
        }
    } while (amountTendered < totalAssessment);

    /* Convert total assessment to words */
    convertToWords((int)totalAssessment, amountInWords);

    /* Print the official receipt */
    printf("\n\nUniversity of Cebu – Main Campus\n");
    printf("OFFICIAL RECEIPT\n\n");
    printf("ID #: %s\n", studentID);
    printf("Name: %s, %s\n", lastName, firstName);
    printf("Gender: %s\n", gender);
    printf("Course: %d\n", course);
    printf("Year: %d\n", year);
    printf("Total Units: %.0f\n", totalUnits);
    printf("Total Assessment: %.2f\n", totalAssessment);
    printf("Amount in Words: %s\n", amountInWords);
    printf("Amount Tendered: %.2f\n", amountTendered);

    return 0;
}

/* Helper function to convert numbers to words */
void convertToWords(int num, char *result) {
    char *ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    char *teens[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    char *tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    int tenThousands = (num / 10000) % 10;
    int thousands = (num / 1000) % 10;
    int hundreds = (num / 100) % 10;
    int tensPlace = (num / 10) % 10;
    int onesPlace = num % 10;
    
    if (tenThousands > 1) {
        strcat(result, tens[tenThousands]);
        strcat(result, "_");
        strcat(result, ones[thousands]);
        strcat(result, "_Thousand_");
    } else if (tenThousands == 1) {
        strcat(result, teens[thousands]);
        strcat(result, "_Thousand_");
    } else if (thousands > 0) {
        strcat(result, ones[thousands]);
        strcat(result, "_Thousand_");
    }

    if (hundreds > 0) {
        strcat(result, ones[hundreds]);
        strcat(result, "_Hundred_");
    }

    if (tensPlace > 1) {
        strcat(result, tens[tensPlace]);
        strcat(result, "_");
        strcat(result, ones[onesPlace]);
    } else if (tensPlace == 1) {
        strcat(result, teens[onesPlace]);
    } else {
        strcat(result, ones[onesPlace]);
    }
}
