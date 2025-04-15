/**
 * @file main.c
 * 
 * @brief Example for implementing standard c functions
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
#include "types.h"
#include "errorstatus.h"

/**********************************************************
 * Macros
 **********************************************************/

/**********************************************************
 * Struct, Enums, and Typedef 
 **********************************************************/
/**
 * @brief Student struct
 */
struct Student {
    char name[30];
    char gender[7];
    uint8_t age;
    double percentage;
};

/***********************************************************
 * Forward declerations and global variables
 **********************************************************/

/***********************************************************
 * Function Prototype
 **********************************************************/

/**
 * @brief copyBytes function (stdc-> memcpy)
 * 
 * @param dest pointer to destination
 * @param src  pointer to source
 * @param size size of bytes to copy
 * 
 * @return @ErrorStatus
 */
ErrorStatus copyBytes( uint8_t *dest, const uint8_t *src, size_t size );

/**
 * @brief fillBytes function 
 * 
 * @param dest pointer to destination
 * @param value  value to fill
 * @param size size of bytes to copy
 * 
 * @return @ErrorStatus
 */
ErrorStatus fillBytes( uint8_t *dest, uint8_t value, size_t size );

/**
 * @brief copyBytes function (stdc-> memcpy)
 * 
 * @param dest pointer to destination
 * @param src  pointer to source
 * @param size size of bytes to copy
 * 
 * @return True in case of equal and false incase of not equal
 */
bool compareBytes( uint8_t *dest, const uint8_t *src, size_t size );

/**
 * @brief stringCopy function (stdc-> strcpy)
 * 
 * @param dest pointer to destination
 * @param src  pointer to source
 * 
 * @return @ErrorStatus
 */
ErrorStatus stringCopy( char *dest, const char *src );

/**
 * @brief stringLength function (stdc-> strlen)
 * 
 * @param ptrSrc pointer to the string
 * @param size pointer to return size of string
 * 
 * @return @ErrorStatus
 */
ErrorStatus strlength( char *ptrSrc, size_t *size );

/**
 * @brief Example function for use of copyBytes
 * 
 * @param void
 * 
 * @return void
 */
void exampleUseCopyBytes( void );

/**
 * @brief Example function for use of fill Bytes
 * 
 * @param void
 * 
 * @return void
 */
void exampleUseFillBytes( void );

/**
 * @brief Example function for use of compare Bytes
 * 
 * @param void
 * 
 * @return void
 */
void exampleUseCompareBytes( void );

/**
 * @brief Example function for use of strLength
 * 
 * @param void
 * 
 * @return void
 */
void exampleUseStrLength( void );

/**
 * @brief Example function for use of endianess
 * 
 * @param void
 * 
 * @return void
 */
void exampleUseEndianess( void );

/***********************************************************
 * Function Definations
 **********************************************************/

/**
 * @brief copyBytes function (stdc-> memcpy)
 * 
 * @param dest pointer to destination
 * @param src  pointer to source
 * @param size size of bytes to copy
 * 
 * @return @ErrorStatus
 */
ErrorStatus copyBytes( uint8_t *dest, const uint8_t *src, size_t size )
{
    ErrorStatus retValue = ERROR_STATUS_GOOD;

    if ( ( NULL == dest ) || ( NULL == src ) || ( 0 == size ) )
    {
        retValue = ERROR_STATUS_ARGUMENT_INVALID;
    }
    else
    {

        while ( 0 < size )
        {
            *dest = *src;

            dest++;
            src++;

            size--;
        }
    }

    return retValue;
} 

/**
 * @brief fillBytes function 
 * 
 * @param dest pointer to destination
 * @param value  value to fill
 * @param size size of bytes to copy
 * 
 * @return @ErrorStatus
 */
ErrorStatus fillBytes( uint8_t *dest, uint8_t value, size_t size )
{
    ErrorStatus retValue = ERROR_STATUS_GOOD;

    if ( ( NULL == dest ) || ( 0 == size ) )
    {
        retValue = ERROR_STATUS_ARGUMENT_INVALID;
    }
    else
    {
        while( 0 < size )
        {
            *dest = value;
            dest++;
            size--;
        }
    }

    return retValue;
}

/**
 * @brief copyBytes function (stdc-> memcpy)
 * 
 * @param dest pointer to destination
 * @param src  pointer to source
 * @param size size of bytes to copy
 * 
 * @return True in case of equal and false incase of not equal
 */
bool compareBytes( uint8_t *dest, const uint8_t *src, size_t size )
{
    bool retValue = True;

    while( 0 < size )
    {
        if ( *dest != *src )
        {
            retValue = False;
            break;
        }
        else
        {
            dest++;
            src++;
            size--;
        }
    }
    return retValue;
}

/**
 * @brief stringCopy function (stdc-> strcpy)
 * 
 * @param dest pointer to destination
 * @param src  pointer to source
 * 
 * @return @ErrorStatus
 */
ErrorStatus stringCopy( char *dest, const char *src )
{
    ErrorStatus retValue = ERROR_STATUS_GOOD;

    if ( ( NULL == dest ) || ( NULL == src ) )
    {
        retValue = ERROR_STATUS_ARGUMENT_INVALID;
    }
    else
    {
        while ( '\0' != *src)
        {
            *dest = *src;

            dest++;
            src++;
        }
        
        *dest = '\0';
    }

    return retValue;
}

