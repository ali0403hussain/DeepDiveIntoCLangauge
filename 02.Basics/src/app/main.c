/**
 * @file main.c
 * 
 * @description Provides examples related to basic c program
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

#define PI (3.14159)    //<! Macro for constant value    


/**********************************************************
 * Struct, Enums, and Typedef 
 **********************************************************/

/***********************************************************
 * Forward declerations and global variables
 **********************************************************/

double circleArea = 0.0;    //<! Global ivariable to save area of circle


/***********************************************************
 * Function Prototype
 **********************************************************/

/**
 * Function to compute area of a circle
 * 
 * @param radius - radius of a circle in decimal
 * 
 * @return void
 */
void compute_circleArea( double radius );


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
    double radius = 0.0;    //<!Variable for storing radius from user

    printf("Enter radius of a circle to find area\n");
    scanf("%lf", &radius);

    compute_circleArea( radius );
    printf("Area of circle = %lf \n", circleArea );

    return 0;  
}

/**
 * Function to compute area of a circle
 * 
 * @param radius - radius of a circle in decimal
 * 
 * @return void
 */
void compute_circleArea( double radius )
{
    circleArea = ( PI * (radius * radius ) );
}