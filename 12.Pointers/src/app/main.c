/**
 * @file main.c
 * 
 * @description Provides examples for Pointers
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
#define ARRAY_SIZE_VEHICLE_NAME  (30u)
/**********************************************************
 * Struct, Enums, and Typedef 
 **********************************************************/
/**
 * @brief enum for vehicle type
 */
 typedef enum {
    VEHICLE_TYPE_CAR = 0,
    VEHICLE_TYPE_TRUCT = 1
}VehicleType;

/**
 * @brief struct for vehicle
 */
 typedef struct {
    char name[ARRAY_SIZE_VEHICLE_NAME];
    uint16_t model;
}Vehicle;

/**
 * @brief struct for my vehicles
 */
typedef struct {
    Vehicle* vehicle;
    uint32_t regNumber;
    VehicleType type;
}MyVehicles;

/***********************************************************
 * Forward declerations and global variables
 **********************************************************/

/***********************************************************
 * Function Prototype
 **********************************************************/

/**
 * @brief Function to give idea of size of different types of pointers 
 * 
 * @param void
 * 
 * @return void
 * */ 
void sizeofDifferentPointers(void); 

/**
 * @brief Function to swap 2 numbers using pointers arthemetic
 * we can also say it function with call by refernce args
 * 
 * @param num1 pointer to num1
 * @param num2 pointer ti num2
 * 
 * @return void
 * */ 
void swapNumbersUsingPtrArthemetic(int *num1, int *num2); 

/**
 * @brief Function to swap 2 numbers using pointers 
 * we can also say it function with call by refernce args
 * 
 * @param num1 pointer to num1
 * @param num2 pointer ti num2
 * 
 * @return void
 * */ 
void swapNumbers(int *num1, int *num2);

/**
 * @brief Function to give idea for basic pointer
 * 
 * @param void
 * 
 * @return void
 * */ 
void basicPointer(void);

/**
 * @brief Function to reverse array
 * 
 * @param ptrArray pointer to an array
 * @param size size of an array
 * 
 * @return void
 * */ 
void arrayReversal(int *ptrArray, size_t size);

/**
 * @brief Function to print array
 * 
 * @param ptrArray pointer to an array
 * @param size size of an array
 * 
 * @return void
 * */ 
void arrayPrint(int *ptrArray, size_t size);

/**
 * @brief function for constant data pointer
 * 
 * @param void
 * 
 * @return void
 */
void constDataPointer(void);

/**
 * @brief function for constant pointer
 * 
 * @param void
 * 
 * @return void
 */
void constPointer(void);

/**
 * @brief function for constant data and constant pointer
 * 
 * @param void
 * 
 * @return void
 */
void constPointerConstData(void);

/**
 * @brief function for pointer arthemetics
 * 
 * @param void
 * 
 * @return void
 */
void pointerArthemetic(void);

/**
 * @brief function for array of pointers
 * 
 * @param void
 * 
 * @return pointer to pointer array
 */
uint8_t** arrayofPointers(void);

/**
 * @brief function returns pointer to an array
 * 
 * @param size size to an array
 * 
 * @return pointer to an array
 */
int* arrayReturn( size_t *ptrSize );

/**
 * @brief function pointer interface to sum 2 values
 * 
 * @param num1 value1 to sum
 * @param num2 value2 to sum
 * 
 * @return sum
 */
int (*sumOf2Numbers)(int num1, int num2 );

/**
 * @brief function to sum 2 values
 * 
 * @param num1 value1 to sum
 * @param num2 value2 to sum
 * 
 * @return sum
 */
static int loc_getSumOf2Numbers(int num1, int num2 );

/**
 * @brief function for struct pointer example
 * 
 * @param void
 * 
 * @return struct pointer
 */
MyVehicles *structPointerExample( void);

/**
 * @brief function for chain of pointers
 * 
 * @param void
 * 
 * @return void
 */
void chainOfPointerExample( void);

