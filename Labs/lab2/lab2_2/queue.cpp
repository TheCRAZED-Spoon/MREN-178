#include "HardwareSerial.h"
/******************************************************************************
FILENAME:   queue.cpp 
COURSE:     MREN 178
LAB:        2 

STUDENT:   Spencer Tapp        STUDENT ID: 20512353  
PARTNER:   Owen Reid                       20516094

OTHER CONTRIBUTORS: [AS PART OF ACADEMIC INTEGRITY POLICY, ANY CONTRIBUTIONS
OBTAINED FROM ADDITIONAL SOURCES MUST BE LISTED. THESE INCLUDE WEBSITES, OTHER
STUDENTS, ETC.]
******************************************************************************/

#include "queue.h"

pQueue CreateQueue (void) {
  pQueue pnew = (pQueue)malloc(sizeof (struct queue));
  if (pnew != NULL) {
    pnew->front = NULL;
    pnew->back =  NULL;
    pnew->count = 0;
  }
  return pnew;
}

int CreateQueueArray(pQueue queue_array[], int num_queues){
  for (int i=0; i<num_queues; i++) {
    queue_array[i] = CreateQueue();
    if (queue_array[i] == NULL) {
      //fprintf (stderr, "ERROR: Failed to create queue %d\n", i);
      Serial.print("ERROR: Failed to create queue ");
      Serial.print(i);
      Serial.println(".");
      return EXIT_ERR;
    }
  }
  return EXIT_OK;
}

// Code to create new item and initialize value field
pStampedItem CreateItem (long timestamp) {
	pStampedItem pnew = (pStampedItem) malloc(sizeof(StampedItem));
	if (pnew != NULL)	{
		pnew->timestamp = timestamp;
    pnew->next = NULL;
	} else {
    //fprintf (stderr, "ERROR: Failed to create queue %d\n", i);
    Serial.print("ERROR: Failed to create new item ");
    Serial.print(timestamp);
    Serial.println(".");
  }
	return pnew;
}

bool IsQEmpty (pQueue queue) {
  /*-------------------------insert your code here--------------------------*/
  if (queue->count == 0) return true;
  // this return value may need to be changed once your code is written
  return false;
}

int Enqueue (pQueue queue, pStampedItem item) {
  /*-------------------------insert your code here--------------------------*/
  if(queue->back != NULL) queue->back->next = item;
  else queue->front = item;
  queue->back = item;
  queue->count++;
  Serial.println(queue->count);
  // this return value may need to be changed once your code is written
  return EXIT_OK;
}

int Dequeue (pQueue queue, long &timestamp) {
  /*-------------------------insert your code here--------------------------*/
  if (IsQEmpty(queue)) {
    Serial.println(queue->count);
    return EXIT_FAILURE;  
  }
  timestamp = queue->front->timestamp;
  pStampedItem delete_this = queue->front;
  queue->front = queue->front->next;
  free(delete_this);
  queue->count --;
  // this return value may need to be changed once your code is written
  return EXIT_SUCCESS;
}

int DequeueAll (pQueue queue) {
  /*-------------------------insert your code here--------------------------*/
  long timestamp;
  while (queue->count > 0) {
    Dequeue(queue, timestamp);
  }
  // this return value may need to be changed once your code is written
  return EXIT_SUCCESS; 
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
