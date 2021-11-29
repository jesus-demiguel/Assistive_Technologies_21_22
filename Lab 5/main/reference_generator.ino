#define DEG2RAD 0.01745 //2pi/360
#define RAD2DEG 57.29577 //360/2pi

//Admittance model
float desired_position = 0.0;
float desired_velocity = 0.0;
float desired_acceleration = 0.0;
float virtual_inertia = 0.0;
float virtual_damping = 0.0;
float virtual_stiffness = 0.0;
float resting_pos = 45; //deg
float resting_vel = 0; //deg/s

/*
 * Function: ReferenceGenerator
 *  Generates a reference torque value following an admittance model, compesating inertia and gravity if desired.
 *    
 * Inputs: 
 *  - time_diff (float): Current time stamp of the system in seconds.
 *  - interaction_torque (int): Value of the load cell measured by the ADC.
 *  
 * Outputs:
 *  - (float): Desired position in degrees.
 */
float ReferenceGenerator(float time_diff, float interaction_torque){
  
}
 
