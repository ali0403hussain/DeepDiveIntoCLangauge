/**
 * @file main.c
 * 
 * @description Provides examples related to Integer Promotions
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

/**
 * Example one
 * 
 * @param 
 * 
 * @return
 */
void example_One( void );

/**
 * Example Two
 * 
 * @param 
 * 
 * @return
 */
void example_Two( void );



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
    printf("Hello from Integer Promotions Example\n");

    example_One();
    example_Two();

    return 0;
}
 
/**
 * Example one
 * 
 * @param 
 * 
 * @return
 */
void example_One( void )
{
    char a = 251;
    unsigned char b = a;

    printf("a = %c", a);
    printf("\nb = %c", b);

    if (a == b)
        printf("Same\n");
    else
        printf("Not Same\n");
}

/**
 * Example Two
 * 
 * @param 
 * 
 * @return
 */
void example_Two( void )
{
    char a = 'e',   //<! Hex->65, Decimal->101
         b = '2',   //<! Hex->32, Decimal->050
         c = 'M';   //<! Hex->4D, Decimal->077

    char d = (a * b) / c;   //<! ( 0x65 * 0x32 ) / 0x4D = 0x65;
   
    printf("d as int: %d as char: %c \n", d, d);
}