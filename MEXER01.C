#include <stdio.h>
#include <math.h>

int main() {
    int distance;
    double fare = 20.00;

    printf("Enter distance in meters: ");
    scanf("%d", &distance);

    if (distance > 300) {
        int extra_distance = distance - 300;
        int increments = (extra_distance + 199) / 200; // Ceiling division
        fare += increments * 2.00;
        fare -= 2.00; // Apply discount
    }

    printf("P %.2f\n", fare);

    return 0;
}
