/**
 * @file main.c
 * 
 * @description Provides examples for PointersStrcut Vs Unions
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
#include <stdint.h>
#include <string.h>

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
 * @brief function for basic struct example
 * 
 * @param void
 * 
 * @return void
 */
void basicStructExample( void );

/**
 * @brief function for basic union example
 * 
 * @param void
 * 
 * @return void
 */
void basicUnionExample( void );


/***********************************************************
 * Function Definations
 **********************************************************/

/**
 * @brief function for basic struct example
 * 
 * @param void
 * 
 * @return void
 */
void basicStructExample( void )
{
    struct Student {
        char name[30];      //<! 30 Bytes
                            //<! 2 Bytes pad
        uint8_t age;        //<! 1 Byte
        char gender[7];     //<! 7 Bytes
        double percentage;  //<! 8 Bytes
    };

    struct Student student; 
    struct Student *ptrStudent = &student;

    // Initializing student struct
    strcpy( ptrStudent->name, "Faizan");
    ptrStudent->age = 33;
    strcpy( ptrStudent->gender, "Male");
    ptrStudent->percentage = 92.467;

    printf("Struct student size = %d \n",        sizeof(student));
    printf("Struct student name = %s \n",        student.name);
    printf("Struct student age = %u \n",         student.age);
    printf("Struct student gender = %s \n",      student.gender);
    printf("Struct student percentage = %lf \n", student.percentage);
}

/**
 * @brief function for basic union example
 * 
 * @param void
 * 
 * @return void
 */
void basicUnionExample( void )
{
    union Student {
        char name[30]; 
        uint8_t age;
        char gender[7];
        double percentage;
    };

    union Student student; 
    union Student *ptrStudent = &student;

    printf("Union student size = %d \n",        sizeof(student));
    strcpy( ptrStudent->name, "Faizan");
    printf("Union student name = %s \n",        student.name);
    ptrStudent->age = 33;
    printf("Union student age = %u \n",         student.age);
    strcpy( ptrStudent->gender, "Male");
    printf("Union student gender = %s \n",      student.gender);
    ptrStudent->percentage = 92.467;
    printf("Union student percentage = %lf \n", student.percentage); 
}


/**
 * Starting (Entry) Point of C program
 * @param -void
 * 
 * @return 0
 */
int main()
{
    printf("Hello World Welcome to learn Struct Vs Unions in C\n");

    printf("################# 1. Basic Struct Example ################\n");
    basicStructExample();

    printf("################# 2. Basic Union Example ################\n");
    basicUnionExample();
    return 0;
}
