#include <Servo.h>

//Pin to read the position sensor
#define MOTORANALOGPIN A0

// Variable to map the position in degrees with the analog values given by the position sensor
#define MINPOSLIMIT 0.0f //degrees
#define MAXPOSLIMIT 90.0f //degrees
int adc_out_min_limit; // Value of the analog value of the potentiometer in zero degrees
int adc_out_max_limit; // Value of the analog value of the potentiometer in 90 degrees


/*
 * Function: CalibratePositionSensor
 *  The user is required to move the EduExo to the position limits and then the values
 *  read by the analog channel are stored in the variables adc_out_min_limit (int) and
 *  adc_out_max_limit (int).
 *  
 * Inputs: void
 *  
 * Outputs: void
 */
void CalibratePositionSensor(void){
  
}

/*
 * Function: ReadMotorPosition
 *  Read data received from the position sensor
 *  
 * Inputs: void
 *  
 * Outputs:
 *  -(float): Actual motor position in degrees
 */
float ReadMotorPosition(void){
 
}
