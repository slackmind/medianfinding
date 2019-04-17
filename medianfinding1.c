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
bool timing_mode = false;
int max_value = 100; // default, can be changed
int tests;
int num_smaller;
int num_equal;
int median;
int operations_taken;
int mean_operations;

int i;
int j;
int k;
time_t t;
int counter;

int calculate_median(int numbers[], int values)
{
    printf("\nCalculating the median value..");
    k = ceil(values/2);
    operations_taken = 1;
   
    for ( i = 0; i<values; i++)
    {
        num_smaller = 0;
        num_equal = 0;
        
        for ( j = 0; j<values; j++)
        {
            if ( numbers[j] < numbers[i] )
            {
                num_smaller++;
            }
            else if ( numbers[j] == numbers[i] )
            {
                num_equal++;
            }

            operations_taken++;
            
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
    int array1_size = 1;
    int array2_size = 1;
    int array3_size = 10;
    int array4_size = 10;
    int array5_size = 10;
    int array6_size = 10;
    int array7_size = 100;
    int array8_size = 1000;
    int test_array1[1] =
    {   
        0 
    };
    int test_array2[1] =
    {   
        4 
    };
    int test_array3[10] =
    {   
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4 
    };
    int test_array4[10] =
    {   
        3, 1, 10, 4, 8, 9, 5, 2, 7, 6 
    };
    int test_array5[10] =
    {   
        1, 1, 1, 1, 1, 1, 1, 1, 1, 9 
    };
    int test_array6[10] =
    {   
        9, 9, 9, 9, 9, 9, 9, 9, 9, 1 
    };
    int test_array7[100] = 
    {   
        7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
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
    int test_median;

    printf("\n***********************************************************************");
    printf("\n\n*** Testing the function ***\n");

    printf("\nTest 1:  Array with one element: 0 ");
    test_median = calculate_median(test_array1, array1_size);
    printf("\nOutput (expected):  Median = 0, operations taken = 1. ");
    printf("\nOutput (actual)  :  Median = %d, operations taken = %d.", test_median, operations_taken);

    printf("\n\nTest 2:  Array with one element: 4 ");
    test_median = calculate_median(test_array2, array2_size);
    printf("\nOutput (expected):  Median = 4, operations taken = 1. ");
    printf("\nOutput (actual)  :  Median = %d, operations taken = %d.", test_median, operations_taken);

    printf("\n\nTest 3:  Array with ten identical elements: 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 ");
    test_median = calculate_median(test_array3, array3_size);
    printf("\nOutput (expected):  Median = 4, operations taken = 10. ");
    printf("\nOutput (actual)  :  Median = %d, operations taken = %d.", test_median, operations_taken);

    printf("\n\nTest 4:  Array with ten different elements: 3, 1, 10, 4, 8, 9, 5, 2, 7, 6 ");
    test_median = calculate_median(test_array4, array4_size);
    printf("\nOutput (expected):  Median = 5-6, operations taken = 10-100. ");
    printf("\nOutput (actual)  :  Median = %d, operations taken = %d.", test_median, operations_taken);

    printf("\n\nTest 5:  Array with ten elements: 1, 1, 1, 1, 1, 1, 1, 1, 1, 9 ");
    test_median = calculate_median(test_array5, array5_size);
    printf("\nOutput (expected):  Median = 1, operations taken = 10. ");
    printf("\nOutput (actual)  :  Median = %d, operations taken = %d", test_median, operations_taken);

    printf("\n\nTest 6:  Array with ten elements: 9, 9, 9, 9, 9, 9, 9, 9, 9, 1 ");
    test_median = calculate_median(test_array6, array6_size);
    printf("\nOutput (expected):  Median = 9, operations taken = 10. ");
    printf("\nOutput (actual)  :  Median = %d, operations taken = %d.", test_median, operations_taken);

    printf("\n\nTest 7:  Array with one hundred identical elements: 7..(100 times)..7");
    test_median = calculate_median(test_array7, array7_size);
    printf("\nOutput (expected):  Median = 7, operations taken = 100. ");
    printf("\nOutput (actual)  :  Median = %d, operations taken = %d.", test_median, operations_taken);

    printf("\n\nTest 8:  Array of size 1000 with numbers ranging 0-100 to be populated");
    printf(" by the program's function to generate random arrays.");
    printf("\nThis test should also print the values of the populated array.");
    random_populate(test_array8, array8_size, 100);
    test_median = calculate_median(test_array8, array8_size);
    printf("\nOutput (expected):  Median = 45-55, operations taken = 1000-1000000. ");
    printf("\nOutput (actual)  :  Median = %d, operations taken = %d", test_median, operations_taken);

    printf("\n\nTesting complete.");
    printf("\n***********************************************************************");

}

int calculate_median_timed(int numbers[], int values)
{
    printf("\nCalculating the median value..");
    k = ceil(values/2);
       
    for ( i = 0; i<values; i++)
    {
        num_smaller = 0;
        num_equal = 0;
        
        for ( j = 0; j<values; j++)
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
                printf("\n%d", median);
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
        printf("\nPress 't' to time the algoirthm\nPress 'c' to count operations\nPress 'x' to enter testing mode:  ");
        scanf("%c", &fork_type);
        if ( fork_type == 'x')
        {
            good_answer = true;
            test_mode = true;
            break;

        }
        printf("\nHow many values in the array? (0-999999):  ");
        scanf("%d", &values);
        printf("\nWhat is the range of each particular value? (0-9999):  ");
        scanf("%d", &max_value);
        printf("\nHow many times to run the program? (0-9999):  ");
        scanf("%d", &tests);
        if ( values > 0 && values < 1000000 && tests > 0 && 
            tests < 10001 && max_value > 0 && max_value < 10001
            && (fork_type == 't' || fork_type == 'c' || fork_type == 'x') )
        {
            good_answer = true;
        }
    }

    int numbers[values];
    int record_medians[tests];
    int record_operations[tests];
    
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
            record_operations[counter] = operations_taken; 
        }
        printf("\nOperations taken: ");
        for ( i = 0; i<tests; i++)
        {
            if ( i % 13 == 0 )
            {
                printf("\n");
            }
            printf("%d   ", record_operations[i]);
        }
    }
    if (fork_type == 't')
    {
        timing_mode = true;
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
        printf("\nTo increase timing accuracy, the simulation was run without printing intermediate results.");
        printf("\nTime elapsed in seconds: %f", total_time);
    }

    if (!test_mode && !timing_mode)
    {    
        printf("\nMedians: ");
        for ( i = 0; i<tests; i++)
        {
            mean_operations += record_operations[i];
            if ( i % 13 == 0)
            {
                printf("\n");
            }
            printf("%d   ", record_medians[i]);
        }

        mean_operations = round(mean_operations/tests);
        printf("\n\n%d was the mean of the operations taken after %d tests.", mean_operations, tests); 
    }
    printf("\n\nProgram complete...");
    getchar();

    return 0;
} 
