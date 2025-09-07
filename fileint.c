/* PLEASE EDIT THIS FILE */

#include "fileint.h"

#include <stdbool.h>
#include <stdio.h>

bool addFile(char *filename, int *sum) 
{
  /* BEGIN STUDENT ANSWER */

  FILE *fptr; // file pointer
  *sum = 0; // Initialize *sum to zero
  int quantity; // to accumulate the sum

  // Open the file specified by filename for reading
  fptr = fopen(filename, "r");

  // If the file cannot be opened, return false and do not call fclose()
  if (fptr == NULL) 
  {
    return false;
  }

  // int fscanf(FILE *stream, const char *format, ...) <- format for me to use
  while (fscanf(fptr, "%d", &quantity) == 1) 
  {
    *sum = *sum + quantity; // accumulate the sum
  }

  // Close the file using fclose() if it opened successfully + Return true
  fclose(fptr); 

  /* END STUDENT ANSWER */
  return true;
}

bool writeSum(char *filename, int sum) 
{
  /* BEGIN STUDENT ANSWER */

  FILE *fptr; // file pointer
  // Open the file specified by filename for WRITING, so ill use "w" this time
  fptr = fopen(filename, "w");
  // If the file cannot be opened, return false
  if (fptr == NULL) 
  {
    return false;
  }

  fprintf(fptr, "%d", sum);

  // Close the file using fclose() if it opened successfully + Return true
  fclose(fptr); 

  /* END STUDENT ANSWER */
  return true;
}
