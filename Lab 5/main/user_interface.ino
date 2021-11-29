/*
 * Function: LoadMenuUI
 *  Present to the user the serial menu with the different options. Depending on the option selected the flag 
 *  enable_control_loop is activated.
 *    Enable: Set the actuator to the enable mode.
 *    Disable: Set the actuator to the disable mode.
 *    Position Sensor Calibration: Associated the position limits with the values of the position sensor.
 *    Map Sensor and Motor Position: Associates the position sensor frame with the motor position frame.
 *    Offset Load Cell: Correction of the offset of the load cell.
 *    Position: Set a desired position to the actuator.
 *    Admittance: Request the user the parameters of the admittance model and enter in the control mode.
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
  Serial.println("o) Correct Offset Load Cell");
  Serial.println("p) Set a position");
  Serial.println("c) Enter in the Control Loop");
}

/*
 * Function: CheckKeyboard
 *  State machine to enter in the different modes depending on the selection of the user. The modes are:
 *    Enable: Set the actuator to the enable mode.
 *    Disable: Set the actuator to the disable mode.
 *    Position Sensor Calibration: Associated the position limits with the values of the position sensor.
 *    Map Sensor and Motor Position: Associates the position sensor frame with the motor position frame.
 *    Offset Load Cell: Correction of the offset of the load cell.
 *    Position: Set a desired position to the actuator.
 *    Admittance: Request the user the parameters of the admittance model and enter in the control mode.
 *    
 *  Depending on the option selected the flag enable_control_loop is activated.
 *  
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
    else if(incomingChar_b == 'o'){
      enable_control_loop = false;
      CorrectOffsetLoadCell();
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
      Serial.println("Admittance mode!");
      enable_control_loop = true;

      // Ask for changing admittance parameters
      Serial.println("Do you want to change your admittance parameters? [Y/N]");
      while (Serial.available() == 0);
      if (Serial.read() == 'Y') {
        Serial.println("Selected: YES");
        // Select virtual components admittance
        Serial.println("Set virtual inertia! [Nms^2/rad]");
        while (Serial.available() == 0);
        virtual_inertia = Serial.parseFloat();
        Serial.println("Virtual inertia set to " + String(virtual_inertia, 4) + " [Nms^2/rad]");
        Serial.println(" ");
        Serial.println("Set virtual damping! [Nms/rad]");
        while (Serial.available() == 0);
        virtual_damping = Serial.parseFloat();
        Serial.println("Virtual damping set to " + String(virtual_damping, 4) + " [Nms/rad]");
        Serial.println(" ");
        Serial.println("Set virtual stiffness! [Nm/rad]");
        while (Serial.available() == 0);
        virtual_stiffness = Serial.parseFloat();
        Serial.println("Virtual stiffness set to " + String(virtual_stiffness, 4) + " [Nm/rad]");
      }
      else {
        Serial.println("Selected: NO");
      }
    }
  }
}
