#ifndef HW1_AcsiiArtTool_H
#define HW1_AcsiiArtTool_H

#include <stdio.h>
#include <stdbool.h>
#include "RLEList.h"

/**
* Run Length Encoding List
*
* Implements an RLE list containing a sequence of characters.
*
* The following functions are available:
*   asciiArtRead	                - Calls the given file and compress it with the RLE way.
*   asciiArtPrint                   - Prints the image to the file with the use of a list of type RLEList.
*   asciiArtPrintEncoded            - Prints the image to the file in its compressed shape.
*/



/**
*   asciiArtRead: Calls the given folder and compress it with the RLE way.
*
* @param in_stream - An object of type FILE* that contains the image we want to compress.
* @return
*   A list of type RLEList that contains all the characters in the image.
*/
RLEList asciiArtRead(FILE* in_stream);

/**
*   asciiArtPrint: Prints the image to the file with the use of a list of type RLEList.
*
* @param list - The RLE list that contains the characters of the image.
* @param out_stream - An object of type FILE* to print the image to.
* @return
* 	RLE_LIST_NULL_ARGUMENT if a NULL was sent as one of the parameters
* 	RLE_LIST_OUT_OF_MEMORY if an allocation failed
* 	RLE_LIST_SUCCESS if the character has been inserted successfully
*/
RLEListResult asciiArtPrint(RLEList list, FILE *out_stream);


/**
* asciiArtPrintEncoded: Prints the image to the file in its compressed shape.
* @param list - A list of type RLEList that contains the characters of the image.
* @param out_stream - An object of type FILE* to print the compressed shape to.
* @return
* 	RLE_LIST_NULL_ARGUMENT if a NULL was sent as one of the parameters.
* 	RLE_LIST_SUCCESS if the compressed shape of the image has been printed successfully.
*/
RLEListResult asciiArtPrintEncoded(RLEList list, FILE *out_stream);


#endif // HW1_AcsiiArtTool_H