/**
 * @brief stringLength function (stdc-> strlen)
 * 
 * @param ptrSrc pointer to the string
 * @param size pointer to return size of string
 * 
 * @return @ErrorStatus
 */
ErrorStatus strlength( char *ptrSrc, size_t *size )
{
    ErrorStatus retValue = ERROR_STATUS_GOOD;

    if ( ( NULL == ptrSrc ) || ( NULL == size ) )
    {
        retValue = ERROR_STATUS_ARGUMENT_INVALID;
    }
    else
    {
        *size = 0;

        while ( '\0' != *ptrSrc )
        {
            (*size)++;
            ptrSrc++;
        }
    }

    return retValue;
}

/**
 * @brief Example function for use of copyBytes
 * 
 * @param void
 * 
 * @return void
 */
void exampleUseCopyBytes( void )
{
    struct Student student1, student2;

    struct Student *ptrStudent1 = &student1, *ptrStudent2 = &student2;

    if ( ERROR_STATUS_GOOD ==  stringCopy( ptrStudent1->name, "Hamza") )
    {
        if ( ERROR_STATUS_GOOD ==  stringCopy( ptrStudent1->gender, "Male") )
        {
            ptrStudent1->age = 30;
            ptrStudent1->percentage = 92.456;
        }
        else
        {
            printf("Error while copying string\n");
        }
    }
    else
    {
        printf("Error while copying string\n");
    }

    printf("Student 1 Name : %s \n",        ptrStudent1->name );
    printf("Student 1 Gender : %s \n",      ptrStudent1->gender );
    printf("Student 1 Age : %u \n",         ptrStudent1->age );
    printf("Student 1 Percentage : %lf \n", ptrStudent1->percentage );

    if ( ERROR_STATUS_GOOD ==  copyBytes( (uint8_t*)ptrStudent2, (uint8_t*)ptrStudent1, sizeof(student1) ) )
    {
        printf("Student 2 Name : %s \n",        ptrStudent2->name );
        printf("Student 2 Gender : %s \n",      ptrStudent2->gender );
        printf("Student 2 Age : %u \n",         ptrStudent2->age );
        printf("Student 2 Percentage : %lf \n", ptrStudent2->percentage );
    }
    else
    {
        printf("Error while copying Bytes\n");
    }
}

/**
 * @brief Example function for use of fill Bytes
 * 
 * @param void
 * 
 * @return void
 */
void exampleUseFillBytes( void )
{
    struct Data {
        uint8_t data[30];
    };

    struct Data data1;
    struct Data *ptrData1 = &data1;

    if ( ERROR_STATUS_GOOD == fillBytes((uint8_t*)ptrData1, 0xFF, sizeof(data1)) )
    {
        for(uint8_t alter =0; alter < 30; alter++)
        {
            printf("Value: %#X \n", ptrData1->data[alter]);
        }
    }
    else
    {
        printf("Error while strlength\n");
    }
}

/**
 * @brief Example function for use of compare Bytes
 * 
 * @param void
 * 
 * @return void
 */
void exampleUseCompareBytes( void )
{
    uint8_t payload1[] = { 0xff, 0x0a, 0x01, 0x0d, 0x08, 0xff, 0xef, 0xca, 0x07, 0x5a };
    uint8_t payload2[] = { 0xff, 0x0a, 0x01, 0x0d, 0x08, 0xff, 0xef, 0xca, 0x07, 0x5a };
    uint8_t payload3[] = { 0xff, 0x0a, 0x01, 0x0d, 0x00, 0xff, 0xef, 0xca, 0x07, 0x5a };

    bool status;
    size_t size = sizeof(payload2)/sizeof(uint8_t);

    status = compareBytes( payload1, payload2, size);
    printf("payload1 and payload2 are equal = %zu\n", status);

    status = compareBytes( payload1, payload3, size);
    printf("payload1 and payload3 are equal = %zu\n", status);

    status = compareBytes( payload2, payload3, size);
    printf("payload2 and payload3 are equal = %zu\n", status);
}

/**
 * @brief Example function for use of strLength
 * 
 * @param void
 * 
 * @return void
 */
void exampleUseStrLength( void )
{
    char name[] = "Hamza";
    char sentence[] = "My name is Hamza. I am 30 years old. I love programming";
    char age[] = "30";

    size_t strSize;

    if ( ERROR_STATUS_GOOD == strlength(name, &strSize) )
    {
        printf("name string length: %zu \n", strSize );
    }
    else
    {
        printf("Error while strlength\n");
    }

    if ( ERROR_STATUS_GOOD == strlength(sentence, &strSize) )
    {
        printf("sentence string length: %zu \n", strSize);
    }
    else
    {
        printf("Error while strlength\n");
    }

    if ( ERROR_STATUS_GOOD == strlength(age, &strSize) )
    {
        printf("age string length: %zu \n", strSize);
    }
    else
    {
        printf("Error while strlength\n");
    }
}


/**
 * Starting (Entry) Point of C program
 * @param -void
 * 
 * @return 0
 */
int main()
{
    printf("Hello World Welcome to learn Implementation of standard c library functions\n");

    printf("1. Example Copy bytes and string copy\n");
    exampleUseCopyBytes();

    printf("2. Example for stringlength function\n");
    exampleUseStrLength();

    printf("3. Example for fillBytes function\n");
    exampleUseFillBytes();

    printf("4. Example for compareBytes function\n");
    exampleUseCompareBytes();

    return 0;
}
