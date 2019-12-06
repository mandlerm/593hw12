/************************************************************************/
/* File Name : lc4_memory.c		 										*/
/* Purpose   : This file implements the linked_list helper functions	*/
/* 			   to manage the LC4 memory									*/
/*             															*/
/* Author(s) : tjf and you												*/
/************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "lc4_memory.h"


/*
 * adds a new node to the end of a linked list pointed to by head
 */
int add_to_list (row_of_memory** head,
		 short unsigned int address,
		 short unsigned int contents)
{
	/* allocate memory for a single node */
    row_of_memory *newRow = malloc(sizeof(row_of_memory)) ;
    if (newRow == NULL) return -1 ;
    
	/* populate fields in newly allocated node w/ address&contents */

	/* if malloc returns null, return with error code */

// populate note
    newRow->address = address ;
    newRow->contents = contents ;
    newRow->label = NULL ;
    newRow->assembly = NULL ;
    newRow->next = NULL ;
    
    printf("NODE: %x -- %x\n\n", newRow->address, newRow->contents) ;
	/* if head==NULL, node created is the new head of the list! */
    if (*head == NULL) {
        *head = newRow ;
        return 0;
    }
    
    row_of_memory *foundNode;
    foundNode = search_address (*head,newRow->address) ;
    
    // find the right place to put the node
    // if node already exists, update node
    if (foundNode != NULL) {
        foundNode->contents = newRow->contents ; 
        return 0 ;
    }

    int found = 0;
    row_of_memory *rear, *front ;
    rear = front = *head ; 
    
    while(front != NULL) {
        if ((found = (newRow->address < front->address))) {
            rear->next = newRow ;
            newRow->next = front ;
            return 0;
        }
        else {
           rear = front ;
           front = front->next ;
        }
    }
    
    rear->next = newRow ;
    newRow->next = NULL ;
    

	/* otherwise, insert node into the list in address ascending order */

	/* return 0 for success, -1 if malloc fails */
    printf("\n****************\n");
    print_list (head ) ;
    
    printf("\nExiting AddNode\n\n");
    
    return 0;
}


    // ****** . PRINTING OUT ADDRESSES TO CHECK ORDERING
// void testPrint(row_of_memory* head) {}    
//     row_of_memory *front = *head ;
//     do {
//         printf("address %x\n", front->address);
//         front = front->next ;
//     } while(front != NULL) ;
// 	return ;
// }

/*
 * search linked list by address field, returns node if found
 */
row_of_memory* search_address (row_of_memory* head,
			       short unsigned int address )
{
	row_of_memory *front = head ;
    printf("\nlooking for a node\n\n");
    while (front != NULL){
        if (front->address == address) {
            printf("\nReturning: %x\n\n", front); 
            return front;
        }
        
        front=front->next;
    }
    
    /* traverse linked list, searching each node for "address"  */

	/* return pointer to node in the list if item is found */

	/* return NULL if list is empty or if "address" isn't found */

    printf("\nexiting serach node\n\n");
	return NULL ;
}

/*
 * search linked list by opcode field, returns node if found
 */
row_of_memory* search_opcode  (row_of_memory* head,
				      short unsigned int opcode  )
{
	/* traverse linked list until node is found with matching opcode
	   AND "assembly" field of node is empty */

	/* return pointer to node in the list if item is found */

	/* return NULL if list is empty or if no matching nodes */

	return NULL ;
}


void print_list (row_of_memory* head )
{
	/* make sure head isn't NULL */

	/* print out a header */
    printf("Linked List: \n--------------\n");
   
	/* traverse linked list, print contents of each node */
    if (head == NULL) { printf("empty list") ; }
    row_of_memory *front = head ;
    do {
        printf("address: %x -- contents %x -- next: %x\n", front-> address, front->contents, front->next);
        front = front->next ;
    } while(front != NULL) ;
    
	return ;
}

/*
 * delete entire linked list
 */
int delete_list    (row_of_memory** head )
{
	/* delete entire list node by node */
	/* if no errors, set head = NULL upon deletion */
    row_of_memory *front = *head ;
    if (head==NULL) {
        free(head);
        return 0;
    }
    
    do {
        front = *head ;
        do { 
            printf("%x: \n", front->contents) ;
            front = front->next ;
        } while(front != NULL);
        free(front);
    } while((*head)->next != NULL) ;
    free(head);
    head = NULL ;
    
	/* return 0 if no error, -1 for any errors that may arise */
	return 0 ;
}
