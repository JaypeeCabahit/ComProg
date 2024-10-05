#include <stdio.h>

int main() {
    int distance;
    double totalFare = 20.00;

    printf("Input the distance traveled in meters: ");
    scanf("%d", &distance);

    if (distance > 300) {
        int remainingDistance = distance - 300;
        int additionalIncrements = (remainingDistance + 199) / 200; // Calculate the number of 200-meter increments
        totalFare += additionalIncrements * 2.00;
        totalFare -= 2.00; // Apply a discount
    }

    printf("Total fare is: P %.2f\n", totalFare);

    return 0;
}
