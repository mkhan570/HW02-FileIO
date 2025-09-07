/* PLEASE EDIT THIS FILE */

#include "filechar.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

/* BEGIN STUDENT ANSWER HELPER FUNCTIONS */

static inline int char_to_index(char character) 
{
  if (character >= 'A' && character <= 'Z')
  {
    return character - 'A';
  }

  else if (character >= 'a' && character <= 'z')
  {
    return character - 'a';
  }
  return -1;
}

static inline char index_to_char(int index) 
{
  if (index >= 0 && index < ALPHABET_SIZE)
  {
    return (char)('a' + index);
  }
  if (index == ALPHABET_SIZE)
  {
    return ' ';
  }
  return '!';
}

/* END STUDENT ANSWER HELPER FUNCTIONS */

bool countChar(char *filename, int counts[][ALPHABET_SIZE_W_SPACE]) 
{
  int character; // index for character, characters for int by ASCII table
  int firstLetter = 0; // condition prior to first letter
  int startPosition = -1; // for the first letter
  FILE *fptr; // declaring file pointer to manage file to read
  int indexPart2;
  
  fptr = fopen(filename, "r"); // open file (name, r for reading mode)
  // If the file cannot be opened, return false
  if (fptr == NULL) 
  {
    return false;
  }

  // Create a loop where one character is read each iteration
  // fgetc(): Reads a single character from the file
  // EOF = end of file condition from <stdio.h>
  // Hint 2: use fgetc(). Please read the documentation carefully around reaching the end of the file. Documentation can be found by typing man fgetc in your terminal. This method works for all standard library functions!
  while ((character = fgetc(fptr)) != EOF) 
  {
    // If the current character is not alphanumeric ([a-z] or [A-Z]), skip it.
    // isalpha to see if letter "alpha", not operator for case that it is not
    // Hint 3: use isalpha(). Try looking it up in the manual in the same way as the previous hint.
    if (!isalpha((unsigned char)character)) 
    {
      continue;
    }

    indexPart2 = char_to_index((char)character);
    if (indexPart2 < 0)
    {
      continue;
    }
    // If the current alphanumeric character is first in the current pair, store it's value.
    if (firstLetter == 0) 
    {
      startPosition = indexPart2;
      firstLetter = 1;
    }
    // If the current alphanumeric character is second in the current pair, increment the pair in counts[][]
    else 
    {
      // pair of startPosition + indexPart 2, which get incremented in this condition
      counts[startPosition][indexPart2]++;
      // go back to initialized values
      firstLetter = 0;
      startPosition = -1;
    }
  }
  // Stop reading at the end of the file.

  // no partner condition
  if (firstLetter == 1 && startPosition != -1)
  {
    counts[startPosition][ALPHABET_SIZE]++;
  }
  fclose(fptr); // opposite to fopen, when done to relax on memory

  return true;
}

void printCounts(int counts[][ALPHABET_SIZE_W_SPACE]) 
{
  /* BEGIN STUDENT ANSWER */
  // Hint 1: fill out the helper function index_to_char(), and use it! This is an operation you will have to do multiple times so it nice to have the logic separated. <- done prior
  int indexP1 = 0;
  int indexP2;
  int count;
  char character1;
  char character2;
  // Hint 2: You must always know the size an array before iterating through it to avoid an out-of-bounds array access. Luckily, these are defined for you with the object-like macros ALPHABET_SIZE and ALPHABET_SIZE_W_SPACE in filechar.h
  while (indexP1 < ALPHABET_SIZE)
  {
    indexP2 = 0;
    while (indexP2 < ALPHABET_SIZE_W_SPACE)
    {
      count = counts[indexP1][indexP2];
      if (count != 0)
      {
        character1 = index_to_char(indexP1);
        character2 = index_to_char(indexP2);
        printf("%d, %d, %c%c, %d\n", indexP1, indexP2, character1, character2, count);
      }
      indexP2 += 1;
    }
    indexP1 += 1;
  }
}


  /* END STUDENT ANSWER */
