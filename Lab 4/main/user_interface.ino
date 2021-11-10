/*
 * Function: LoadMenuUI
 *  Present to the user the serial menu with the different options. Depending on the option selected the flag 
 *  enable_control_loop is activated.
 *    Enable: Set the actuator to the enable mode.
 *    Disable: Set the actuator to the disable mode.
 *    Position Sensor Calibration: Associated the position limits with the values of the position sensor.
 *    Map Sensor and Motor Position: Associates the position sensor frame with the motor position frame.
 *    Position: Set a desired position to the actuator.
 *    Sinus tracking: Generates a sinusoidal reference trajectory and send it to the actuator
 *  
 * Inputs: void
 *  
 * Outputs: void
 */
void LoadMenuUI(void){
  Serial.println("|****************************|");
  Serial.println("|*******|EduExo Tests|*******|");
  Serial.println("|**|        Menu          |**|");
  Serial.println("|****************************|");
  Serial.println("");
  Serial.println("Please, select one of the following options:");
  Serial.println("e) Enable");
  Serial.println("d) Disable");
  Serial.println("s) Position Sensor Calibration");
  Serial.println("m) Map Position Sensor to motor position");
  Serial.println("p) Set a position");
  Serial.println("c) Enter in the Control Loop");
}

/*
 * Function: CheckKeyboard
 *  State machine to enter in the different modes depending on the selection of the user. Depending on the option selected the flag 
 *  enable_control_loop is activated.
 *    Enable: Set the actuator to the enable mode.
 *    Disable: Set the actuator to the disable mode.
 *    Position Sensor Calibration: Associated the position limits with the values of the position sensor.
 *    Map Sensor and Motor Position: Associates the position sensor frame with the motor position frame.
 *    Position: Set a desired position to the actuator.
 *    Sinus tracking: Generates a sinusoidal reference trajectory and send it to the actuator
 *    
 *  Depending on the option selected the flag enable_control_loop is activated.
 * Inputs: void
 *  
 * Outputs: void
 */
void CheckKeyboard(void){
  char incomingChar_b = 0;
  if(Serial.available() > 0) {
    incomingChar_b = Serial.read();
    Serial.flush();
    if(incomingChar_b == 'e') {
      enable_control_loop = false;
      EnableMotor();
    }
    else if(incomingChar_b == 'd'){
      enable_control_loop = false;
      DisableMotor();
    }
    else if(incomingChar_b == 'm'){
      enable_control_loop = false;
      MappingSensorAndMotorPosition();
    }
    else if(incomingChar_b == 's'){
      enable_control_loop = false;
      CalibratePositionSensor();
    }
    else if(incomingChar_b == 'p') {
      enable_control_loop = false;
      Serial.println("Set Position! [Deg]");
      while (Serial.available() == 0);
      float des_pos = Serial.parseFloat();
      Serial.println(des_pos);
      SetMotorPosition(des_pos);
      Serial.println("Position Set!"); 
    }
    else if(incomingChar_b == 'c') {
      enable_control_loop = true;
    }
  }
}