/***********************************************************
 * Function Definations
 **********************************************************/

/**
 * @brief Function to give idea of size of different types of pointers 
 * 
 * @param void
 * 
 * @return void
 * */ 
void sizeofDifferentPointers(void)
{
    uint8_t *ptrUint8;
    uint16_t *ptrUint16;
    uint32_t *ptrUint32;

    char *ptrChar;
    unsigned char *ptrUnsignedChar;

    int *ptrInt;

    float *ptrFloat;
    double *prtDouble;

    printf("Size of Ptr uint8_t %d \n", sizeof(ptrUint8));
    printf("Size of Ptr uint16_t%d \n", sizeof(ptrUint16));
    printf("Size of Ptr uint32_t %d \n", sizeof(ptrUint32));
    printf("Size of Ptr char %d \n", sizeof(ptrChar));
    printf("Size of Ptr unsigned char %d \n", sizeof(ptrUnsignedChar));
    printf("Size of Ptr int %d \n", sizeof(ptrInt));
    printf("Size of Ptr float %d \n", sizeof(ptrFloat));
    printf("Size of Ptr double %d \n", sizeof(prtDouble));
} 

/**
 * @brief Function to swap 2 numbers using pointers 
 * we can also say it function with call by refernce args
 * 
 * @param num1 pointer to num1
 * @param num2 pointer ti num2
 * 
 * @return void
 * */ 
void swapNumbers(int *num1, int *num2)
{
    int tempNum = *num1;
    *num1 = *num2;
    *num2 = tempNum;
}

/**
 * @brief Function to swap 2 numbers using pointers arthemetic
 * we can also say it function with call by refernce args
 * 
 * @param num1 pointer to num1
 * @param num2 pointer ti num2
 * 
 * @return void
 * */ 
void swapNumbersUsingPtrArthemetic(int *num1, int *num2)
{
    *num1 = *num1 + *num2;
    *num2 = *num1 - *num2;
    *num1 = *num1 - *num2;
}

/**
 * @brief Function to give idea for basic pointer
 * 
 * @param void
 * 
 * @return void
 * */ 
void basicPointer(void)
{
    int num =1024;
    int *ptrNum =NULL;

    ptrNum = &num;

    printf("Pointer having value %d and having address %p \n",*ptrNum, ptrNum);
}

/**
 * @brief Function to reverse array
 * 
 * @param ptrArray pointer to an array
 * @param size size of an array
 * 
 * @return void
 * */ 
void arrayReversal(int *ptrArray, size_t size)
{
    size_t start = 0;
    size_t end = ( size - 1);

    while ( start < end )
    {
        int tempNum = ptrArray[start];
        ptrArray[start++] = ptrArray[end];
        ptrArray[end--] = tempNum;
    }
}

/**
 * @brief Function to print array
 * 
 * @param ptrArray pointer to an array
 * @param size size of an array
 * 
 * @return void
 * */ 
void arrayPrint(int *ptrArray, size_t size)
{
    size_t alter = 0;
    while ( alter < size )
    {
        printf("%d,",ptrArray[alter++]);
    }
    printf("\n");
}

/**
 * @brief function for constant data pointer
 * 
 * @param void
 * 
 * @return void
 */
void constDataPointer(void)
{
    int num = 3245;
    int num1 = 4567;
    const int *ptrConstData = NULL;

    printf("Constant Data pointer, pointer can be changed but data cant\n");
    ptrConstData = &num;
    printf("Pointing to num: value = %d, address=%p \n", *ptrConstData, ptrConstData);

    ptrConstData = &num1;
    printf("Pointing to num1: value = %d, address=%p \n", *ptrConstData, ptrConstData);

    printf("Changing value is illegal : *ptrConstData = 1234");
}

/**
 * @brief function for constant pointer
 * 
 * @param void
 * 
 * @return void
 */
