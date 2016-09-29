# include <stdio.h>
#include "single_roman_char_conversion.h"

/*function to return the decimal value based on the input roman string*/

int roman_string_to_decimal_value(char roman_string[])
{
	static int roman_string_index = 0;
	static int decimal_number = 0; // value to store the decimal value
	/*while loop to process the each roman character individually */
	while(roman_string[roman_string_index])
	{
		/*if condition check the order of the string. If first digit is greater than the second digit it add the value else 
		it subtracts the value  */
	if(roman_to_decimal_digit_value(roman_string[roman_string_index]) < 0){
             return -1;
         }

	if(roman_to_decimal_digit_value(roman_string[roman_string_index]) >= roman_to_decimal_digit_value(roman_string[roman_string_index+1])) 
			decimal_number = decimal_number + roman_to_decimal_digit_value(roman_string[roman_string_index]);
		else{
			decimal_number = decimal_number+ (roman_to_decimal_digit_value(roman_string[roman_string_index+1]) - roman_to_decimal_digit_value(roman_string[roman_string_index]));
			roman_string_index++;
			
		}
		roman_string_index++;
	}
	return decimal_number;
}
