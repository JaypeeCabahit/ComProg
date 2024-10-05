#include <stdio.h>

int main()
{
    int destinationCode, timeCode, duration;
    double cost, totalCost;

    printf("Input the Destination Code (1: American Region, 2: Asian Region, 3: African Region, 4: European Region): ");
    scanf("%d", &destinationCode);
    printf("Input the Time Code (1 for day, 2 for night): ");
    scanf("%d", &timeCode);
    printf("Input the duration of the call in minutes: ");
    scanf("%d", &duration);

    if (timeCode == 1) {
        if (destinationCode == 1) {
            cost = 50.0 / 3;
        } else if (destinationCode == 2) {
            cost = 30.0 / 2;
        } else if (destinationCode == 3) {
            cost = 40.0 / 3;
        } else if (destinationCode == 4) {
            cost = 35.0 / 2;
        } else {
            printf("Invalid destination code.\n");
            return 1;
        }
    } else if (timeCode == 2) {
        if (destinationCode == 1) {
            cost = 45.0 / 3;
        } else if (destinationCode == 2) {
            cost = 27.0 / 2;
        } else if (destinationCode == 3) {
            cost = 36.0 / 3;
        } else if (destinationCode == 4) {
            cost = 30.0 / 2;
        } else {
            printf("Invalid destination code.\n");
            return 1;
        }
    } else {
        printf("Invalid time code.\n");
        return 1;
    }

    totalCost = cost * duration;

    if (destinationCode == 1) {
        printf("You've chosen American region, and you've chosen %s time and the duration you input is %d minutes.\n", timeCode == 1 ? "day" : "night", duration);
    } else if (destinationCode == 2) {
        printf("You've chosen Asian region, and you've chosen %s time and the duration you input is %d minutes.\n", timeCode == 1 ? "day" : "night", duration);
    } else if (destinationCode == 3) {
        printf("You've chosen African region, and you've chosen %s time and the duration you input is %d minutes.\n", timeCode == 1 ? "day" : "night", duration);
    } else if (destinationCode == 4) {
        printf("You've chosen European region, and you've chosen %s time and the duration you input is %d minutes.\n", timeCode == 1 ? "day" : "night", duration);
    }

    printf("So the total charge is: P %.2lf\n", totalCost);

    return 0;
}
