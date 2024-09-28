#include <stdio.h>

int main() {
    // Declare variables
    double weekly_sales, commission, gross_pay;
    const double regular_pay = 1000.00; // Fixed weekly pay
    const double commission_rate = 0.097; // Commission rate (9.7%)

    // Input: total weekly sales
    printf("Enter the total weekly sales in pesos: ");
    scanf("%lf", &weekly_sales);

    // Determine commission based on the weekly sales
    if (weekly_sales > 5000.00) {
        // Commission is 9.7% of weekly sales
        commission = weekly_sales * commission_rate;
    } else {
        // Flat commission of 250.00 pesos
        commission = 250.00;
    }

    // Calculate gross pay
    gross_pay = regular_pay + commission;

    // Output: regular pay, weekly sales, commission, and gross pay
    printf("\nRegular Pay: P%.2f", regular_pay);
    printf("\nWeekly Sales: P%.2f", weekly_sales);
    printf("\nWeekly Commission: P%.2f", commission);
    printf("\nWeekly Gross Pay: P%.2f\n", gross_pay);

    return 0;
}
