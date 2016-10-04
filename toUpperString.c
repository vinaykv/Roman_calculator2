/* 
Roman calculator: performs addition and subtraction of roman values
Author		: Vinay vittal Karagod
File dependents	: main.c, calculator.h, calculator.c,calculator-test.c,
		  roman_string_to_decimal_value.c, roman_string_to_decimal_value.h, decimal_value_to_roman_string.c,
		  decimal_value_to_roman_string.h, error.c, error.h, validation.h, validation.c, limit.h , limit.c
		  toUpperString.h, toUpperString.c 
Date		: 10/4/2016
 */

#include <ctype.h>
/* function to convert lower string to upper string*/
char* stringUpper(char roman_value[])
{
  int roman_pointer = 0;
  while (roman_value[roman_pointer]) {
	roman_value[roman_pointer] = (toupper(roman_value[roman_pointer]));
	roman_pointer++;
  }
  return roman_value;
}
