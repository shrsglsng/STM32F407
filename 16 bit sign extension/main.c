
#include "sign_extension.h"

static const uint16_t test[6] = {0x0f64, 0x0fff, 0x2c, 0, 0x0ddd, 0x0800};

static const int16_t expected[6] = {-156, -1, 44, 0, -547, -2048};



int main(void)
{

	int errors = 0;

	for(int i = 0; i <= 5; i++){

		if(sign_extend(test[i]) != expected[i]){

			errors ++;

		}


	}



	for(;;);
}
