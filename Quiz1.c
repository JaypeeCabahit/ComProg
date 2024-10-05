#include <stdio.h>

int main() {
    double grossSalary, tax;

    printf("Input the gross salary of the employee: ");
    scanf("%lf", &grossSalary);

    if (grossSalary <= 50000) {
        tax = 0.10 * grossSalary;
    } else if (grossSalary <= 100000) {
        tax = 5000 + 0.15 * (grossSalary - 50000);
    } else if (grossSalary <= 200000) {
        tax = 15000 + 0.20 * (grossSalary - 100000);
    } else {
        tax = 0.25 * grossSalary;
    }

    printf("The tax due is: %.2lf\n", tax);

    return 0;
}
