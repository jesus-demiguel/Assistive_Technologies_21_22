#define ADC2N 1.0f
#define N2Nm 1.0f

//Pin to read the load cell
#define LOADCELL_ANALOGPIN A3
 // N samples to correct the offset of the load cell
#define NSAMPLES_OFFSET_CORRECTION 1000

// Global variable to store the offset corrected of the load cell
float offset_load_cell = 0.0;


/*
 * Function: ReadLoadCell
 *  Function to read the channel associated to the connection with the load cell
 *  
 * Inputs: void
 *  
 * Outputs:
 *  -adc_val(float): Value given by the load cell in ADC counts.
 */
float ReadLoadCell(){
  
}

/*
 * Function: CorrectOffsetLoadCell
 *  Function to correct the offset of the load cell. The value is stored in 
 *  offset_load_cell
 *  
 * Inputs: void
 *  
 * Outputs: void
 */
void CorrectOffsetLoadCell(void){

}