void constPointer(void)
{
    int num =1234;

    printf("Constant pointer, data can be changed but address cant\n");
    int *const ptrConst = &num;

    printf("Pointing to num: value = %d, address=%p \n", *ptrConst, ptrConst);

    *ptrConst = 3245;
    printf("Pointing to num with update value: value = %d, address=%p \n", *ptrConst, ptrConst);

    //ptrConst = &num2;
}

/**
 * @brief function for constant data and constant pointer
 * 
 * @param void
 * 
 * @return void
 */
void constPointerConstData(void)
{
    int num = 123456;
    const int *const ptrConstData = &num;

    printf("Const data Constant pointer, data and address cant be changed\n");
    
    printf("Pointing to num with value: value = %d, address=%p \n", *ptrConstData, ptrConstData);
}

/**
 * @brief function for pointer arthemetics
 * 
 * @param void
 * 
 * @return void
 */
void pointerArthemetic(void)
{
    uint8_t value = (uint8_t)200;
    uint16_t value1 = 12345;
    uint32_t value2 = 234567;

    uint8_t *ptrUint8 = &value;
    uint16_t *ptrUint16 = &value1;
    uint32_t *ptrUint32 = &value2;

    printf("Uint8_t Pointer:\n");
    printf("Value = %u \n",*ptrUint8);
    printf("Address = %p \n",(void*)ptrUint8);
    ++ptrUint8;
    printf("Address increment = %p \n",(void*)ptrUint8);

    printf("Uint16_t Pointer:\n");
    printf("Value = %u \n",*ptrUint16);
    printf("Address = %p \n",(void*)ptrUint16);
    ++ptrUint16;
    printf("Address increment = %p \n",(void*)ptrUint16);

    printf("Uint32_t Pointer:\n");
    printf("Value = %u \n",*ptrUint32);
    printf("Address = %p \n",(void*)ptrUint32);
    ++ptrUint32;
    printf("Address increment = %p \n",(void*)ptrUint32);
    
}
/**
 * @brief function for array of pointers
 * 
 * @param void
 * 
 * @return pointer to pointer array
 */
uint8_t** arrayofPointers(void)
{
    static uint8_t num1 =12, num2 =13, num3 =14;
    static uint8_t* ptrArray[3];

    ptrArray[0] = &num1;
    ptrArray[1] = &num2;
    ptrArray[2] = &num3;

    return ptrArray;
}

/**
 * @brief function returns pointer to an array
 * 
 * @param size size to an array
 * 
 * @return pointer to an array
 */
int* arrayReturn( size_t *ptrSize )
{
    static int array[5] = {1,2,3,4,5};

    *ptrSize = sizeof(array)/sizeof(int);

    return array;
}

/**
 * @brief function to sum 2 values
 * 
 * @param num1 value1 to sum
 * @param num2 value2 to sum
 * 
 * @return sum
 */
int loc_getSumOf2Numbers(int num1, int num2 )
{
    return num1 + num2;
}

/**
 * @brief function for struct pointer example
 * 
 * @param void
 * 
 * @return struct pointer
 */
MyVehicles *structPointerExample( void)
{
    static Vehicle vehicle;
    static Vehicle *ptrvehicle = &vehicle;

    static MyVehicles myVehicle;
    static MyVehicles *ptrMyVehicle = &myVehicle;

    ptrvehicle->model = 2023;
    strcpy( ptrvehicle->name, "Toyota");

    ptrMyVehicle->regNumber = 1011;
    ptrMyVehicle->type = VEHICLE_TYPE_CAR;
    ptrMyVehicle->vehicle = ptrvehicle;

    return ptrMyVehicle;
}

/**
 * @brief function for chain of pointers
 * 
 * @param void
 * 
 * @return void
 */
