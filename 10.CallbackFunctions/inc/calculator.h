/**
 * @file calculator.h
 * 
 * @description calculator library
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

/**********************************************************
 * Macros
 **********************************************************/

#ifndef CALCULATOR_H_INCLUDE
#define CALCULATOR_H_INCLUDE

/**********************************************************
 * Struct, Enums, and Typedef 
 **********************************************************/

/**
 * @brief Calculator status codes enum
 */
typedef enum {
    CALCULATOR_STATUS_GOOD = 0,
    CALCULATOR_STATUS_ERROR = 1,
    CALCULATOR_STATUS_INSTANCE_INVALID = 2,
    CALCULATOR_STATUS_ARGUMENT_INVALID = 3
} CalculatorStatusCode;

/**
 * @brief callback interface for computeSum
 * 
 * @param num1 1st number for addition
 * @param num2 2nd number for addition
 * @param ptrResult pointer to result
 * 
 * @return @CalculatorStatusCode 0 for Good else some error
 */
typedef CalculatorStatusCode (*computeSum) (int num1, int num2, int *ptrResult);

/**
 * @brief callback interface for computeSubtraction
 * 
 * @param num1 1st number for addition
 * @param num2 2nd number for addition
 * @param ptrResult pointer to result
 * 
 * @return @CalculatorStatusCode 0 for Good else some error
 */
typedef CalculatorStatusCode (*computeSubtraction) (int num1, int num2, int *ptrResult);

/**
 * @brief callback interface for computeProduct
 * 
 * @param num1 1st number for addition
 * @param num2 2nd number for addition
 * @param ptrResult pointer to result
 * 
 * @return @CalculatorStatusCode 0 for Good else some error
 */
typedef CalculatorStatusCode (*computeProduct) (int num1, int num2, int *ptrResult);

/**
 * @brief callback interface for computeDivion
 * 
 * @param num1 1st number for addition
 * @param num2 2nd number for addition
 * @param ptrResult pointer to result
 * 
 * @return @CalculatorStatusCode 0 for Good else some error
 */
typedef CalculatorStatusCode (*computeDivion) (int num1, int num2, double *ptrResult);

/**
 * @brief Calculator interface struct
 */
typedef struct {
    computeSum sum;
    computeSubtraction subtraction;
    computeProduct product;
    computeDivion div;
}Calculatorinterface;

/**
 * @brief Calculator main struct
 */
typedef struct {
    Calculatorinterface interface;
} Calculator;

/***********************************************************
 * Forward declerations and global variables
 **********************************************************/

/***********************************************************
 * Function Prototype
 **********************************************************/ 

/**
 * @brief Calculator_Init 
 * 
 * @param object pointer to Calculator object
 * 
 * @return @CalculatorStatusCode 0 for Good else some error
 */
CalculatorStatusCode Calculator_init( Calculator *object );

#endif // CALCULATOR_H_INCLUDE

