the sign_extend() implements 12 bit 2's complement form sign extension to 16 bit 2's complement form. The 12 bit input can be changed to n bit by ensuring nth bit masking.This can be useful when a peripheral outputs a 12bit signed value.

Real life usecase scenario: a strin gauge sensor feed into a 12 bit ADC.
