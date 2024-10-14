/*
FILE: code2.c
TITLE: EECS 348 Lab 6.2 (MATRIX MANIPULATION)
DESCRIPTION: Program which contains 2 matrices. Can print out a matrix, add, multiply, and transpose matrices.
AUTHOR: Owen Berkholtz
Date: 10/13/2024
Lab: Wed, 1:00 PM

*/



#include <stdio.h>
#include <stdlib.h>
#define SIZE 5 //define a constant size for matrices

/*
Displays a readable matrix for the user

Takes a 2D matrix array
Prints out the matrix
*/
void print_matrix(int matrix[SIZE][SIZE]) {
    printf("====== MATRIX ======\n"); //display title

    //loop over every number in the matrix
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            //if the number is less than 10, make it have a space so that the whole matrix is aligned
            if (matrix[i][j] < 10) {
                printf("[ %d] ", matrix[i][j]);  // Added space for single digits to make it more readable
            } else {
                printf("[%d] ", matrix[i][j]); //print out the number
            }
        }
        printf("\n"); //line break to represent rows
    }
    printf("====================\n");
}

/*
Function that adds together 2 matrices.

Takes 2 matrices to add together as well as an empty matrix which will become the final matrix
Returns nothing, just fills the sum matrix.
*/
void addMatrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE], int sum_matrix[SIZE][SIZE]) {
    //Check if there are proper input parameters
    if (matrix1 == NULL || matrix2 == NULL || sum_matrix == NULL){
        printf("---BAD INPUT---");
        return;
        }
    //Go over every item in both given matrices and add them
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            sum_matrix[row][col] = matrix1[row][col] + matrix2[row][col];} //fill sum matrix
        
    }
}
/*
Function that multiplies together 2 matrices.

Takes 2 matrices to multiply together as well as an empty matrix which will become the final matrix
Returns nothing, just fills the product matrix.
*/
void multMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int prod_matrix[SIZE][SIZE]) {
    //Check if there are proper input parameters
    if (m1 == NULL || m2 == NULL || prod_matrix == NULL){
        printf("---BAD INPUT---");
        return;
    }
    //Go over every item in both given matrices and multiply them
    for (int row= 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            //Do the dot product for the current matrix number
            prod_matrix[row][col] = 0; // Initialize the prod_matrix value to zero
            for (int i = 0; i < SIZE; i++) {
                prod_matrix[row][col] += m1[row][i] * m2[i][col];}


            
        }
    }
}

/*
Function that gets the transpose of a matrix.

Takes a matrix and an empty matrix to be transposed.
Returns nothing, just fills the transposed matrix.
*/
void transposeMatrices(int matrix[SIZE][SIZE], int trans_matrix[SIZE][SIZE]) {
    //Check if there are proper input parameters
    if (matrix == NULL || trans_matrix == NULL){
        printf("---BAD INPUT---");
        return;}

        //Go over every item in the matrix
        for (int row= 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
            trans_matrix[row][col] = matrix[col][row];} //fill the transpose matrix
        }   
    }



int main() {
    //matrix 1
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    //matrix 2
    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    //Print matrix 1
    printf("Matrix 1:\n");
    print_matrix(m1);

    //Print matrix 2
    printf("Matrix 2:\n");
    print_matrix(m2);

    int sum_matrix[SIZE][SIZE];  //Matrix to hold the sum matrix
    addMatrices(m1, m2, sum_matrix); //Fill the product matrix
    printf("\nSum of the matrices:\n");
    print_matrix(sum_matrix); //print out the product matrix

    int product_matrix[SIZE][SIZE];  // Matrix to hold the product matrix
    multMatrices(m1, m2, product_matrix); //Fill the product matrix
    printf("\nProduct of the matrices:\n");
    print_matrix(product_matrix); //print out the product matrix

    int transposed_matrix_1[SIZE][SIZE]; //Transposed matrix no. 1
    transposeMatrices(m1, transposed_matrix_1); //Fill transposed matrix
    printf("\nTransposed Matrix 1:\n");
    print_matrix(transposed_matrix_1); //print out the matrix

    int transposed_matrix_2[SIZE][SIZE]; //Transposed matrix no. 2
    transposeMatrices(m2, transposed_matrix_2); //Fill transposed matrix
    printf("Transposed Matrix 2:\n");
    print_matrix(transposed_matrix_2); //print out the matrix


    return 0;
}
