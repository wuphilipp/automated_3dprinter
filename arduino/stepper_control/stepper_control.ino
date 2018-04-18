// ConstantSpeed.pde
// -*- mode: C++ -*-
//
// Shows how to run AccelStepper in the simplest,
// fixed speed mode with no accelerations
/// \author  Mike McCauley (mikem@airspayce.com)
// Copyright (C) 2009 Mike McCauley
// $Id: ConstantSpeed.pde,v 1.1 2011/01/05 01:51:01 mikem Exp mikem $

#include <AccelStepper.h>

AccelStepper stepper(1, 3, 4); // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5

int mode = 0;

void setup()
{  
  Serial.begin(115200);
  stepper.setMaxSpeed(1000000);
  stepper.setSpeed(-1000000);	
  Serial.println("Ready");
  
}

void switch_zero(){ stepper.setSpeed(0); }

void switch_up(){ stepper.setSpeed(-100000); }

void switch_down(){ stepper.setSpeed(100000); }



void loop()
{  

    if (Serial.available() > 0) {
      int read_value = Serial.read();
      mode = read_value;
      switch(mode) {
        case '0:
          switch_zero();
          Serial.println("done");
          break;
        case 1:
          switch_up();
          Serial.println("done");
          break;
        case 2:
          switch_up();
          Serial.println("done");
          break;
      }
    }
       
  stepper.runSpeed();    
  
}
