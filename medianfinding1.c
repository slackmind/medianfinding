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
#include<sys/time.h>

int values;
char fork_type;
bool test_mode = false;
int max_value = 100; // default, can be changed
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

int array1_size = 1;
int array2_size = 1;
int array3_size = 10;
int array4_size = 10;
int array5_size = 10;
int array6_size = 10;
int array7_size = 100;
int array8_size = 1000;


int test_array1[1] =
{   0 };
int test_array2[1] =
{   4 };
int test_array3[10] =
{   4, 4, 4, 4, 4, 4, 4, 4, 4, 4 };
int test_array4[10] =
{   6, 1, 10, 4, 8, 9, 5, 2, 7, 3 } ;
int test_array5[10] =
{   1, 1, 1, 1, 1, 1, 1, 1, 1, 9 };
int test_array6[10] =
{   9, 9, 9, 9, 9, 9, 9, 9, 9, 1 };
int test_array7[100] = 
{   7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7
};

int test_array8[1000];


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

void random_populate_timed(int numbers[], int values, int max_value)
{
    printf("\nPopulating the array with random numbers..");
    for ( i = 0; i<values; i++)
    {
        numbers[i] = rand()%max_value;
    }
}

void random_populate(int numbers[], int values, int max_value)
{
    printf("Populating the array with random numbers..");
        for ( i = 0; i<values;i++ )
        {
            numbers[i] = rand()%max_value;
            if ( i % 23 == 0 )    //  makes the numbers better formatted
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


void implement_testing()
{
    int test_median;
    printf("********************************");
    printf("\n\n*** Testing the function ***\n");

    printf("\nTest 1:  Array with one element: 0 ");
    test_median = calculate_median(test_array1, array1_size);
    printf("\nOutput:  Median = %d, steps taken = %d", test_median, steps_taken);

    printf("\n\nTest 2:  Array with one element: 4 ");
    test_median = calculate_median(test_array2, array2_size);
    printf("\nOutput:  Median = %d, steps taken = %d", test_median, steps_taken);

    printf("\n\nTest 3:  Array with ten identical elements: 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 ");
    test_median = calculate_median(test_array3, array3_size);
    printf("\nOutput:  Median = %d, steps taken = %d", test_median, steps_taken);

    printf("\n\nTest 4:  Array with ten different elements: 6, 1, 10, 4, 8, 9, 5, 2, 7, 3 ");
    test_median = calculate_median(test_array4, array4_size);
    printf("\nOutput:  Median = %d, steps taken = %d", test_median, steps_taken);

    printf("\n\nTest 5:  Array with ten elements: 1, 1, 1, 1, 1, 1, 1, 1, 1, 9 ");
    test_median = calculate_median(test_array5, array5_size);
    printf("\nOutput:  Median = %d, steps taken = %d", test_median, steps_taken);

    printf("\n\nTest 6:  Array with ten elements: 9, 9, 9, 9, 9, 9, 9, 9, 9, 1 ");
    test_median = calculate_median(test_array6, array6_size);
    printf("\nOutput:  Median = %d, steps taken = %d", test_median, steps_taken);

    printf("\n\nTest 7:  Array with one hundred identical elements: 7..(100 times)..7");
    test_median = calculate_median(test_array7, array7_size);
    printf("\nOutput:  Median = %d, steps taken = %d", test_median, steps_taken);

    printf("\n\nTest 8:  Array of size 1000 with numbers ranging 0-100 to be populated");
    printf(" by the program's function to generate random arrays.");
    printf("\nThis test should also print the values of the populated array.");
    random_populate(test_array8, array8_size, 100);
    test_median = calculate_median(test_array8, array8_size);
    printf("\nOutput:  Median = %d, steps taken = %d", test_median, steps_taken);

    printf("\n\n Testing complete.");
    printf("********************************");

}

int calculate_median_timed(int numbers[], int values)
{
    printf("\nCalculating the median value..");
    k = ceil(values/2);
       
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


int main()
{
    srand((unsigned) time(&t));
    bool good_answer = false;
    values = 0;
    while ( !good_answer )
    {
        printf("\n\n\nWelcome to median finding algorithm.  Press enter to continue.");
        getchar();
        printf("\nPress 't' to time the algoirthm\nPress 'c' to count steps\nPress 'x' to enter testing mode:  ");
        scanf("%c", &fork_type);
        if ( fork_type =='x')
        {
            good_answer = true;
            test_mode = true;
            break;

        }
        printf("\nHow many values in the array? (0-999999):  ");
        scanf("%d", &values);
        printf("\nWhat is the range of each particular value? (0-9999):  ");
        scanf("%d", &max_value);
        printf("\nHow many times to run the program? (0-999):  ");
        scanf("%d", &tests);
        if ( values > 0 && values < 1000000 && tests > 0 && 
            tests < 1000 && max_value > 0 && max_value < 10001
            && (fork_type == 't' || fork_type == 'c' || fork_type == 'x') )
        {
            good_answer = true;
        }
    }

    int numbers[values];
    int record_medians[tests];
    int record_steps[tests];
    
    if (test_mode)
    {
        implement_testing();
    }

    if (fork_type == 'c')
    {
        for (int counter = 0; counter<tests; counter++)
        {
            
            printf("\nIteration %d.\n", counter+1);
            random_populate(numbers, values, max_value);
            median = calculate_median(numbers, values);
            printf("%d \n", median);
            record_medians[counter] = median;
            record_steps[counter] = steps_taken; 
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
    }
    if (fork_type == 't')
    {
        double total_time = 0;
        clock_t start;
        clock_t finish;
        for (int counter = 0; counter<tests; counter++)
        {
            
            random_populate_timed(numbers, values, max_value);
            start = clock();
            median = calculate_median_timed(numbers, values);
            finish = clock();
            total_time += (double)(finish - start) / CLOCKS_PER_SEC;
            record_medians[counter] = median;
        }
        printf("\nTo increase timing accuracy, the simulation was run without printing results.");
        printf("\nTime elapsed in seconds: %f", total_time);
    }
    if (!test_mode)
    {    
        printf("\nMedians: ");
        for ( i = 0; i<tests; i++)
        {
            if (i%13 == 0)
            {
                printf("\n");
            }
            printf("%d   ", record_medians[i]);
        }
        
        printf("\n\n\n\n");
    }
    printf("Press enter to exit...");
    getchar();

    return 0;
} 
