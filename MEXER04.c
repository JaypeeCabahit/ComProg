#include <stdio.h>

int main() {
    // Declare variables to store three integers
    int num1, num2, num3, largest;

    // Input: three integers
    printf("Enter three integers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    // Two-way branching to find the largest number
    if (num1 >= num2) {
        if (num1 >= num3) {
            largest = num1;  // num1 is greater than or equal to both num2 and num3
        } else {
            largest = num3;  // num3 is greater than num1 but num1 is greater than or equal to num2
        }
    } else {
        if (num2 >= num3) {
            largest = num2;  // num2 is greater than or equal to both num1 and num3
        } else {
            largest = num3;  // num3 is greater than both num1 and num2
        }
    }

    // Output: the largest number
    printf("The largest number is: %d\n", largest);

    return 0;
}
