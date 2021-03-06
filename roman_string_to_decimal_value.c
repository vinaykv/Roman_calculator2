/* 
Roman calculator: performs addition and subtraction of roman values
Author		: Vinay vittal Karagod
File dependents	: main.c, calculator.h, calculator.c,calculator-test.c,
		  roman_string_to_decimal_value.c, roman_string_to_decimal_value.h, decimal_value_to_roman_string.c,
		  decimal_value_to_roman_string.h, error.c, error.h, validation.h, validation.c, limit.h , limit.c
		  toUpperString.h, toUpperString.c 
Date		: 10/4/2016
 */



#include "roman_string_to_decimal_value.h"
#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000
#define INVALID -1

/*function to return decimal value of the roman digit*/
int roman_to_decimal_digit_value(char roman_character)
{
	static int decimal_value = 0;
	/*switch case to return the decimal value based on the character passed to it*/
	switch(roman_character){
	case 'I': decimal_value = I;
	break;
	case 'i': decimal_value = I;
	break;
	case 'V': decimal_value = V;
	break;
	case 'v': decimal_value = V;
	break;
	case 'X': decimal_value = X;
	break;
	case 'x': decimal_value = X;
	break;
	case 'L': decimal_value = L;
	break;
	case 'l': decimal_value = L;
	break;
	case 'C': decimal_value = C;
	break;
	case 'c': decimal_value = C;
	break;
	case 'D': decimal_value = D;
	break;
	case 'd': decimal_value = D;
	break;
	case 'M': decimal_value = M;
	break;
	case 'm': decimal_value = M;
	break;
	case '\0': decimal_value = 0;
	break;
	default: decimal_value = INVALID;
	}
	return decimal_value;
}

/*function to return the decimal value based on the input roman string*/
int roman_string_to_decimal_value(char roman_string[])
{
	int roman_string_index = 0; // index points to first element of the string
	int decimal_number = 0; // value to store the decimal value
	/*while condition runs until all the characters in the string are checked*/
	while(roman_string[roman_string_index]) 
	{
		/*if condition check the order of the string. If first digit is greater than the second digit it adds the value else 
		it subtracts the value  */
		if(roman_to_decimal_digit_value(roman_string[roman_string_index]) >= roman_to_decimal_digit_value(roman_string[roman_string_index+1])) 
			decimal_number = decimal_number + roman_to_decimal_digit_value(roman_string[roman_string_index]);
		else{
			decimal_number = decimal_number+ (roman_to_decimal_digit_value(roman_string[roman_string_index+1]) - roman_to_decimal_digit_value(roman_string[roman_string_index]));
			roman_string_index++;
		}
		roman_string_index++;/*incrementing to next character */
	}
	return decimal_number; /*return the final decimal value of the roman string*/
}
