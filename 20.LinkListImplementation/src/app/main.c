/**
 * @file main.c
 * 
 * @description Provides examples for LinkList Example
 * 
 * @author - Ali Hussain
 * @date   - 25-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

/**********************************************************
 * Includes
 **********************************************************/

#include <stdio.h>  //<! Standard c library including printf scanf etc
#include "types.h"

#include "singlelinklist.h"

/**********************************************************
 * Macros
 **********************************************************/

/**********************************************************
 * Struct, Enums, and Typedef 
 **********************************************************/

/***********************************************************
 * Forward declerations and global variables
 **********************************************************/
SingleLinkList singleLinkList;
SingleLinkList *ptrSingleLinkList = &singleLinkList;

/***********************************************************
 * Function Prototype
 **********************************************************/
/**
 * @brief function to insert element in single link list at start
 * 
 * @param elementToInsert element to insert
 * 
 * @return void
 */
void singleLinkListInsertAtStart( singleLinkList_type elementToInsert );

/**
 * @brief function to insert element in single link list at end
 * 
 * @param elementToInsert element to insert
 * 
 * @return void
 */
void singleLinkListInsertAtEnd( singleLinkList_type elementToInsert );

/**
 * @brief function to insert element in single link list at position
 * 
 * @param elementToInsert element to insert
 * @param pos position
 * 
 * @return void
 */
void singleLinkListInsertAtPosition( singleLinkList_type elementToInsert, size_t pos );

/**
 * @brief function to delete element in single link list at start
 * 
 * @param void
 * 
 * @return void
 */
void singleLinkListDeleteAtStart( void );

/**
 * @brief function to delete element in single link list at end
 * 
 * @param void
 * 
 * @return void
 */
void singleLinkListDeleteAtEnd( void );

/**
 * @brief function to delete element in single link list at pos
 * 
 * @param pos position
 * 
 * @return void
 */
void singleLinkListDeleteAtPosition( size_t pos);

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
    SingleLinkListStatusCodes eCodeSingleLinkList;

    printf("Hello World Welcome to LinkList example in C\n");

    printf("................................Single LinkList Example...........................\n");

    eCodeSingleLinkList = SingleLinkList_init(ptrSingleLinkList);
    if ( SINGLE_LINKLIST_STATUS_GOOD ==  eCodeSingleLinkList )
    {
        singleLinkListDeleteAtStart();

        singleLinkListDeleteAtEnd();

        singleLinkListDeleteAtPosition(2);

        singleLinkListDeleteAtPosition(0);

        singleLinkList_type elementToInsert = 100;
        singleLinkListInsertAtStart(elementToInsert);

        elementToInsert = 200;
        singleLinkListInsertAtStart(elementToInsert);

        elementToInsert = 300;
        singleLinkListInsertAtStart(elementToInsert);

        elementToInsert = 1000;
        singleLinkListInsertAtEnd(elementToInsert);

        elementToInsert = 2000;
        singleLinkListInsertAtEnd(elementToInsert);

        elementToInsert = 10245;
        singleLinkListInsertAtPosition(elementToInsert, 2);

        singleLinkListDeleteAtStart();

        singleLinkListDeleteAtEnd();

        singleLinkListDeleteAtPosition(2);

        elementToInsert = 22222;
        singleLinkListInsertAtPosition(elementToInsert, 1);

        elementToInsert = 1111111;
        singleLinkListInsertAtPosition(elementToInsert, 0);

        singleLinkListDeleteAtPosition(1);

        singleLinkListDeleteAtPosition(0);
    }
    else
    {
        printf("Error while Single Link List Init Error:%d \n",eCodeSingleLinkList);
    }

    return 0;
}

/**
 * @brief function to insert element in single link list at start
 * 
 * @param elementToInsert element to insert
 * 
 * @return void
 */
