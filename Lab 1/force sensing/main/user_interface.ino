/*
 * Function: LoadMenuUI
 *  Present to the user the serial menu with the different options. Depending on the option selected the flag 
 *  enable_force_sensing is activated.
 *    Offset Load Cell: Correction of the offset of the load cell.
 *    Read Load Cell: Read interaction torques coming from load cell
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
  Serial.println("o) Correct Offset Load Cell");
  Serial.println("r) Read Load Cell");
  Serial.println("e) Exit Mode");
}

/*
 * Function: CheckKeyboard
 *  State machine to enter in the different modes depending on the selection of the user. The modes are:
 *    Offset Load Cell: Correction of the offset of the load cell.
 *    Read Load Cell: Read interaction torques coming from load cell
 *    
 *  Depending on the option selected the flag enable_force_sensing is activated.
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
    if(incomingChar_b == 'o'){
      enable_force_sensing = false;
      CorrectOffsetLoadCell();
    }
    else if(incomingChar_b == 'r') {
      enable_force_sensing = true;
    }
    else if(incomingChar_b == 'e') {
      enable_force_sensing = false;
    }
  }
}
