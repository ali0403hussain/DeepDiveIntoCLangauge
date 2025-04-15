/**
 * @file calculator.c
 * 
 * @description Provides interfaces for calculator
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

#include <stdio.h>
#include "calculator.h" 
 
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

/**
 * @brief loc_Calculator_computeSum 
 * 
 * @param num1 1st number for addition
 * @param num2 2nd number for addition
 * @param ptrResult pointer to result
 * 
 * @return @CalculatorStatusCode 0 for Good else some error
 */
static CalculatorStatusCode loc_Calculator_computeSum( int num1, int num2, int *ptrResult ); 

/**
 * @brief loc_Calculator_computeSubtraction 
 * 
 * @param num1 1st number for subtraction
 * @param num2 2nd number for subtraction
 * @param ptrResult pointer to result
 * 
 * @return @CalculatorStatusCode 0 for Good else some error
 */
static CalculatorStatusCode loc_Calculator_computeSubtraction( int num1, int num2, int *ptrResult ); 

/**
 * @brief loc_Calculator_computeProduct
 * 
 * @param num1 1st number for addition
 * @param num2 2nd number for addition
 * @param ptrResult pointer to result
 * 
 * @return @CalculatorStatusCode 0 for Good else some error
 */
static CalculatorStatusCode loc_Calculator_computeProduct( int num1, int num2, int *ptrResult ); 

/**
 * @brief loc_Calculator_computeDivision 
 * 
 * @param num1 1st number for division
 * @param num2 2nd number for division
 * @param ptrResult pointer to result
 * 
 * @return @CalculatorStatusCode 0 for Good else some error
 */
static CalculatorStatusCode loc_Calculator_computeDivision( int num1, int num2, double *ptrResult );


/***********************************************************
 * Function Definations
 **********************************************************/

 /**
 * @brief Calculator_Init 
 * 
 * @param object pointer to Calculator object
 * 
 * @return @CalculatorStatusCode 0 for Good else some error
 */
CalculatorStatusCode Calculator_init( Calculator *object )
{
    CalculatorStatusCode retValue = CALCULATOR_STATUS_GOOD;

    if ( NULL == object )
    {
        retValue = CALCULATOR_STATUS_INSTANCE_INVALID;
    }
    else 
    {
        object->interface.sum = &loc_Calculator_computeSum;
        object->interface.subtraction = &loc_Calculator_computeSubtraction;
        object->interface.product = &loc_Calculator_computeProduct;
        object->interface.div = &loc_Calculator_computeDivision;
    }

    return retValue;
}

/**
 * @brief loc_Calculator_computeSum 
 * 
 * @param num1 1st number for addition
 * @param num2 2nd number for addition
 * @param ptrResult pointer to result
 * 
 * @return @CalculatorStatusCode 0 for Good else some error
 */
CalculatorStatusCode loc_Calculator_computeSum( int num1, int num2, int *ptrResult )
{
    CalculatorStatusCode retValue = CALCULATOR_STATUS_GOOD;

    if ( NULL == ptrResult )
    {
        retValue = CALCULATOR_STATUS_ARGUMENT_INVALID;
    }
    else 
    {
        *ptrResult = ( num1 + num2 );
    }

    return retValue;
}

/**
 * @brief loc_Calculator_computeSubtraction 
 * 
 * @param num1 1st number for subtraction
 * @param num2 2nd number for subtraction
 * @param ptrResult pointer to result
 * 
 * @return @CalculatorStatusCode 0 for Good else some error
 */
CalculatorStatusCode loc_Calculator_computeSubtraction( int num1, int num2, int *ptrResult )
{
    CalculatorStatusCode retValue = CALCULATOR_STATUS_GOOD;

    if ( NULL == ptrResult )
    {
        retValue = CALCULATOR_STATUS_ARGUMENT_INVALID;
    }
    else 
    {
        *ptrResult = ( num1 - num2 );
    }

    return retValue;
}

/**
 * @brief loc_Calculator_computeProduct
 * 
 * @param num1 1st number for addition
 * @param num2 2nd number for addition
 * @param ptrResult pointer to result
 * 
 * @return @CalculatorStatusCode 0 for Good else some error
 */
CalculatorStatusCode loc_Calculator_computeProduct( int num1, int num2, int *ptrResult )
{
    CalculatorStatusCode retValue = CALCULATOR_STATUS_GOOD;

    if ( NULL == ptrResult )
    {
        retValue = CALCULATOR_STATUS_ARGUMENT_INVALID;
    }
    else 
    {
        *ptrResult = ( num1 * num2 );
    }

    return retValue;
}

/**
 * @brief loc_Calculator_computeDivision 
 * 
 * @param num1 1st number for division
 * @param num2 2nd number for division
 * @param ptrResult pointer to result
 * 
 * @return @CalculatorStatusCode 0 for Good else some error
 */
CalculatorStatusCode loc_Calculator_computeDivision( int num1, int num2, double *ptrResult )
{
    CalculatorStatusCode retValue = CALCULATOR_STATUS_GOOD;

    if ( NULL == ptrResult )
    {
        retValue = CALCULATOR_STATUS_ARGUMENT_INVALID;
    }
    else 
    {
        *ptrResult = ( (double)num1 / (double)num2 );
    }

    return retValue;
}