void singleLinkListInsertAtStart( singleLinkList_type elementToInsert )
{
    SingleLinkListStatusCodes eCodeSingleLinkList;

    eCodeSingleLinkList = ptrSingleLinkList->interface.insertAtStart(ptrSingleLinkList, elementToInsert);

    if ( SINGLE_LINKLIST_STATUS_GOOD ==  eCodeSingleLinkList )
    {
        printf("Element %d inserted at start: \n",elementToInsert);
    }
    else
    {
        printf("Error while inserting element %d at start Error:%d \n",elementToInsert, eCodeSingleLinkList);
    }
}

/**
 * @brief function to insert element in single link list at end
 * 
 * @param elementToInsert element to insert
 * 
 * @return void
 */
void singleLinkListInsertAtEnd( singleLinkList_type elementToInsert )
{
    SingleLinkListStatusCodes eCodeSingleLinkList;

    eCodeSingleLinkList = ptrSingleLinkList->interface.insertAtEnd(ptrSingleLinkList, elementToInsert);

    if ( SINGLE_LINKLIST_STATUS_GOOD ==  eCodeSingleLinkList )
    {
        printf("Element %d inserted at end: \n",elementToInsert);
    }
    else
    {
        printf("Error while inserting element %d at end Error:%d \n",elementToInsert, eCodeSingleLinkList);
    }
}

/**
 * @brief function to insert element in single link list at position
 * 
 * @param elementToInsert element to insert
 * @param pos position
 * 
 * @return void
 */
void singleLinkListInsertAtPosition( singleLinkList_type elementToInsert, size_t pos )
{
    SingleLinkListStatusCodes eCodeSingleLinkList;

    eCodeSingleLinkList = ptrSingleLinkList->interface.insertAtPos(ptrSingleLinkList, elementToInsert, pos);

    if ( SINGLE_LINKLIST_STATUS_GOOD ==  eCodeSingleLinkList )
    {
        printf("Element %d inserted at Pos %u: \n",elementToInsert, pos);
    }
    else
    {
        printf("Error while inserting element %d at Pos %u Error:%d \n",elementToInsert, pos, eCodeSingleLinkList);
    }
}

/**
 * @brief function to delete element in single link list at start
 * 
 * @param void
 * 
 * @return void
 */
void singleLinkListDeleteAtStart( void )
{
    SingleLinkListStatusCodes eCodeSingleLinkList;

    eCodeSingleLinkList = ptrSingleLinkList->interface.deleteAtStart(ptrSingleLinkList);

    if ( SINGLE_LINKLIST_STATUS_GOOD ==  eCodeSingleLinkList )
    {
        printf("Element deleted at start: \n");
    }
    else
    {
        printf("Error while deleting element at start Error:%d \n",eCodeSingleLinkList);
    }
}

/**
 * @brief function to delete element in single link list at end
 * 
 * @param void
 * 
 * @return void
 */
void singleLinkListDeleteAtEnd( void )
{
    SingleLinkListStatusCodes eCodeSingleLinkList;

    eCodeSingleLinkList = ptrSingleLinkList->interface.deleteAtEnd(ptrSingleLinkList);

    if ( SINGLE_LINKLIST_STATUS_GOOD ==  eCodeSingleLinkList )
    {
        printf("Element deleted at End: \n");
    }
    else
    {
        printf("Error while deleting element at start Error:%d \n",eCodeSingleLinkList);
    }
}

/**
 * @brief function to delete element in single link list at pos
 * 
 * @param pos position
 * 
 * @return void
 */
void singleLinkListDeleteAtPosition( size_t pos)
{
    SingleLinkListStatusCodes eCodeSingleLinkList;

    eCodeSingleLinkList = ptrSingleLinkList->interface.deleteAtPos(ptrSingleLinkList, pos);

    if ( SINGLE_LINKLIST_STATUS_GOOD ==  eCodeSingleLinkList )
    {
        printf("Element deleted at pos %u: \n", pos);
    }
    else
    {
        printf("Error while deleting element at pos %u Error:%d \n",pos, eCodeSingleLinkList);
    }
}