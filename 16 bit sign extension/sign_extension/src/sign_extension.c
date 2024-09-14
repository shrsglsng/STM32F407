/*
 * sign_extension.c
 *
 *  Created on: Sep 14, 2024
 *      Author: shreyas
 */

#include "sign_extension.h"

int16_t sign_extend( uint16_t input_12_bits){

// in 12 bit 2's complement value, the 12th bit is the the sign , so apply sign extension to convert to 16 bits

uint16_t temp= 0x0000;		//intermediate variable to sore the masked value

int16_t output_16_bits = 0x0000;

output_16_bits |= input_12_bits;

temp |= input_12_bits & 0x800;				// mask the 12th bit and store it in temp

for(int i = 0; i<=5; i++){

	output_16_bits |= (temp << i);			// iteratively extend sign bits


}

return output_16_bits;

}


