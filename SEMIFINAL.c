#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* arrays for converting numbers to words */
char *ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
char *teens[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
char *tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
char *thousands[] = {"", "Thousand", "Million"};

/* function to check if a string contains only digits
   used to make sure student id is valid */
int isDigitsOnly(char str[]) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0; /* return false if there's a non-digit character */
        }
    }
    return 1; /* return true if all characters are digits */
}

/* function to check if a string contains only letters
   used to validate first and last names */
int isLettersOnly(char str[]) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isalpha(str[i])) {
            return 0; /* return false if there's a non-letter character */
        }
    }
    return 1; /* return true if all characters are letters */
}

/* function to clear the input buffer
   helps when invalid input like letters are given instead of numbers */
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

/* helper function to convert a three-digit number into words
   this is used for numbers like 123 to "one hundred twenty three" */
void convertThreeDigit(int num, char *output) {
    if (num >= 100) {
        strcat(output, ones[num / 100]);
        strcat(output, " Hundred ");
        num %= 100;
    }
    if (num >= 20) {
        strcat(output, tens[num / 10]);
        strcat(output, " ");
        num %= 10;
    } else if (num >= 10) {
        strcat(output, teens[num - 10]);
        strcat(output, " ");
        num = 0;
    }
    if (num > 0) {
        strcat(output, ones[num]);
        strcat(output, " ");
    }
}

/* main function to convert the total amount into words
   handles numbers in thousands and millions */
void convertToWords(int num, char *output) {
    int thousandCounter = 0;
    while (num > 0) {
        if (num % 1000 != 0) {
            char temp[100] = "";
            convertThreeDigit(num % 1000, temp);
            strcat(temp, thousands[thousandCounter]);
            strcat(temp, " ");
            strcat(temp, output);
            strcpy(output, temp);
        }
        num /= 1000;
        thousandCounter++;
    }
    if (strlen(output) == 0) {
        strcpy(output, "Zero ");
    }
}

int main() {
    
    /* variables for student info and fees */
    char student_id[15];
    char first_name[15];
    char last_name[15];
    char gender[10];
    int course;
    int year;
    int subjects;
    float amountTendered;

    /* get and validate student id (only numbers allowed) */
    do {
        printf("Enter Student ID Number (Max 15 characters, numbers only): ");
        scanf("%s", student_id);
        if (!isDigitsOnly(student_id)) {
            printf("Error: Student ID should contain numbers only.\n");
        }
    } while (!isDigitsOnly(student_id));
    
    /* get and validate first name (only letters allowed) */
    do {
        printf("Enter First Name (Max 15 characters, letters only): ");
        scanf("%s", first_name);
        if (!isLettersOnly(first_name)) {
            printf("Error: First Name should contain letters only.\n");
        }
    } while (!isLettersOnly(first_name));
    
    /* get and validate last name (only letters allowed) */
    do {
        printf("Enter Last Name (Max 15 characters, letters only): ");
        scanf("%s", last_name);
        if (!isLettersOnly(last_name)) {
            printf("Error: Last Name should contain letters only.\n");
        }
    } while (!isLettersOnly(last_name));
    
    /* get and validate gender */
    int validGender = 0;
    do {
        printf("Enter Gender (Female, Male, Gay, Lesbian): ");
        scanf("%s", gender);
        if (strcmp(gender, "Female") == 0 || strcmp(gender, "Male") == 0 ||
            strcmp(gender, "Gay") == 0 || strcmp(gender, "Lesbian") == 0) {
            validGender = 1;
        } else {
            printf("Error: Please enter a valid gender (Female, Male, Gay, Lesbian).\n");
        }
    } while (!validGender);

    /* validate course selection */
    while (1) {
        printf("Select Course:\n");
        printf("1 - BSIT\n");
        printf("2 - BSHM\n");
        printf("3 - BSED\n");
        printf("4 - COMPE\n");
        printf("Enter the corresponding number for your course: ");
        if (scanf("%d", &course) != 1 || course < 1 || course > 4) {
            printf("Error: Please select a valid course number (1-4).\n");
            clearInputBuffer(); /* clear invalid input */
        } else {
            break;
        }
    }
    
    /* validate year level (1-5) */
    while (1) {
        printf("Enter Year Level (1-5): ");
        if (scanf("%d", &year) != 1 || year < 1 || year > 5) {
            printf("Error: Year Level must be between 1 and 5.\n");
            clearInputBuffer(); /* clear invalid input */
        } else {
            break;
        }
    }
    
    /* validate number of subjects (1-10) */
    while (1) {
        printf("Enter Number of Subjects Enrolled (Max 10): ");
        if (scanf("%d", &subjects) != 1 || subjects < 1 || subjects > 10) {
            printf("Error: Number of subjects must be between 1 and 10.\n");
            clearInputBuffer(); /* clear invalid input */
        } else {
            break;
        }
    }

    /* tuition fees and other fees per course */
    float tuitionPerUnit = 450.00;
    float registrationFee, miscellaneousFee = 1000.00, laboratoryFee;

    /* set fees based on course selection */
    switch (course) {
        case 1:
            registrationFee = 545.00;
            laboratoryFee = 3000.00;
            break;
        case 2:
            registrationFee = 550.00;
            laboratoryFee = 3500.00;
            break;
        case 3:
            registrationFee = 555.00;
            laboratoryFee = 1500.00;
            break;
        case 4:
            registrationFee = 560.00;
            laboratoryFee = 3000.00;
            break;
    }
    
    /* calculate total units and total tuition */
    int totalUnits = subjects * 3;
    float totalTuition = (totalUnits * tuitionPerUnit) + registrationFee + miscellaneousFee + laboratoryFee;
    int totalTuitionInt = (int) totalTuition; /* convert to integer for words */
    int cents = (int)((totalTuition - totalTuitionInt) * 100); /* calculate cents */

    /* validate amount tendered */
    do {
        printf("Enter Amount Tendered (Must be no less than %.2f): ", totalTuition);
        if (scanf("%f", &amountTendered) != 1 || amountTendered < totalTuition) {
            printf("Error: Amount tendered is less than the total assessment. Please provide a sufficient amount.\n");
            clearInputBuffer(); /* clear invalid input */
        } else {
            break;
        }
    } while (1);

    /* convert the total tuition to words */
    char totalInWords[500] = "";
    convertToWords(totalTuitionInt, totalInWords);

    /* print the official receipt */
    printf("\n\nUniversity of Cebu - Main Campus\nOFFICIAL RECEIPT\n\n");
    printf("ID #: %s\n", student_id);
    printf("Name: %s, %s\n", last_name, first_name);
    printf("Gender: %s\n", gender);
    printf("Course: ");
    switch (course) {
        case 1: printf("BSIT - "); 
        break;
        case 2: printf("BSHM - "); 
        break;
        case 3: printf("BSED - "); 
        break;
        case 4: printf("COMPE - "); 
        break;
    }
    printf("%d\n", year);
    printf("Total Units: %d\n", totalUnits);
    printf("Total Assessment: %.2f\n", totalTuition);

    /* print the amount in words
       if cents are 0, omit the "and 0/100" part */
    if (cents > 0) {
        printf("Amount in words: %sand %d/100\n", totalInWords, cents);
    } else {
        printf("Amount in words: %s\n", totalInWords);
    }

    return 0;
}
