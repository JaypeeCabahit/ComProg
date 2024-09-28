#include <stdio.h>

int main() {
    // Declare variables
    double consumption, excess_consumption, final_bill;
    const double rate_per_kw = 50.00; // Rate per kilowatt-hour for excess consumption
    const double adjustment_tax_rate = 0.085; // Adjustment tax rate of 8.5%
    const double threshold = 25.00; // Threshold before excess consumption

    // Input: total kilowatt-hour consumption
    printf("Enter the total kilowatt-hour consumption: ");
    scanf("%lf", &consumption);

    // Determine excess consumption
    if (consumption > threshold) {
        excess_consumption = consumption - threshold;
    } else {
        excess_consumption = 0;
    }

    // Calculate the final bill
    final_bill = excess_consumption * rate_per_kw;
    final_bill += final_bill * adjustment_tax_rate; // Apply the 8.5% adjustment tax

    // Output: consumption, excess consumption, and final electric bill
    printf("\nTotal Consumption: %.2f kWh", consumption);
    printf("\nExcess Consumption: %.2f kWh", excess_consumption);
    printf("\nFinal Electric Bill: P%.2f\n", final_bill);

    return 0;
}
