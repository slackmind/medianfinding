/*      This program returns the median value in a given array of (100) numbers
        the median value is the kth element, where k = n/2 = 50 
        when the array is sorted

        Author:  John Young    
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<time.h>

int values;
int max_value = 100;    // default, changed on input
int tests;
int num_smaller;
int num_equal;
int median;
int steps_taken;
int i;
int j;
int k;
time_t t;
int counter;


int calculate_median(int numbers[], int values)
{
    printf("\nCalculating the median value..");
    k = ceil(values/2);
    steps_taken = 0;
   
    for ( i = 0; i<values-1; i++)
    {
        num_smaller = 0;
        num_equal = 0;
        
        for ( j = 0; j<values-1; j++)
        {
            if ( numbers[j] < numbers[i] )
            {
                num_smaller++;
            }
            else if ( numbers[j] == numbers[i] )
            {
                num_equal++;
            }

            steps_taken++;
            
        }
        if ( num_smaller < k && 
            k <= num_smaller + num_equal )
        {
                median = numbers[i];
                return median;            
        }
    }
    return 0;
}

void random_populate(int numbers[], int values, int max_value)
{
    printf("Populating the array with random numbers..");
        for ( i = 0; i<values;i++ )
        {
            numbers[i] = rand()%max_value;
            if ( i % 42 == 0 )    //  makes the numbers better formatted
            {
                printf("\n");
            }
            printf("%d ", numbers[i]);
            if (numbers[i] < 10)        // evens out spacing
            {
                printf(" ");
            }
            if (numbers[i] < 100)       // evens out spacing
            {
                printf(" ");
            }
        }
}

int main()
{
    srand((unsigned) time(&t));
    bool good_answer = false;
    values = 0;
    while ( !good_answer )
    {
        printf("Welcome to median finding algorithm.  Press enter to continue.");
        getchar();
        printf("\nHow many values in the array? (0-9999):  ");
        scanf("%d", &values);
        printf("\nWhat is the range of each particular value? (0-9999):  ");
        scanf("%d", &max_value);
        printf("\nHow many times to run the program? (0-99):  ");
        scanf("%d", &tests);
        if ( values > 0 && values < 10000 && tests > 0 && 
            tests < 100 && max_value > 0 && max_value < 10000)
        {
            good_answer = true;
        }
    }

    int numbers[values];
    int record_medians[tests];
    int record_steps[tests];

    for (int counter = 0; counter<tests; counter++)
    {
        printf("\nIteration %d.\n", counter+1);
        random_populate(numbers, values, max_value);
        median = calculate_median(numbers, values);
        printf("%d \n", median);
        record_medians[counter] = median;
        record_steps[counter] = steps_taken; 
    }

    printf("\nMedians: ");
    for ( i = 0; i<tests; i++)
    {
        if (i%13 == 0)
        {
            printf("\n");
        }
        printf("%d   ", record_medians[i]);
    }
    printf("\nSteps taken: ");
    for ( i = 0; i<tests; i++)
    {
        if ( i % 13 == 0 )
        {
            printf("\n");
        }
        printf("%d   ", record_steps[i]);
    }
    getchar();
    
    return 0;
} 
