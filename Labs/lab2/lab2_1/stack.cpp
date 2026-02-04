/******************************************************************************
FILENAME:   stack.cpp 
COURSE:     MREN 178
LAB:        2 

STUDENT:   [YOUR NAME HERE]         STUDENT ID: [YOUR STUDENT ID]  
PARTNER:   [PARTNER's NAME HERE]    

OTHER CONTRIBUTORS: [AS PART OF ACADEMIC INTEGRITY POLICY, ANY CONTRIBUTIONS
OBTAINED FROM ADDITIONAL SOURCES MUST BE LISTED. THESE INCLUDE WEBSITES, OTHER
STUDENTS, ETC.]
******************************************************************************/

#include <stdio.h>
#include "Stack.h"

void CreateStackArray(Stack stack_array[], int num_stacks){
  for (int i=0; i<num_stacks; i++) {
    Stack stack; 
    stack.top = -1; 
    stack_array[i] = stack;
  }
}

int Push(pStack stack, long timestamp, char data) {
  
  /*-------------------------insert your code here--------------------------*/

  // this return value will need to be changed once your code is written
  return EXIT_ERR;
}

int Pop(pStack stack, long &timestamp, char &data) {
  
  /*-------------------------insert your code here--------------------------*/

  // this return value will need to be changed once your code is written
  return EXIT_ERR;
}

bool IsStackFull (pStack stack) {
  /*-------------------------insert your code here--------------------------*/

  // this return value will need to be changed once your code is written
  return false;
}

bool IsStackEmpty (pStack stack) {
  /*-------------------------insert your code here--------------------------*/

}

void PopAll(pStack stack) {
  /*-------------------------insert your code here--------------------------*/

}

long GetTime(DS3231 rtc_clock) {
  /*-------------------------insert your code here--------------------------*/
  
  // this return value will need to be changed once your code is written
  return 0;
}
