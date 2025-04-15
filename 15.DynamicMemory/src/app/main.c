/**
 * @file main.c
 * 
 * @description Provides examples for Dynamic memory allocation
 *  malloc() method
    The “malloc” or “memory allocation” method in C is used to dynamically
    allocate a single large block of memory with the specified size.
    It returns a pointer of type void which can be cast into a pointer of any
    form. It doesn’t Initialize memory at execution time so that it has
    initialized each block with the default garbage value initially.
    @Syntax : ptr = (cast-type*) malloc(byte-size)
 *
 * calloc() method
    “calloc” or “contiguous allocation” method in C is used to dynamically allocate
    the specified number of blocks of memory of the specified type. it is very much
    similar to malloc() but has two different points and these are:
    - It initializes each block with a default value ‘0’.
    - It has two parameters or arguments as compare to malloc().
    @Syntax : ptr = (cast-type*)calloc(n, element-size);
 * 
 * realloc() method
    “realloc” or “re-allocation” method in C is used to dynamically change the memory
    allocation of a previously allocated memory. In other words, if the memory previously
    allocated with the help of malloc or calloc is insufficient, realloc can be used to
    dynamically re-allocate memory. re-allocation of memory maintains the already present
    value and new blocks will be initialized with the default garbage value.
    @Syntax : ptr = realloc(ptr, newSize);
 * 
 * free() method
    “free” method in C is used to dynamically de-allocate the memory. The memory
    allocated using functions malloc() and calloc() is not de-allocated on their
    own. Hence the free() method is used, whenever the dynamic memory allocation
    takes place. It helps to reduce wastage of memory by freeing it.
    @Syntax : free(ptr);
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
#include <stdlib.h>
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
 * @brief Function for Malloc Example 
 * 
 * @param void
 * 
 * @retun void
 * */
void exampleBasicMalloc(void); 

/**
 * @brief Function for Calloc Example 
 * 
 * @param void
 * 
 * @retun void
 * */
void exampleBasicCalloc(void);

/**
 * @brief Function for Realloc Example 
 * 
 * @param void
 * 
 * @retun void
 * */
void exampleBasicRealloc(void);

/**
 * @brief Function for dynamic memory allocation with multiple pointers
 * 
 * @param void
 * 
 * @retun void
 * */
void exampleMultiDMemoryAlloc(void);

/***********************************************************
 * Function Definations
 **********************************************************/

/**
 * @brief Function for Malloc Example 
 * Create 10 bytes using malloc
 * 
 * @param void
 * 
 * @retun void
 * */
void exampleBasicMalloc(void)
{
    #define MALLOC_SIZE (8U)

    uint8_t arrayPatternToWrite[MALLOC_SIZE] = 
    {
        0x00D,
        0x00E,
        0x00A,
        0x00D,
        0x00B,
        0x00E,
        0x00E,
        0x00F
    };

    uint8_t *ptrDynamicMemory = NULL;

    ptrDynamicMemory = (uint8_t*)malloc( MALLOC_SIZE * sizeof(uint8_t) );

    for(uint8_t alter = 0; alter < MALLOC_SIZE; alter++)
    {
        ptrDynamicMemory[alter] = arrayPatternToWrite[alter];
    }

    for(uint8_t alter = 0; alter < MALLOC_SIZE; alter++)
    {
        printf("Memory address = %p, value = %#X \n", (void*)&ptrDynamicMemory[alter], ptrDynamicMemory[alter]);
    }

    free(ptrDynamicMemory);
    ptrDynamicMemory = NULL;
}

/**
 * @brief Function for Calloc Example 
 * 
 * @param void
 * 
 * @retun void
 * */
void exampleBasicCalloc(void)
{
    #define NUMBER_BLOCKS (3U)

    uint8_t arrayPatternToWrite[] = 
    {
        0x00D,
        0x00E,
        0x00A,
        0x00D,
        0x00B,
        0x00E,
        0x00E,
        0x00F
    };

    size_t patternSize = sizeof(arrayPatternToWrite) / sizeof(uint8_t);

    uint8_t *ptrDynamicMemory = NULL;
    uint8_t *ptrDynamicMemory2ndBank = NULL;
    uint8_t *ptrDynamicMemory3rdBank = NULL;

    ptrDynamicMemory = (uint8_t*)calloc( NUMBER_BLOCKS, ( patternSize*sizeof(uint8_t) ) );

    ptrDynamicMemory2ndBank = ptrDynamicMemory+patternSize;
    ptrDynamicMemory3rdBank = ptrDynamicMemory+ (2 * patternSize);
    //write data to 1st block
    memcpy( ptrDynamicMemory , arrayPatternToWrite, patternSize );

    //write data to 2nd block
    memcpy( ptrDynamicMemory2ndBank , arrayPatternToWrite, patternSize );

    //write data to 3rd block
    memcpy( ptrDynamicMemory3rdBank , arrayPatternToWrite, patternSize );

    for(uint8_t alter = 0; alter < (NUMBER_BLOCKS*patternSize) ; alter++)
    {
        printf("Memory address = %p, value = %#X \n", (void*)&ptrDynamicMemory[alter], ptrDynamicMemory[alter]);
    }

    free(ptrDynamicMemory);
    ptrDynamicMemory = NULL;
    ptrDynamicMemory2ndBank = NULL;
    ptrDynamicMemory3rdBank = NULL;
}

