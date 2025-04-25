/**
 * @file singlelinklist.h
 * 
 * @description single link list library
 * 
 * @author - Ali Hussain
 * @date   - 25-04-2025
 * @email  - ali0403hussain@gmail.com
 * 
 * @copyright (c) 2025 Ali Hussain
 */

#ifndef SINGLE_LINK_LIST_H_INCLUDE
#define SINGLE_LINK_LIST_H_INCLUDE

/**********************************************************
 * Includes
 **********************************************************/
#include "types.h"

/**********************************************************
 * Macros
 **********************************************************/
#define HEAD_POSITION         ( 0U )
#define AFTER_HEAD_POSITION   ( 1U )
#define LIST_EMPTY            ( 0U )

/**********************************************************
 * Struct, Enums, and Typedef 
 **********************************************************/
typedef int singleLinkList_type;    //<! Typedef for data type for link list change according to project 

typedef struct SingleLinkList SingleLinkList;   //<! Forward decleration for Single link list

typedef struct Node Node;   //<! Forward decleration for link list Node

/**
 * @brief enum for Single link list status codes
 *  */ 
typedef enum {
    SINGLE_LINKLIST_STATUS_GOOD = 0,
    SINGLE_LINKLIST_STATUS_ERROR = 1,
    SINGLE_LINKLIST_STATUS_ERROR_INSTANCE_INVALID = 2,
    SINGLE_LINKLIST_STATUS_ERROR_ARGUMENT_INVALID = 3,
    SINGLE_LINKLIST_STATUS_ERROR_POSITION_OUT_OF_RANGE = 4,
    SINGLE_LINKLIST_STATUS_ERROR_EMPTY = 5,
    SINGLE_LINKLIST_STATUS_ERROR_MEMORY_ALLOCATION = 6
}SingleLinkListStatusCodes;

/**
 * @brief Struct Node
 */
struct Node{
    singleLinkList_type data;   //<! data in link list
    Node* next; //<! Pointer to next node
};

/**
 * @brief interface for single link list insert at start
 * 
 * @param object pointer to single link list object
 * @param element value to insert
 * 
 * @return @SingleLinkListStatusCodes
 */
typedef SingleLinkListStatusCodes (*SingleLinkListInserAtStart)(SingleLinkList *object, singleLinkList_type element);

/**
 * @brief interface for single link list insert at end
 * 
 * @param object pointer to single link list object
 * @param element value to insert
 * 
 * @return @SingleLinkListStatusCodes
 */
typedef SingleLinkListStatusCodes (*SingleLinkListInserAtEnd)(SingleLinkList *object, singleLinkList_type element);

/**
 * @brief interface for single link list insert at position
 * 
 * @param object pointer to single link list object
 * @param element value to insert
 * @param position index at which element needs to be inserted starting from 0
 * 
 * @return @SingleLinkListStatusCodes
 */
typedef SingleLinkListStatusCodes (*SingleLinkListInserAtPosition)(SingleLinkList *object, singleLinkList_type element, size_t position);

/**
 * @brief interface for single link list delete at start
 * 
 * @param object pointer to single link list object
 * @param element value to insert
 * 
 * @return @SingleLinkListStatusCodes
 */
typedef SingleLinkListStatusCodes (*SingleLinkListDeleteAtStart)(SingleLinkList *object );

/**
 * @brief interface for single link list delete at end
 * 
 * @param object pointer to single link list object
 * 
 * @return @SingleLinkListStatusCodes
 */
typedef SingleLinkListStatusCodes (*SingleLinkListDeleteAtEnd)(SingleLinkList *object );

/**
 * @brief interface for single link list delete at position
 * 
 * @param object pointer to single link list object
 * @param position index at which element needs to be inserted
 * 
 * @return @SingleLinkListStatusCodes
 */
typedef SingleLinkListStatusCodes (*SingleLinkListDeleteAtPosition)(SingleLinkList *object, size_t position);

/**
 * @brief typedef struct for single link list interface
 */
typedef struct {
    SingleLinkListInserAtStart insertAtStart;
    SingleLinkListInserAtEnd insertAtEnd;
    SingleLinkListInserAtPosition insertAtPos;
    SingleLinkListDeleteAtStart deleteAtStart;
    SingleLinkListDeleteAtEnd deleteAtEnd;
    SingleLinkListDeleteAtPosition deleteAtPos;
}SingleLinkListInterface;

struct SingleLinkList {
    Node *head;                             //<! head of link list
    size_t size;                            //<! size of link list
    SingleLinkListInterface interface;      //<! Interfaces for link list
};

/***********************************************************
 * Forward declerations and global variables
 **********************************************************/

/***********************************************************
 * Inline functions
 **********************************************************/

/***********************************************************
 * Functions Declerations
 **********************************************************/
/**
 * @brief function for single link list init
 * 
 * @param object pointer to single link list object
 * 
 * @return @SingleLinkListStatusCodes
 */
SingleLinkListStatusCodes SingleLinkList_init(SingleLinkList *object);

#endif // SINGLE_LINK_LIST_H_INCLUDE
   
   