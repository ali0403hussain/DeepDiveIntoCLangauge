/**
 * @file main.c
 * 
 * @description Provides examples for switch statement
 * 
 * @author - Ali Hussain
 * @date   - 06-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

/**********************************************************
 * Includes
 **********************************************************/

#include <stdio.h>  //<! Standard c library including printf scanf etc


/**********************************************************
 * Macros
 **********************************************************/

/**********************************************************
 * Struct, Enums, and Typedef 
 **********************************************************/

/***********************************************************
 * Forward declerations and global variables
 **********************************************************/

/***********************************************************
 * Function Prototype
 **********************************************************/

/***********************************************************
 * Function Definations
 **********************************************************/

/**
 * Starting (Entry) Point of C program
 * @param -void
 * 
 * @return 0
 */
int main()
{
    double num1, num2;
    char op;

    printf("Simple Calculator using Switch Statement\n");

    printf("Enter expression (e.g., 5 + 3): ");
    scanf("%lf %c %lf", &num1, &op, &num2);

    switch ( op )
    {
        case '+':
        printf("Addition of %lf and %lf = %lf \n", num1, num2, ( num1 + num2 ) );
        break;

        case '-':
        printf("Subtraction of %lf and %lf = %lf \n", num1, num2, ( num1 - num2 ) );
        break;

        case '*':
        printf("Multiplication of %lf and %lf = %lf \n", num1, num2, ( num1 * num2 ) );
        break;

        case '/':
        printf("Division of %lf and %lf = %lf \n", num1, num2, ( num1 / num2 ) );
        break;

        default:
        printf("Invalid operation\n");
    }

    return 0;  
}
