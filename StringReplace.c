/*
* FILENAME         : StringReplace.c
* PROBLEM STATEMENT:
* A program for the following string operations
*     a. Read a main String (STR), a Pattern String (PAT) and a Replace String (REP)
*     b. Perform Pattern Matching Operation: Find and Replace all occurrences of PAT in STR with
         REP if PAT exists in STR. Report suitable messages in case PAT does not exist in STR
* ------------------------------------------------------------------------------
* Author      : Prof. Ganesh Pai, P.A.C.E.
* Version     : 2019
* ------------------------------------------------------------------------------
*/

#include <stdio.h>
#define MAX 100

void readString (char src[], char pattern[], char replaceString[]);
int length (char string[]);
int indexOf (char string[], char pattern[], int startIndex);
int replaceAll (char src[], char dest[], char pattern[], char replaceString[]);

int main()
{
    char src[MAX], dest[MAX], pattern[MAX], replaceString[MAX];

    readString(src, pattern, replaceString);
    int count = replaceAll(src, dest, pattern, replaceString);
    if(count == 0)
    {
       printf("Pattern '%s' not found in source string '%s'.\n", pattern, src);
    }
    else
    {
       printf("\n%d match of pattern '%s' found in source string '%s'.", count, pattern, src);
       printf("\nNew String: '%s'\n", dest);
    }

    return 0;
}

//Reads the 3 input strings
void readString(char src[], char pattern[], char replaceString[])
{
    printf("Enter a Source string : ");
    fgets(src, MAX, stdin);
    src[length(src) - 1] = '\0';

    printf("Enter a Pattern string: ");
    fgets(pattern, MAX, stdin);
    pattern[length(pattern) - 1] = '\0';

    printf("Enter a Replace string: ");
    fgets(replaceString, MAX, stdin);
    replaceString[length(replaceString) - 1] = '\0';    
}

//computes string length
int length(char string[])
{
    int length = 0;
    while(string[length++] != '\0');
    return (length - 1);
}

// Returns index if found, -1 otherwise
int indexOf(char string[], char pattern[], int startIndex)
{
    //if reached end of string or length of pattern is 0, return search failed
    if(length(string) == 0 || length(pattern) == 0)
        return -1;
    
    int maxIndex = length(string) - length(pattern);    //search for pattern from startIndex
    for (int i = startIndex; i <= maxIndex; i++)
    {
        int pi = 0;
        //run over matching characters
        for(int si = i; (pattern[pi] != '\0' && pattern[pi] == string[si]); pi++, si++);
        
        if(pattern[pi] == '\0')                         //return match position
            return i;
    }
    
    return -1;                                          //return match failed
}

// Returns count of match if found, 0 otherwise
int replaceAll(char src[], char dest[], char pattern[], char replaceString[])
{
    int matchIndex, si = 0, di = 0, count = 0;
    
    while((matchIndex = indexOf(src, pattern, si)) != -1)   //replace for each occurences of pattern
    {
        count++;                                //increment match counter
        while(si < matchIndex)                  //copy initial char of source to destination string
            dest[di++] = src[si++];
        
        for(int j = 0; replaceString[j] != '\0'; j++)   //copy replace string to destination string
            dest[di++] = replaceString[j];
        
        si += length(pattern);                  //update index of source string
    }
    
    do dest[di++] = src[si];                    //copy remaining chars. of source to destination
    while(src[si++] != '\0');
    
    return count;                               //return number of matching strings
}