/**
 * @brief Function for Realloc Example 
 * 
 * @param void
 * 
 * @retun void
 * */
void exampleBasicRealloc(void)
{
    #define NUMBER_BLOCKS (3U)
    #define NEW_NUMBER_BLOCKS (2U)

    uint8_t arrayPatternToWrite[] = 
    {
        0x00D,
        0x00E,
        0x00A,
        0x00D,
        0x00B,
        0x00E,
        0x00E,
        0x00F
    };

    size_t patternSize = sizeof(arrayPatternToWrite) / sizeof(uint8_t);

    uint8_t *ptrDynamicMemory = NULL;
    uint8_t *ptrDynamicMemory2ndBank = NULL;
    uint8_t *ptrDynamicMemory3rdBank = NULL;

    ptrDynamicMemory = (uint8_t*)calloc( NUMBER_BLOCKS, ( patternSize*sizeof(uint8_t) ) );

    ptrDynamicMemory2ndBank = ptrDynamicMemory+patternSize;
    ptrDynamicMemory3rdBank = ptrDynamicMemory+ (2 * patternSize);
    //write data to 1st block
    memcpy( ptrDynamicMemory , arrayPatternToWrite, patternSize );

    //write data to 2nd block
    memcpy( ptrDynamicMemory2ndBank , arrayPatternToWrite, patternSize );

    //write data to 3rd block
    memcpy( ptrDynamicMemory3rdBank , arrayPatternToWrite, patternSize );

    for(uint8_t alter = 0; alter < (NUMBER_BLOCKS*patternSize) ; alter++)
    {
        printf("Memory address = %p, value = %#X \n", (void*)&ptrDynamicMemory[alter], ptrDynamicMemory[alter]);
    }

    //Reallocation 
    ptrDynamicMemory = (uint8_t*)realloc( ptrDynamicMemory, NEW_NUMBER_BLOCKS*(patternSize*sizeof(uint8_t)));

    ptrDynamicMemory3rdBank = NULL;
    
    printf("After Realloc-------------------\n");
    for(uint8_t alter = 0; alter < (NUMBER_BLOCKS*patternSize) ; alter++)
    {
        printf("Memory address = %p, value = %#X \n", (void*)&ptrDynamicMemory[alter], ptrDynamicMemory[alter]);
    }

    free(ptrDynamicMemory);
    ptrDynamicMemory = NULL;
    ptrDynamicMemory2ndBank = NULL;
}

/**
 * @brief Function for dynamic memory allocation with multiple pointers
 * Creating memory space for name of different programming langauges
 * array[] = {
 *  "C programming",
 *  "C++ Programming",
 *  "Python Programming",
 *  "Assembly Langauge",
 *  "Rust Programming",
 *  "Java Programming",
 *  "C sharp programming",
 *  "Go programming"
 * }
 * 
 * @param void
 * 
 * @retun void
 * */
void exampleMultiDMemoryAlloc(void)
{
    #define STRING_SIZE  (30U)
    #define NO_OF_ITEMS  (8U)

    char **ptrDynamicMemory = NULL;

    ptrDynamicMemory = (char**)malloc( NO_OF_ITEMS*sizeof(char*) );

    for(uint8_t alter = 0; alter < NO_OF_ITEMS; alter++)
    {
        if ( NULL != ptrDynamicMemory[alter] )
        {
            ptrDynamicMemory[alter] = (char*)malloc(STRING_SIZE*sizeof(char));
        }
        else
        {
            printf("Memory not allocated at index %u\n",alter);
            exit(0);
        }
    }

    char arrayItems[NO_OF_ITEMS][STRING_SIZE] = 
    {
        "C programming",
        "C++ Programming",
        "Python Programming",
        "Assembly Langauge",
        "Rust Programming",
        "Java Programming",
        "C sharp programming",
        "Go programming"
    };

    for (uint8_t alter =0; alter < NO_OF_ITEMS; alter++)
    {
        ptrDynamicMemory[alter] = realloc( ptrDynamicMemory[alter],sizeof(arrayItems[alter])*sizeof(char) );

        memcpy(ptrDynamicMemory[alter], arrayItems[alter], sizeof(arrayItems[alter]));
    }

    for (uint8_t alter =0; alter < NO_OF_ITEMS; alter++)
    {
        printf("Memory address = %p, value = %s \n", ptrDynamicMemory[alter], ptrDynamicMemory[alter]);
    }

    free(ptrDynamicMemory);
    ptrDynamicMemory = NULL;

}

/**
 * Starting (Entry) Point of C program
 * @param -void
 * 
 * @return 0
 */
int main()
{
    printf("Hello World Welcome to learn Dynamic Memory Allocation in C\n");

    printf("1. Basic Malloc Example\n");
    exampleBasicMalloc();

    printf("2. Basic Calloc Example\n");
    exampleBasicCalloc();

    printf("3. Basic Realloc Example\n");
    exampleBasicRealloc();

    printf("4. Multi dimentional memory allocation \n");
    exampleMultiDMemoryAlloc();

    return 0;
}
