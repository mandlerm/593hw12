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

void testPrint(row_of_memory* head);

/*
 * adds a new node to the end of a linked list pointed to by head
 */
int add_to_list (row_of_memory** head, short unsigned int address, short unsigned int contents) {
	/* allocate memory for a single node */
   
    row_of_memory *newRow = malloc(sizeof(row_of_memory)) ;
    if (newRow == NULL) return -1 ;
    
	/* populate fields in newly allocated node w/ address&contents */

	/* if malloc returns null, return with error code */

// populate note
    newRow->address = address ;
    newRow->contents = contents ;
//     newRow->label = NULL ;
    newRow->assembly = NULL ;
    newRow->next = NULL ;
   
   
	/* if head==NULL, node created is the new head of the list! */
    if (*head == NULL) {
//         printf("FIRSTNODE\n") ;
        *head = newRow ;
        return 0;
    }
    
//     testPrint(head) ;
    
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
    
    if(newRow->address < rear->address) {
        *head = newRow ;
        newRow->next = rear ;
        
        return 0;
    }
    int i=1;
    while(front != NULL) {
        if (newRow->address < front->address) {
            rear->next = newRow ;
            newRow->next = front ;
            return 0;
        }
        else {
           rear = front ;
           front = front->next ;  
        }
        i++ ;
    }

    rear->next = newRow ;
    newRow->next = NULL ;

    return 0;
}


    // ****** . PRINTING OUT ADDRESSES TO CHECK ORDERING
void testPrint(row_of_memory* head) {     
    row_of_memory *front = head ;
    do {
        printf("address: %x -- label: %s -- contents: %x\n", front->address, front->label, front->contents);
        if (front->next == NULL) {
            break ;
        }
        front = front->next ;
    } while(front != NULL) ;
	return ;
}

/*
 * search linked list by address field, returns node if found
 */
row_of_memory* search_address (row_of_memory* head,
			       short unsigned int address )
{
	row_of_memory *front = head ;
    while (front != NULL){
        if (front->address == address) {
            return front;
        }
        front=front->next;
    }  
    /* traverse linked list, searching each node for "address"  */
	/* return pointer to node in the list if item is found */
	/* return NULL if list is empty or if "address" isn't found */

	return NULL ;
}

/*
 * search linked list by opcode field, returns node if found
 */
row_of_memory* search_opcode  (row_of_memory* head, short unsigned int opcode) {
    row_of_memory* ptr = head ;
    if (head == NULL) return 1;
    int op_match;
 
    do {
        if (ptr->assembly == NULL) {
           op_match = retrieve_op(ptr->contents); 
            if (op_match == opcode) {           
                return ptr ;
            }               
        } 
        ptr=ptr->next ;
    } while (ptr != NULL) ;
    
    /* traverse linked list until node is found with matching opcode
	   AND "assembly" field of node is empty */

	/* return pointer to node in the list if item is found */

	/* return NULL if list is empty or if no matching nodes */

	return NULL ;
}

int retrieve_op(short unsigned int op) {
    return (op>>12);
}

void print_list (row_of_memory* head )
{
	/* make sure head isn't NULL */

	/* print out a header */
    printf("Linked List: \n--------------\n");
   
	/* traverse linked list, print contents of each node */
    if (head == NULL) { printf("empty list") ; }
    row_of_memory *front = head ;
    
    printf("<label>\t\t<address>\t<contents>\t<assembly>\n") ;
    
    do {
        if (front->label == NULL){
            printf("\t\t\t\t%x\t\t%x\t\n", front->contents, front->assembly);      
        }
        else {
            printf("%s\t\t%x\t\t%x\t\n", front->label, front->contents, front->assembly);      
        }
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
