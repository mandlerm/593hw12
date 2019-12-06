/************************************************************************/
/* File Name : lc4_loader.c		 										*/
/* Purpose   : This file implements the loader (ld) from PennSim		*/
/*             It will be called by main()								*/
/*             															*/
/* Author(s) : tjf and you												*/
/************************************************************************/

#include <stdio.h>
#include "lc4_memory.h"

/* declarations of functions that must defined in lc4_loader.c */
int flip_16_bytes(FILE* my_obj_file);

FILE* open_file(char* file_name)
{
    return (fopen (file_name, "rb")) ;
}



int parse_file (FILE* my_obj_file, row_of_memory** memory) {

   int header, address, n;
   int i, val ;
   
     while(header!=EOF) {
        header = flip_16_bytes(my_obj_file) ;
    
        address = flip_16_bytes(my_obj_file) ;
    
        n = flip_16_bytes(my_obj_file) ;
        printf("N = %x -- should print\n", n) ;
        for(i=0; i<n; i++){
          val =   flip_16_bytes(my_obj_file) ;
            printf("%d\n", i) ;
          add_to_list(memory, (address +i), val) ;  
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
