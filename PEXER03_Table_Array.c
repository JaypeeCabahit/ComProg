#include <stdio.h>

int main() {
    float price, tendered, change;
    int change_in_cents;
    int denom[] = {2000, 1000, 500, 100, 25, 10, 5}; // Denominations in cents
    int counts[7] = {0}; // To store the count for each denomination

    // Input item price and tendered amount
    printf("Enter the price of the item: ");
    scanf("%f", &price);
    printf("Enter the tendered amount: ");
    scanf("%f", &tendered);

    // Calculate change
    change = tendered - price;
    printf("Item price       : %.2f\n", price);
    printf("Tendered amount  : %.2f\n", tendered);
    printf("Change           : %.2f\n\n", change);

    // Convert change to cents
    change_in_cents = (int)(change * 100 + 0.5); // Adding 0.5 for rounding

    // Calculate denomination counts using the array
    for (int i = 0; i < 7; i++) {
        counts[i] = change_in_cents / denom[i];
        change_in_cents %= denom[i];
    }

    // Display denominations in a table
    printf("+------------------+---------+\n");
    printf("| Coin Denomination | Quantity|\n");
    printf("+------------------+---------+\n");
    printf("| 20.00 pesos       | %7d |\n", counts[0]);
    printf("| 10.00 pesos       | %7d |\n", counts[1]);
    printf("|  5.00 pesos       | %7d |\n", counts[2]);
    printf("|  1.00 pesos       | %7d |\n", counts[3]);
    printf("|  0.25 cents       | %7d |\n", counts[4]);
    printf("|  0.10 cents       | %7d |\n", counts[5]);
    printf("|  0.05 cents       | %7d |\n", counts[6]);
    printf("+------------------+---------+\n");

    return 0;
}
