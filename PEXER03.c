#include <stdio.h>

int main() {
    float price, tendered, change;
    int change_in_cents;
    int denomination_20, denomination_10, denomination_5, denomination_1;
    int cent_25, cent_10, cent_5;

    // Input item price and tendered amount
    printf("Enter the price of the item: ");
    scanf("%f", &price);
    printf("Enter the tendered amount: ");
    scanf("%f", &tendered);

    // Calculate change
    change = tendered - price;
    printf("Item price : %.2f\n", price);
    printf("Tendered amount : %.2f\n", tendered);
    printf("Change : %.2f\n\n", change);

    // Convert change to cents
    change_in_cents = (int)(change * 100 + 0.5); // Adding 0.5 for rounding

    // Calculate denomination
    denomination_20 = change_in_cents / 2000;
    change_in_cents %= 2000;

    denomination_10 = change_in_cents / 1000;
    change_in_cents %= 1000;

    denomination_5 = change_in_cents / 500;
    change_in_cents %= 500;

    denomination_1 = change_in_cents / 100;
    change_in_cents %= 100;

    cent_25 = change_in_cents / 25;
    change_in_cents %= 25;

    cent_10 = change_in_cents / 10;
    change_in_cents %= 10;

    cent_5 = change_in_cents / 5;
    change_in_cents %= 5;

    // Display denominations
    printf("Coin Denomination\n");
    printf("20.00 pesos = %d\n", denomination_20);
    printf("10.00 pesos = %d\n", denomination_10);
    printf("5.00 pesos  = %d\n", denomination_5);
    printf("1.00 pesos  = %d\n", denomination_1);
    printf("0.25 cents  = %d\n", cent_25);
    printf("0.10 cents  = %d\n", cent_10);
    printf("0.05 cents  = %d\n", cent_5);

    return 0;
}
