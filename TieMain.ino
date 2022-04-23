/*
  Interactive Piano Tie-Sam Kingston
  
  Plays piano tones through a buzzer when capacitive keys are touched.
  April 23 2022
  
  
 Based on Code by Created by Tyler Crumpton and Nicholas Jones on 18 May 2013 
*/ 

#include <CapacitiveSensor.h> //INCLUDE TOUCH LIBRARY
#include "pitches.h" //INCLUDE PIEZO FREQUENCY REFERENCE FILE

#define COMMON_PIN      2    // COMMON SEND PIN SHARED BY ALL INPUT PINS
#define BUZZER_PIN      A2   // BUZZER PIN
#define NUM_OF_SAMPLES  20   // NUMBER OF SAMPLES-HIGHER MEANS MORE ACCURATE BUT SLOWER
#define CAP_THRESHOLD   150  // ANALOG NUMBER TO BE REACHED IN ORDER TO TRIGGER PIEZO EVENT
#define NUM_OF_KEYS     12    // NUMBER OF KEYS


#define CS(Y) CapacitiveSensor(2, Y) //MACRO WHICH ALLOWS MULTIPLE PINS TO BE INSERTED INTO Y VALUE


int notes[]={NOTE_C4,NOTE_CS4,NOTE_D4,NOTE_DS4,NOTE_E4,NOTE_F4,NOTE_FS4,NOTE_G4,NOTE_GS4,NOTE_A4,NOTE_AS4,NOTE_B4}; // FULL OCTAVE OF NOTES FROM PITCHES.H

    // Defines the pins that the keys are connected to:
CapacitiveSensor keys[] = {CS(3), CS(4), CS(5), CS(6), CS(7), CS(8), CS(9), CS(10), CS(11), CS(12), CS(13), CS(A0)}; //REFERENCES MACRO-NUMBER IN BRACKET REPRESENTS PIN TO BE USED

void setup() { 
      // TURN OFF AUTO CALIBRATE-CAN LEAD TO UNDESIREABLE TIMEOUTS.
  for(int i=0; i<12; ++i) {
    keys[i].set_CS_AutocaL_Millis(0xFFFFFFFF);
  }
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT); 
}

void loop() {    
  // LOOP THROUGH KEYS 1-12
  for (int i = 0; i < 12; ++i) {
        //IF CAPACITANCE READ BY GIVEN PIN IS HIGHER THAN THE DECLARED THRESHOLD DEFINED IN THE PREAMBLE, PLAY THE PAD'S CORESPONDING FREQUENCY ON THE BUZZER.
    if(keys[i].capacitiveSensor(NUM_OF_SAMPLES) > CAP_THRESHOLD) {
      tone(BUZZER_PIN, notes[i]); // Plays the note corresponding to the key pressed
    }
  }
    //FOLLOWING LINE IS FOR TROUBLESHOOTING. IF THRESHOLD SEEMS TO BE WRONG (PADS TOO SENSITIVE/NOT SENSITIVE ENOUGH) CHECK VALUES IN SERIAL PORT AND ADJUST 
    //ACCORDINGLY TO HOW VALUES CHANGE WHEN TOUCHED.
  
  //Serial.println(keys[i].capacitiveSensor(NUM_OF_SAMPLES));
}
