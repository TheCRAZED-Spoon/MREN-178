/******************************************************************************
FILENAME:     lab_1_1.ino 
COURSE:       MREN 178
LAB:          1
STUDENT(S):   [STUDENT NAMES AND IDS HERE] 
DATE:         

ATTRIBUTIONS: [LIST ANY EXTERNAL CONTIBUTORS/CONTRIBUTIONS HERE] 

******************************************************************************/
// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to      
const int pin_RS = 8; 
const int pin_EN = 9; 
const int pin_d4 = 4; 
const int pin_d5 = 5; 
const int pin_d6 = 6; 
const int pin_d7 = 7; 
const int pin_BL = 10; 
LiquidCrystal lcd(pin_RS,  pin_EN,  pin_d4,  pin_d5,  pin_d6,  pin_d7);

int display_num;
bool is_held;
int arr[] = {0,0,0,0,0};
bool arr_full = false;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("number:");
  //when starting displayed number should be 100
  display_num = 100;
  //set flag to false
  is_held = false;
}

void loop() {
  
  int button_read;

  //clear lower row and reset cursor
  lcd.setCursor(1,1);

  //read button inputs
  button_read = analogRead (0);

  //if right button
  if (button_read < 60 && !is_held) {
    display_num++;
    is_held = true;
  }
  //up button
  else if (button_read < 200 && !is_held) {
    display_num += 10;
    is_held = true;
  }
  //down button
  else if (button_read < 400 && !is_held){
    display_num -= 10;
    is_held = true;
  }
  //left button
  else if (button_read < 600 && !is_held){
    display_num--;
    is_held = true;
  }
  // select button
  else if (button_read < 800 && !is_held){
    arr_full = append(display_num);
    is_held = true;
  }
  // no button pressed
  else if (button_read > 1020){
    //enable the pressing of other buttons
    is_held = false;
  }

  if (!arr_full) {
    //display the number
    lcd.print(display_num);
    //clear any leftover text from prior calls of print
    lcd.print("          ");
    for (int i = 0; i < 5; i++){
      Serial.print(arr[i]);
      Serial.print(" ");
    }
    Serial.print("\t\t");
    Serial.println(button_read); // for debug purposes
  }
  else {
    Serial.println("Array is full.");
    lcd.print("Array is full           ");
  }
  
}

bool append(int num) {
  for (int i = 0; i < 5; i++) {
    if (arr[i] == 0) {
      arr[i] = num;
      if (i == 4) {
          return true;
      }
      return false;
    } 
    if (i == 4) {
        return true;
    }
  }
  return false;
}
