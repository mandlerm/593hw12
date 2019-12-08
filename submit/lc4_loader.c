/************************************************************************/
/* File Name : lc4_loader.c		 										*/
/* Purpose   : This file implements the loader (ld) from PennSim		*/
/*             It will be called by main()								*/
/*             															*/
/* Author(s) : tjf and you												*/
/************************************************************************/

#include <stdio.h>
#include "lc4_memory.h"
#include <stdlib.h>

/* declarations of functions that must defined in lc4_loader.c */
int flip_16_bytes(FILE* my_obj_file);

FILE* open_file(char* file_name)
{
    return (fopen (file_name, "rb")) ;
}


int parse_file (FILE* my_obj_file, row_of_memory** memory) {
    
//     printf("&memory: %p\n", &memory) ;
//     printf("memory: %p\n", memory) ;
//     printf("&(*memory): %p\n", &(*memory)) ;  // same value as above
//     printf("%d\n", **memory) ;
//     printf("%x\n", (**memory).next) ;

    
   int header, address, n;
   int i, val ;
     header = flip_16_bytes(my_obj_file) ;
     
    int l;
    for(l=0;l<20;l++) {
        while(header!=EOF) {
            address = flip_16_bytes(my_obj_file) ;
            n = flip_16_bytes(my_obj_file) ;
            
            // code and data
            if(header == 0xdada || header == 0xcade) {
                for(i=0; i<n; i++){
                  val =   flip_16_bytes(my_obj_file) ;
                  add_to_list(memory, (address +i), val) ;  
                }
            }
            // symbol
            else if (header == 0xc3b7) {
                row_of_memory* matched_node = search_address(*memory, address) ;
                if (matched_node == NULL) {
                    printf("No match\n") ;
                    
                    //make node
                }
                else {
                    printf("need to update node\n") ;
                    printf("%d characters in the label\n", n);
                    printf("address is %x - %x\n", address, matched_node->address);
                    char *word = malloc(sizeof(char) * (n+1)) ;
                    char *start=word;
                    for(i=0; i<n; i++){
//                       val =   flip_16_bytes(my_obj_file) ;
                       val =   fgetc(my_obj_file) ; 
                       printf("%x --  %c \n", val, val) ; 
                      *word = val ;
//                       printf("%x -- %x -- %c \n", *word, val, val) ;
                      word++ ;
                }
                    *word = '\0' ;
                    printf("%s\n", start);
                    
     
                }
                // search for note with this address
                // if does not exist, create a node...?
                // if does exists, update node
            }
            
            // grab next chunk so I can test for EOF at top of loop
             header = flip_16_bytes(my_obj_file) ;
         }
    }
	return 0 ;
}


// takes in the current file pointer and returns the first
int flip_16_bytes(FILE* my_obj_file) {
   int header1, header2;
   int flipped_header = 0;

   header1 = (fgetc(my_obj_file))  ;
    header2 = (fgetc(my_obj_file))  ;
//    header2 = (fgetc(my_obj_file)<<8);

//     printf("h1: %x -- h2: %x\n", header1, header2) ;
       if(header1==EOF) return -1 ;
        return ((header1<<8) + (header2)) ;
//    return ((header1) + (header2<<8)) ;
}