void chainOfPointerExample( void)
{
    int value   = 12345;
    int *ptr1   = &value;
    int **ptr2  = &ptr1;
    int ***ptr3 = &ptr2;

    printf("Pointer 3 have address for itself: %p \n", (void*)&ptr3);
    printf("Pointer 3 have address for pointer 2: %p \n", (void*)ptr3);

    printf("Pointer 2 have address for itself: %p \n", (void*)&ptr2);
    printf("Pointer 2 have address for pointer 1: %p \n", (void*)ptr2);

    printf("Pointer 1 have address for itself: %p \n", (void*)&ptr1);
    printf("Pointer 1 have address for value a: %p \n", (void*)ptr1);

    printf("Value have address for itself: %p \n", (void*)&value);
    printf("Value: %d \n", ***ptr3);
}

/**
 * Starting (Entry) Point of C program
 * @param -void
 * 
 * @return 0
 */
int main()
{
printf("Hello World Welcome to learn Pointers in C\n");

printf("############# 1. Size of different Pointers ##################\n");
sizeofDifferentPointers();

printf("############# 2. Swap Numbers ##################\n");
int num1 = 256, num2 = 1024;
printf("Number before swap: Num1 = %d, Num2 = %d \n",num1, num2);
swapNumbers(&num1, &num2);
printf("Number after swap: Num1 = %d, Num2 = %d \n",num1, num2);

printf("############# 3. Swap Numbers using pointer arthemetic ##################\n");
num1 = 222, num2 = 10114;
printf("Number before swap: Num1 = %d, Num2 = %d \n",num1, num2);
swapNumbersUsingPtrArthemetic(&num1, &num2);
printf("Number after swap: Num1 = %d, Num2 = %d \n",num1, num2);

printf("############# 4. Basic Pointer idea ##################\n");
basicPointer();

printf("############# 5. Array Reversal ##################\n");
int arrNum[8] = {1,3,5,7,9,11,13,15};
size_t sizeArray = sizeof(arrNum)/sizeof(int);
arrayPrint(arrNum, sizeArray);
printf("Reverse Array\n");
arrayReversal(arrNum, sizeArray);
arrayPrint(arrNum, sizeArray);

printf("############# 6. Constant Data Pointer ##################\n");
constDataPointer();

printf("############# 7. Constant Pointer ##################\n");
constPointer();

printf("############# 8. Constant data and const Pointer ##################\n");
constPointerConstData();

printf("############# 9. Pointer Arthemetics ##################\n");
pointerArthemetic();

printf("############# 10. Pointers Array ##################\n");
uint8_t **ptrtoArray = arrayofPointers();

printf("Value=%u, MainAddress=%p, IndexAddress=%p \n", **ptrtoArray, ptrtoArray, *ptrtoArray);
ptrtoArray++;
printf("Value=%u, MainAddress=%p, IndexAddress=%p \n", **ptrtoArray, ptrtoArray, *ptrtoArray);
ptrtoArray++;
printf("Value=%u, MainAddress=%p, IndexAddress=%p \n", **ptrtoArray, ptrtoArray, *ptrtoArray);

printf("############# 11. Function that returns an array ##################\n");
size_t size = 0;
int *ptr = arrayReturn( &size );
arrayPrint(ptr, size);

printf("############# 12. Function pointer ##################\n");
sumOf2Numbers = &loc_getSumOf2Numbers;

num1 = 111, num2 = 222;
int result = 0;

result = sumOf2Numbers(num1, num2);
printf("Sum of %d,  %d = %d \n", num1, num2, result);

printf("############# 13. Struct pointer example ##################\n");

MyVehicles *ptrToMyVehicle = NULL;
ptrToMyVehicle = structPointerExample();

printf("My vehicle name = %s \n", ptrToMyVehicle->vehicle->name);
printf("My vehicle model = %u \n", ptrToMyVehicle->vehicle->model);
printf("My vehicle type = %u \n", ptrToMyVehicle->type);
printf("My vehicle Reg Number = %u \n", ptrToMyVehicle->regNumber);

printf("############# 14. Chain of pointers ##################\n");
chainOfPointerExample();

return 0;
}
