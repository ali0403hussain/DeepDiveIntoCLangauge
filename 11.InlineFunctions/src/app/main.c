/**
 * @file main.c
 * 
 * @description Provides examples for Inline Functions
 * 
 * @author - Ali Hussain
 * @date   - 11-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

/**********************************************************
 * Includes
 **********************************************************/

 #include <stdio.h>  //<! Standard c library including printf scanf etc
 #include "commonhelper.h"
 
 
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
    int num1 = 5, num2 =6, num3 =5;

    printf("Max of %d, %d = %d\n", num1, num2, MAX(num1, num2));

    printf("Min of %d, %d = %d\n", num1, num2, MIN(num1, num2));

    printf("Are Equal  %d, %d = %d\n", num1, num2, EQUAL(num1, num2));
    printf("Are Equal  %d, %d = %d\n", num1, num3, EQUAL(num1, num3));

    int value = 5, min =2, max = 6;
    printf("Clamp min-> %d, max-> %d, value-> %d, clamp = %d\n", min, max, value, CLAMP(value, min, max));

    value = -1, min =2, max = 6;
    printf("Clamp min-> %d, max-> %d, value-> %d, clamp = %d\n", min, max, value, CLAMP(value, min, max));

    value = 8, min =2, max = 6;
    printf("Clamp min-> %d, max-> %d, value-> %d, clamp = %d\n", min, max, value, CLAMP(value, min, max));

    value = 8;
    printf("Absoulte value of %d = %d\n", value, ABS(value));

    value = -2;
    printf("Absoulte value of %d = %d\n", value, ABS(value));

    value = 0;
    printf("Absoulte value of %d = %d\n", value, ABS(value));

    value = 0;
    printf("Is even number %d = %d\n", value, ISEVEN(value));

    value = 2;
    printf("Is even number %d = %d\n", value, ISEVEN(value));

    value = 7;
    printf("Is even number %d = %d\n", value, ISEVEN(value));

    value = 0;
    printf("Is odd number %d = %d\n", value, ISODD(value));

    value = 2;
    printf("Is odd number %d = %d\n", value, ISODD(value));

    value = 7;
    printf("Is odd number %d = %d\n", value, ISODD(value));

    value = 7;
    printf("Is Zero number %d = %d\n", value, ISZERO(value));

    value = 0;
    printf("Is Zero number %d = %d\n", value, ISZERO(value));

    return 0;
 }
 