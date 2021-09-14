#define MS2S 0.000001f // from microsecond to seconds

//Time measurements
float time_stamp = 0.0;
float current_time = micros();
float past_time = micros();

// Variable to enable reading the motor position
volatile byte enable_position_sensing = false;

void setup() {
  Serial.begin(9600);
  LoadMenuUI(); // Load Serial User Interface
}

void loop() {
  // Update TimeStamp
  current_time = micros();
  time_stamp = (current_time - past_time)*MS2S;
  past_time = current_time;

  // Check User Commands
  CheckKeyboard();
  
  // Apply control law if the flag enable_control_loop is enabled
  if(enable_position_sensing){
    // Read actuator position
    float motor_position = ReadMotorPosition();

    // Print data in the serial monitor
    Serial.print(time_stamp); Serial.print(", ");
    Serial.println(motor_position);
  }
}
