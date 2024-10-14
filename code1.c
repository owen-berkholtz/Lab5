
/*
FILE: code1.c
TITLE: EECS 348 Lab 6.1 (SALES REPORT)
DESCRIPTION: Program which allows the user to input a file with sales reports for every month of the year 2024.
  Displays the monthly sales report both by month and from highest to lowest sales. Also shows a sales summary report
  and a six-month moving average report.
AUTHOR: Owen Berkholtz
Date: 10/13/2024
Lab: Wed, 1:00 PM

*/

#include <stdio.h>
#include <stdlib.h>

/*
Generates the sales report all months starting at January.

Takes the array of sales for each month as well as another array containing the names of each month. 
Prints one column displaying the month and another displaying the sales for that month.
*/
void sales_report(float sales_data_array[12], char months[][12]) {

    printf("\nMonthly Sales Report for 2024:\nMONTH\t  SALES\n"); //Title display
    //Go over every month in the array containing the months
    for (int month_num = 0; month_num <12; month_num++){

    printf("%s: $%.2f\n", months[month_num], sales_data_array[month_num]); //print out the report for that month

    }
}

/*
Sorts a given array of floats and months from lowest to highest based on sales.

Takes the array of floats to be sorted and the array of months.
Does not return anything, but the given arrays are sorted.
*/
void sort_array(float float_array[], char months[][12]){
  //SORT FLOAT ARRAY
    //Go through every element in the float arraay
    for(int i = 0; i < 11; i++){
      //Compare the number to the next number in the array
      for (int j = 0; j <11; j++){
        //If the number is greater than the number in front of it, then swap them
        if (float_array[j] > float_array[j + 1]) { 

                float store_j = float_array[j]; //Create a temporary varaible to keep track of the current number
                //Do the swap with the greater number
                float_array[j] = float_array[j+ 1];
                float_array[j + 1] = store_j;

              //SORT MONTH ARRAY
                char store_month[12]; // A temporary array to store the month name

                //Go through the months and swap them around by the float they are 'attached to'
                for (int k = 0; k < 12; k++) {
                    store_month[k] = months[j][k]; //store the current month by the index j
                    //Swap month names
                    months[j][k] = months[j+1][k]; 
                    months[j+ 1][k] = store_month[k]; 
                }
            }
        }
    }
}

/*
Gets the average of a bunch of numbers in an array.

Takes the array of floats as well as a starting index and an ending index
Returns the final average
*/
float get_average(float array[], int start, int end) {

    float sum = 0; //Variable which holds the sum of all the values

    //go through every value from the given start to end and add them together
    for (int i = start; i <= end; i++) {
        sum = sum + array[i];
    }
    return sum / (end- start+1);  //return the final sum divided by the end index - (the starting index+1)
}


/*
  Prints out the moving average for six months of the year starting at January-June

  Takes an unsorted float array and the size of the array. Also another array containing the months.
*/

void moving_avg(float array[], int size, char months[][12]){
  printf("\nMOVING AVERAGE\n"); //Display title

    //Display the six-month moving average report. 
    for (int i = 0; i <= (size/2); i++) {
            printf("%s-%s: %.2f\n", months[i], months[i + 5], get_average(array, i, i + 5)); //call get_average

    }
}




/*
Generates a sales summary for the year 2024.

Takes a sorted sales array and the corrsponding month names array.
Prints out the minimum and maximum sales months and the average sales for the whole year.
*/
void sales_summary(float sales_data_array[12], char months[][12]){
  printf("\nSALES SUMMARY REPORT:\n"); //Display title

  printf("Minimum Sales: %.2f (%s)\n", sales_data_array[0], months[0]); //print out the first value in the sorted array
  printf("Maxumum Sales: %.2f (%s)\n", sales_data_array[11], months[11]); //print out the last value in the sorted array
  printf("Average Sales: %.2f \n", get_average(sales_data_array, 0, 11)); //Call get_average to find the average of the whole array

}


/*
Displays another sales report but this time it is sorted from highest sales in a month to lowest

Takes a sorted array of the sales and months array.
Prints out the sales and months column just like the 'sales_report' function above
*/
void high_to_low(float sales_data_array[12], char months[][12]){
    printf("\nSales Report Highest to Lowest:\nMONTH\t  SALES\n"); //Display title
    //Since the given array is sorted from highest to lowest, begin at the final value and print the array in reverse
    for (int month_num = 11; month_num >=0; month_num--){
    printf("%s: $%.2f\n", months[month_num], sales_data_array[month_num]); //prints out one row
    }
}


/*
Main function. Allows the user to enter in the file with the monthly sales data
*/
int main() {
    FILE *user_file; //declare a file pointer
    char user_i[50] = {}; //Variable which will hold the name of the user's desired file
    float data_nums; //Temperary float variable which holds the sales numbers from the file

  //prompts the user to input the name of their file (limits file names size to 49 characters)
    printf("Please enter a file: ");
    scanf("%49s", user_i);
    user_file = fopen(user_i, "r"); //read the file

    //Arrays that will hold sales data and month names
    char months[][12] = {"January", "Febuary", "March", "April", "May", "June", "July",
                           "August", "September", "October", "November", "December"}; //month names array
    float sort_sales_data[12] = {}; //array to hold sales data sorted from lowest sales to highest
    float sales_data[12] = {}; //array to hold unsorted sales data starting at January
    int array_size = 0; //keeps track of the size of the array holding sales data

    //Read the file data until the end of the file and the sales for every month is accounted for
    while (fscanf(user_file, "%f", &data_nums) == 1 && array_size < 12) {
      sort_sales_data[array_size] = data_nums; //Fill the sorted array (it is not sorted yet)
      sales_data[array_size] = data_nums; //Fill the unsorted array
      array_size++; //increment array size
    }

    sort_array(sort_sales_data, months); //sort the sorted array

    //call sales report by month
    printf("===================\n\t1\n===================");
    sales_report(sales_data, months);

    //call sales data
    printf("===================\n\t2\n===================");
    sales_summary(sort_sales_data, months);

    //call moving average
    printf("===================\n\t3\n===================");
    moving_avg(sales_data, array_size, months);

    //call sales report from high to low
    printf("===================\n\t4\n===================");
    high_to_low(sort_sales_data, months);

    fclose(user_file); // Close the file after reading it
    return 0;
}
