#include "Arduino.h"
/******************************************************************************
FILENAME:   stack.cpp 
COURSE:     MREN 178
LAB:        2 

STUDENT:   Spencer Tapp         STUDENT ID: 20512353  
PARTNER:   Owen Reid                      : 20516094

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
  if (!IsStackFull(stack)) {
    stack->top ++;
    stack->stack_of_items[stack->top].data = data;
    stack->stack_of_items[stack->top].timestamp = timestamp;
    return EXIT_SUCCESS;
  }
  // this return value will need to be changed once your code is written
  return EXIT_ERR;
}

int Pop(pStack stack, long &timestamp, char &data) {
  
  /*-------------------------insert your code here--------------------------*/
  if (!IsStackEmpty(stack)) {
    timestamp = stack->stack_of_items[stack->top].timestamp;
    data = stack->stack_of_items[stack->top].data;
    stack->top --;
    return EXIT_SUCCESS;
  }
  // this return value will need to be changed once your code is written
  return EXIT_ERR;
}

bool IsStackFull (pStack stack) {
  /*-------------------------insert your code here--------------------------*/
  // this return value will need to be changed once your code is written
  return stack->top == MAX_STACK_LEN-1;
  
}

bool IsStackEmpty (pStack stack) {
  /*-------------------------insert your code here--------------------------*/
  return stack->top==-1;
}

void PopAll(pStack stack) {
  /*-------------------------insert your code here--------------------------*/
  stack->top = -1;
}

long GetTime(DS3231 rtc_clock) {
  /*-------------------------insert your code here--------------------------*/
  long seconds;
  seconds += rtc_clock.getSecond();
  seconds += rtc_clock.getMinute()*60;
  bool h12Flag;
  bool pmFlag;
  byte hours = rtc_clock.getHour(h12Flag, pmFlag);
  if (h12Flag) {
    if (pmFlag) {
      seconds += 12*3600 + 3600*hours;
    }
    else seconds += 3600*hours;
  }
  else seconds += 3600*hours;
  
  // this return value will need to be changed once your code is written
  return seconds;
}
