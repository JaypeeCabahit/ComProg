#include <stdio.h> 
 
int main() 
{ 
    int num, largest, smallest; 
     
    printf("Enter the first number: "); 
    scanf("%d", &num); 
     
    largest = num; 
    smallest = num; 
     
    while (1) 
    { 
        printf("Enter the next number (enter -9999 to stop): "); 
        scanf("%d", &num); 
         
        if (num == -9999)
            break; 
             
        if (num > largest) 
            largest = num; 
             
        if (num < smallest) 
            smallest = num; 
    } 
     
    printf("The largest number is %d\n", largest); 
    printf("The smallest number is %d\n", smallest); 
     
    return 0; 
} 
