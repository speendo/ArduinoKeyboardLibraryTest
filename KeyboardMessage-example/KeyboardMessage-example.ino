//#include "Keyboard.h"
#include "src/Keyboard/src/Keyboard.h"

const int buttonPin = 11;          // input pin for pushbutton
int previousButtonState = HIGH;   // for checking the state of a pushButton
int counter = 0;                  // button push counter
int prevTime = 0;

void setup() {
  // make the pushButton pin an input:
  pinMode(buttonPin, INPUT);
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {
  // read the pushbutton:
  int buttonState = digitalRead(buttonPin);
  // if the button state has changed,
  if ((buttonState != previousButtonState) && (buttonState == HIGH)) {
    prevTime = millis();
    int threshold = 0;
    while (threshold <= 500) {
      int curTime = millis();
      if (curTime - prevTime >= threshold) {
        Keyboard.print("Last Message before ");
        Keyboard.print(curTime - prevTime);
        Keyboard.println(" millis.");
        threshold = threshold+5;
        prevTime = millis();
      }
    }
  }
  // save the current button state for comparison next time:
  previousButtonState = buttonState;
}
