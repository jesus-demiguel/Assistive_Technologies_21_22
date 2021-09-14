/*
 * Function: LoadMenuUI
 *  Present to the user the serial menu with the different options. Depending on the option selected the flag 
 *  enable_position_sensing is activated.
 *    Position Sensor Calibration: Associated the position limits with the values of the position sensor.
 *    Read Position: Read position of the motor of the exo.
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
  Serial.println("c) Position Sensor Calibration");
  Serial.println("r) Read Position");
  Serial.println("e) Exit Mode");
}

/*
 * Function: CheckKeyboard
 *  State machine to enter in the different modes depending on the selection of the user. Depending on the option selected the flag 
 *  enable_control_loop is activated.
 *    Position Sensor Calibration: Associated the position limits with the values of the position sensor.
 *    Read Position: Read position of the motor of the exo.
 *    
 *  Depending on the option selected the flag enable_position_sensing is activated.
 * Inputs: void
 *  
 * Outputs: void
 */
void CheckKeyboard(void){
  char incomingChar_b = 0;
  if(Serial.available() > 0) {
    incomingChar_b = Serial.read();
    Serial.flush();
    if(incomingChar_b == 'c'){
      enable_position_sensing = false;
      CalibratePositionSensor();
    }
    else if(incomingChar_b == 'r') {
      enable_position_sensing = true;
    }
    else if(incomingChar_b == 'e') {
      enable_position_sensing = false;
    }
  }
}
