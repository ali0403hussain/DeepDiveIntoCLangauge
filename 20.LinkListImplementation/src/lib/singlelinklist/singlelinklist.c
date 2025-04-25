/**
 * @file singlelinklist.c
 * 
 * @description Provides interfaces for single link list
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
#include <stdio.h>
#include <stdlib.h>
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

/***********************************************************
 * Function Prototype
 **********************************************************/

/**
 * @brief function for single link list to create node
 * 
 * @param void
 * 
 * @return pointer to node
 */
static Node* loc_SingleLinkList_createNode(void);

/**
 * @brief function for single link list insert at start
 * 
 * @param object pointer to single link list object
 * @param element value to insert
 * 
 * @return @SingleLinkListStatusCodes
 */
static SingleLinkListStatusCodes loc_SingleLinkList_insertAtStart(SingleLinkList *object, singleLinkList_type element);

/**
 * @brief function for single link list insert at end
 * 
 * @param object pointer to single link list object
 * @param element value to insert
 * 
 * @return @SingleLinkListStatusCodes
 */
static SingleLinkListStatusCodes loc_SingleLinkList_insertAtEnd(SingleLinkList *object, singleLinkList_type element);

/**
 * @brief function for single link list insert at position
 * 
 * @param object pointer to single link list object
 * @param element value to insert
 * @param position index at which element needs to be inserted starting from 0
 * 
 * @return @SingleLinkListStatusCodes
 */
static SingleLinkListStatusCodes loc_SingleLinkList_insertAtPosition(SingleLinkList *object, singleLinkList_type element, size_t position);

/**
 * @brief function for single link list delete at start
 * 
 * @param object pointer to single link list object
 * @param element value to insert
 * 
 * @return @SingleLinkListStatusCodes
 */
static SingleLinkListStatusCodes loc_SingleLinkList_deleteAtStart(SingleLinkList *object );

/**
 * @brief function for single link list delete at end
 * 
 * @param object pointer to single link list object
 * 
 * @return @SingleLinkListStatusCodes
 */
static SingleLinkListStatusCodes loc_SingleLinkList_deleteAtEnd(SingleLinkList *object );

/**
 * @brief function for single link list delete at position
 * 
 * @param object pointer to single link list object
 * @param position index at which element needs to be inserted
 * 
 * @return @SingleLinkListStatusCodes
 */
static SingleLinkListStatusCodes loc_SingleLinkList_deleteAtPosition(SingleLinkList *object, size_t position);

/***********************************************************
 * Function Definations
 **********************************************************/
/**
 * @brief function for single link list init
 * 
 * @param object pointer to single link list object
 * 
 * @return @SingleLinkListStatusCodes
 */
SingleLinkListStatusCodes SingleLinkList_init(SingleLinkList *object)
{
    SingleLinkListStatusCodes retValue = SINGLE_LINKLIST_STATUS_GOOD;

    if ( NULL == object )
    {
        retValue = SINGLE_LINKLIST_STATUS_ERROR_INSTANCE_INVALID;
    }
    else
    {
        object->head =  NULL;
        object->size =  LIST_EMPTY;

        object->interface.insertAtStart = &loc_SingleLinkList_insertAtStart;
        object->interface.insertAtEnd   = &loc_SingleLinkList_insertAtEnd;
        object->interface.insertAtPos   = &loc_SingleLinkList_insertAtPosition;
        object->interface.deleteAtStart = &loc_SingleLinkList_deleteAtStart;
        object->interface.deleteAtEnd   = &loc_SingleLinkList_deleteAtEnd;
        object->interface.deleteAtPos   = &loc_SingleLinkList_deleteAtPosition;
    }

    return retValue;
}

/**
 * @brief function for single link list to create node
 * 
 * @param void
 * 
 * @return pointer to node
 */
Node* loc_SingleLinkList_createNode(void)
{
    Node *ptrNewNode = (Node*)malloc(sizeof(Node));

    return ptrNewNode;
}

/**
 * @brief function for single link list insert at start
 * 
 * @param object pointer to single link list object
 * @param element value to insert
 * 
 * @return @SingleLinkListStatusCodes
 */
SingleLinkListStatusCodes loc_SingleLinkList_insertAtStart(SingleLinkList *object, singleLinkList_type element)
{
    SingleLinkListStatusCodes retValue = SINGLE_LINKLIST_STATUS_GOOD;

    if ( NULL == object )
    {
        retValue = SINGLE_LINKLIST_STATUS_ERROR_INSTANCE_INVALID;
    }
    else
    {
       Node *ptrNewNode = loc_SingleLinkList_createNode();

       if ( NULL != ptrNewNode )
       {
            ptrNewNode->data = element;
            ptrNewNode->next = NULL;
    
            if ( LIST_EMPTY == object->size )
            {
                object->head = ptrNewNode;
            }
            else
            {
                ptrNewNode->next = object->head;
                object->head = ptrNewNode;
            }
 
            object->size++;
       }
       else
       {
            retValue = SINGLE_LINKLIST_STATUS_ERROR_MEMORY_ALLOCATION;
       }
    }

    return retValue;
}

/**
 * @brief function for single link list insert at end
 * 
 * @param object pointer to single link list object
 * @param element value to insert
 * 
 * @return @SingleLinkListStatusCodes
 */
