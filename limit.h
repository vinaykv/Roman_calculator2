/* 
Roman calculator: performs addition and subtraction of roman values
Author		: Vinay vittal Karagod
File dependents	: main.c, calculator.h, calculator.c,calculator-test.c,
		  roman_string_to_decimal_value.c, roman_string_to_decimal_value.h, decimal_value_to_roman_string.c,
		  decimal_value_to_roman_string.h, error.c, error.h, validation.h, validation.c, limit.h , limit.c
		  toUpperString.h, toUpperString.c 
Date		: 10/4/2016
 */

#ifndef limit_H
#define limit_H
typedef int bool;
typedef enum {TRUE, FALSE} BOOL;
BOOL is_subtracted_number_null(int total_subtracted_value);
BOOL check_limit_of_added_numbers(int total_sum_value);
BOOL check_limit_of_subtracted_numbers(int total_subtracted_value);
#endif
