/************************************************************************/
/* File Name : lc4.c 													*/
/* Purpose   : This file contains the main() for this project			*/
/*             main() will call the loader and disassembler functions	*/
/*             															*/
/* Author(s) : tjf and you												*/
/************************************************************************/

#include <stdio.h>
#include "lc4_memory.h"
#include "lc4_loader.h"
#include "lc4_disassembler.h"

/* program to mimic pennsim loader and disassemble object files */

int main (int argc, char** argv) {

	/**
	 * main() holds the linked list &
	 * only calls functions in other files
	 */

	/* step 1: create head pointer to linked list: memory 	*/
	row_of_memory* memory = NULL ;


	/* step 2: determine filename, then open it		*/
	/*   TODO: extract filename from argv, pass it to open_file() */
    char *fileName = argv[1] ;
    FILE *my_obj_file ;
    
    if (fileName == NULL) {
        fprintf(stderr, "error1: must enter file name\n");
    }
    else {
        my_obj_file = open_file(fileName) ;
        if (my_obj_file == NULL) {
           fprintf(stderr, "error1: file failed to open\n");
            return 1;
        }    
//         else {
//             printf("File opened\nProcessing to follow\n") ;
//         }
    }
 
	/* step 3: call function: parse_file() in lc4_loader.c 	*/
	/*   TODO: call function & check for errors		*/

//     printf("address of memory: %p\n", &memory);
    parse_file (my_obj_file, &memory) ;

	/* step 4: call function: reverse_assemble() in lc4_disassembler.c */
	/*   TODO: call function & check for errors		*/


	/* step 5: call function: print_list() in lc4_memory.c 	*/
	/*   TODO: call function 				*/
    
    
//     printf("about to print\n\n");
//     print_list (NULL) ;
//     print_list (memory ) ;

	/* step 6: call function: delete_list() in lc4_memory.c */
	/*   TODO: call function & check for errors		*/

        
//         //         printf("about to delete\n\n");
//     delete_list (memory) ;

	/* only return 0 if everything works properly */
    fclose(my_obj_file) ;
	return 0 ;
}