SingleLinkListStatusCodes loc_SingleLinkList_insertAtEnd(SingleLinkList *object, singleLinkList_type element)
{
    SingleLinkListStatusCodes retValue = SINGLE_LINKLIST_STATUS_GOOD;

    if ( NULL == object )
    {
        retValue = SINGLE_LINKLIST_STATUS_ERROR_INSTANCE_INVALID;
    }
    else
    {
        Node *ptrNewNode = loc_SingleLinkList_createNode();

        if ( NULL != ptrNewNode )
        {
            ptrNewNode->data = element;
            ptrNewNode->next = NULL;

            if ( LIST_EMPTY == object->size )
            {
                object->head = ptrNewNode;
            }
            else
            {
                Node *tempNode = object->head;

                while ( NULL  != tempNode->next )
                {
                    tempNode = tempNode->next;
                }

                tempNode->next = ptrNewNode;

                object->size++;
            }
        }
        else
        {
            retValue = SINGLE_LINKLIST_STATUS_ERROR_MEMORY_ALLOCATION;
        }

    }

    return retValue;
}

/**
 * @brief function for single link list insert at position
 * 
 * @param object pointer to single link list object
 * @param element value to insert
 * @param position index at which element needs to be inserted starting from 0
 * 
 * @return @SingleLinkListStatusCodes
 */
SingleLinkListStatusCodes loc_SingleLinkList_insertAtPosition(SingleLinkList *object, singleLinkList_type element, size_t position)
{
    SingleLinkListStatusCodes retValue = SINGLE_LINKLIST_STATUS_GOOD;

    if ( NULL == object )
    {
        retValue = SINGLE_LINKLIST_STATUS_ERROR_INSTANCE_INVALID;
    }

    else if ( position > object->size  )
    {
        retValue = SINGLE_LINKLIST_STATUS_ERROR_POSITION_OUT_OF_RANGE;
    }
    else
    {
        if ( HEAD_POSITION == position )
        {
            retValue = loc_SingleLinkList_insertAtStart( object, element );
        }
        
        else
        {
            Node *ptrNewNode = loc_SingleLinkList_createNode();

            if ( NULL != ptrNewNode )
            {
                ptrNewNode->data = element;
                ptrNewNode->next = NULL;
                
                Node *tempNode = object->head;
    
                if ( AFTER_HEAD_POSITION == position )
                {
                   //Do nothing
                }
                else
                {
                    for( size_t iter = 0; iter < (position - 1); iter++)
                    {
                        tempNode = tempNode->next;
                    }
                }
    
                ptrNewNode->next = tempNode->next;
                tempNode->next = ptrNewNode;

                object->size++;
            }
            else
            {
                retValue = SINGLE_LINKLIST_STATUS_ERROR_MEMORY_ALLOCATION;
            }
        }
    }

    return retValue;
}

/**
 * @brief function for single link list delete at start
 * 
 * @param object pointer to single link list object
 * @param element value to insert
 * 
 * @return @SingleLinkListStatusCodes
 */
SingleLinkListStatusCodes loc_SingleLinkList_deleteAtStart(SingleLinkList *object )
{
    SingleLinkListStatusCodes retValue = SINGLE_LINKLIST_STATUS_GOOD;

    if ( NULL == object )
    {
        retValue = SINGLE_LINKLIST_STATUS_ERROR_INSTANCE_INVALID;
    }
    else
    {
        if ( LIST_EMPTY == object->size )
        {
            retValue = SINGLE_LINKLIST_STATUS_ERROR_EMPTY;
        }
        else
        {
            Node *tempNode = object->head;

            object->head = object->head->next;

            free(tempNode);
            tempNode = NULL;

            object->size--;
        }
    }

    return retValue;
}

/**
 * @brief function for single link list delete at end
 * 
 * @param object pointer to single link list object
 * 
 * @return @SingleLinkListStatusCodes
 */
SingleLinkListStatusCodes loc_SingleLinkList_deleteAtEnd(SingleLinkList *object )
{
    SingleLinkListStatusCodes retValue = SINGLE_LINKLIST_STATUS_GOOD;

    if ( NULL == object )
    {
        retValue = SINGLE_LINKLIST_STATUS_ERROR_INSTANCE_INVALID;
    }
    else
    {
        if ( LIST_EMPTY == object->size )
        {
            retValue = SINGLE_LINKLIST_STATUS_ERROR_EMPTY;
        }
        else
        {
            Node *tempNode = object->head;

            while( NULL != tempNode->next->next )
            {
                tempNode = tempNode->next;
            }

            free(tempNode->next);
            tempNode->next = NULL;

            object->size--;
        }
    }

    return retValue;
}

/**
 * @brief function for single link list delete at position
 * 
 * @param object pointer to single link list object
 * @param position index at which element needs to be inserted
 * 
 * @return @SingleLinkListStatusCodes
 */
SingleLinkListStatusCodes loc_SingleLinkList_deleteAtPosition(SingleLinkList *object, size_t position)
{
    SingleLinkListStatusCodes retValue = SINGLE_LINKLIST_STATUS_GOOD;

    if ( NULL == object )
    {
        retValue = SINGLE_LINKLIST_STATUS_ERROR_INSTANCE_INVALID;
    }
    else if ( ( position > object->size ) || ( ( 0 == object->size ) && ( HEAD_POSITION == position)) )
    {
        retValue = SINGLE_LINKLIST_STATUS_ERROR_POSITION_OUT_OF_RANGE;
    }
    else
    {
        if ( HEAD_POSITION == position )
        {
            retValue = loc_SingleLinkList_deleteAtStart( object );
        }
        else
        {
            Node *tempNode = object->head;

            for( size_t iter = 0; iter < (position - 1); iter++)
            {
                tempNode = tempNode->next;
            }

            Node *nodeToRemove = tempNode->next;
            
            tempNode->next = tempNode->next->next;

            free(nodeToRemove);
            nodeToRemove = NULL;
        }

        object->size--;
    }

    return retValue;
}