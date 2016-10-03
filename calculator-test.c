#include <check.h>
#line 1 "calculator-test.check"
#include "limit.h"
#include "roman_string_to_decimal_value.h"
#include "decimal_value_to_roman_string.h"
# include "calculator.h"
#include "validation.h"
#include "toUpperString.h"
#define INVALID 0
#define VALID 1

#define size 50
char buffer[size];

START_TEST(single_roman_char_conversion)
{
/* checking the conditions for the single roman value*/
ck_assert_msg(roman_to_decimal_digit_value('I') == 1,"operation failed for I");
ck_assert_msg(roman_to_decimal_digit_value('V') == 5,"operation failed for V");
ck_assert_msg(roman_to_decimal_digit_value('X') == 10,"operation failed for X");
ck_assert_msg(roman_to_decimal_digit_value('L') == 50,"operation failed for L");
ck_assert_msg(roman_to_decimal_digit_value('C') == 100,"operation failed for C");
ck_assert_msg(roman_to_decimal_digit_value('D') == 500,"operation failed for D");
ck_assert_msg(roman_to_decimal_digit_value('M') == 1000,"operation failed for M");

}
END_TEST
START_TEST(invalid_roman_digit)
{
#line 27
ck_assert_msg(roman_to_decimal_digit_value('\0') == 0,"operation failed for end of line");
ck_assert_msg(roman_to_decimal_digit_value('K') == INVALID,"operation failed for passing wrong input");

}
END_TEST

START_TEST(roman_string_to_decimal)
{

/*condition to check the string of roman numbers*/
ck_assert_msg(roman_string_to_decimal_value("MD") == 1500,"operation failed to convert roman to decimal of MD");

}
END_TEST

START_TEST(roman_string_to_decimal_1)
{

ck_assert_msg(roman_string_to_decimal_value("MM") == 2000,"operation failed to convert roman to decimal of MM");

}
END_TEST
START_TEST(invalid_roman_string)
{

ck_assert_msg(roman_string_to_decimal_value("DM") == INVALID,"wrong format to pass the roman value DM");
}
END_TEST

START_TEST(II_equals_2)
{

ck_assert_msg(roman_string_to_decimal_value("II") == 2,"operation failed to convert roman to decimal of II");
}
END_TEST

START_TEST(IV_equals_4)
{

ck_assert_msg(roman_string_to_decimal_value("IV") == 4,"operation failed to convert roman to decimal of IV");
}
END_TEST

START_TEST(VI_equals_6)
{

ck_assert_msg(roman_string_to_decimal_value("VI") == 6,"operation failed to convert roman to decimal of VI");
}
END_TEST

START_TEST(XXXVII_equals_37)
{

ck_assert_msg(roman_string_to_decimal_value("XXXVII") == 37,"operation failed to convert roman to decimal of XXXVII");
}
END_TEST

START_TEST(invalid_roman_string_1)
{

ck_assert_msg(roman_string_to_decimal_value("XXC") == INVALID,"invalid roman string XXC");
}
END_TEST

START_TEST(MMCCCXLV_equals_2345)
{

ck_assert_msg(roman_string_to_decimal_value("MMCCCXLV") == 2345,"operation failed to convert roman to decimal of MMCCCXLV");
}
END_TEST

START_TEST(zero_equals_zero)
{

ck_assert_msg(roman_string_to_decimal_value("0") == INVALID,"Invalid Operation passed zero value");
}
END_TEST

START_TEST(XXXC_equals_70)
{

ck_assert_msg(roman_string_to_decimal_value("XXXC") == INVALID,"Not a valid roman number := XXXC");
}
END_TEST

START_TEST(LV_equals_55)
{

ck_assert_msg(roman_string_to_decimal_value("LV") == 55,"valid roman number: lv == 55");
}
END_TEST

START_TEST(_1000_equals_M)
{
/*condition to convert back from decimal to roman number*/
ck_assert_msg(strcmp(decimal_number_to_roman_string(1000,buffer),"M") == 0,"Operation failed to convert decimal to roman value: 1000");
}
END_TEST

START_TEST(_500_equals_D)
{
/*condition to convert back from decimal to roman number*/
ck_assert_msg(strcmp(decimal_number_to_roman_string(500,buffer),"D") == 0,"Operation failed to convert decimal to roman value: 500");
}
END_TEST

START_TEST(_1500_equals_MD)
{
/*condition to convert back from decimal to roman number*/
ck_assert_msg(strcmp(decimal_number_to_roman_string(1500,buffer),"MD") == 0,"Operation failed to convert decimal to roman value: 1500");
}
END_TEST

START_TEST(_1900_equals_MCM)
{
/*condition to convert back from decimal to roman number*/
ck_assert_msg(strcmp(decimal_number_to_roman_string(1900,buffer),"MCM") == 0,"Operation failed to convert decimal to roman value: 1900");
}
END_TEST

START_TEST(_150_equals_CL)
{
/*condition to convert back from decimal to roman number*/
ck_assert_msg(strcmp(decimal_number_to_roman_string(150,buffer),"CL") == 0,"Operation failed to convert decimal to roman value: 150");
}
END_TEST

START_TEST(_15_equals_XV)
{
/*condition to convert back from decimal to roman number*/
ck_assert_msg(strcmp(decimal_number_to_roman_string(15,buffer),"XV") == 0,"Operation failed to convert decimal to roman value: 15");
}
END_TEST

START_TEST(_4_equals_IV)
{
/*condition to convert back from decimal to roman number*/
ck_assert_msg(strcmp(decimal_number_to_roman_string(4,buffer),"IV") == 0,"Operation failed to convert decimal to roman value: 4");
}
END_TEST

START_TEST(_2_equals_II)
{
/*condition to convert back from decimal to roman number*/

ck_assert_msg(strcmp(decimal_number_to_roman_string(2,buffer),"II") == 0,"Operation failed to convert decimal to roman value: 2");

}
END_TEST

START_TEST(roman_addition_M_D_equals_MD)
{

ck_assert_msg(strcmp(calculate_roman_numbers("M","D",ADD,buffer),"MD") == 0,"Operation failed to add the two roman value to MD");

}
END_TEST

START_TEST(roman_addition_i_X_equals_XI)
{

ck_assert_msg(strcmp(calculate_roman_numbers("i","X",ADD,buffer),"XI") == 0,"Operation failed to add the two roman value to MD");

}
END_TEST

START_TEST(Invalid_roman_character_A_equals_NULL)
{

ck_assert_msg(isRomanNumberValid("A") == INVALID,"A is not a valid roman character");

}
END_TEST

START_TEST(valid_roman_character_M_equals_1000)
{

ck_assert_msg(isRomanNumberValid("M") == VALID,"M is a valid roman character");

}
END_TEST

START_TEST(roman_addition_I_I_equals_II)
{

ck_assert_msg(strcmp(calculate_roman_numbers("I","I",ADD,buffer),"II") == 0,"Operation failed to add the two roman value to II");

}
END_TEST

START_TEST(roman_addition_BAD_XXLL_equals_NULL)
{

ck_assert_msg(strcmp(calculate_roman_numbers("BAD","XXLL",ADD,buffer),"INVALID") == 0,"Invalid operation bad input : BAD XXLL ADD");

}
END_TEST

START_TEST(roman_addition_XX_BAD_equals_NULL)
{

ck_assert_msg(strcmp(calculate_roman_numbers("XX","BAD",ADD,buffer),"INVALID") == 0,"Invalid operation bad second input : XX BAD ADD ");

}
END_TEST

START_TEST(roman_addition_BAD_BAD_equals_NULL)
{

ck_assert_msg(strcmp(calculate_roman_numbers("BAD","BAD",ADD,buffer),"INVALID") == 0,"Invalid operation invalid input : BAD BAD ADD ");

}
END_TEST

START_TEST(roman_addition_MM_MM_equals_MMMM)
{

ck_assert_msg(strcmp(calculate_roman_numbers("MM","MM",ADD,buffer),"INVALID") == 0,"Limit exceeds the maximum limit: 4000 ");

}
END_TEST

START_TEST(roman_addition_MMCCC_MMCCC_equals_MMMMDC)
{

ck_assert_msg(strcmp(calculate_roman_numbers("MMCCC","MMCCC",ADD,buffer),"INVALID") == 0,"Limit exceeds the maximum limit: 4600 ");

}
END_TEST

START_TEST(roman_addition_0_0_equals_0)
{

ck_assert_msg(strcmp(calculate_roman_numbers("0","0",ADD,buffer),"INVALID") == 0,"Invalid input passing zeros as both input");

}
END_TEST

START_TEST(roman_addition_III_III_equals_VI)
{

ck_assert_msg(strcmp(calculate_roman_numbers("III","III",ADD,buffer),"VI") == 0,"operation failed to return : VI");

}
END_TEST

START_TEST(roman_subtraction_III_I_equals_II)
{

ck_assert_msg(strcmp(calculate_roman_numbers("III","I",SUBTRACT,buffer),"II") == 0,"operation failed to subtract two numbers : II ");

}
END_TEST

START_TEST(roman_limit_sum_3_equals_VALID)
{

ck_assert_msg(is_Limit_Of_Add_Is_Not_Exceeded(3) == VALID,"input number is with in the limit : 3");

}
END_TEST

START_TEST(roman_limit_sum_4500_equals_INVALID)
{

ck_assert_msg(is_Limit_Of_Add_Is_Not_Exceeded(4500) == INVALID,"input number is out of limit : 4500");

}
END_TEST

START_TEST(roman_limit_subtract_3700_equals_VALID)
{

ck_assert_msg(is_Limit_Of_Subtract_Is_Not_Exceeded(3700) == VALID,"input number is in limit : 3700");

}
END_TEST

START_TEST(roman_limit_subtract_4900_equals_INVALID)
{

ck_assert_msg(is_Limit_Of_Subtract_Is_Not_Exceeded(4900) == INVALID,"input number is out of limit : 4900");

}
END_TEST

START_TEST(string_upper_iii_equals_III)
{

ck_assert_msg(strcmp(stringUpper("iii"),"III") == 0,"failed to conver lower to upper string");

}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, roman_limit_sum_3_equals_VALID);
    tcase_add_test(tc1_1, roman_limit_sum_4500_equals_INVALID);
    tcase_add_test(tc1_1, roman_limit_subtract_3700_equals_VALID);
    tcase_add_test(tc1_1, roman_limit_subtract_4900_equals_INVALID);
    tcase_add_test(tc1_1, roman_addition_BAD_BAD_equals_NULL);
    tcase_add_test(tc1_1, roman_addition_MM_MM_equals_MMMM);
    tcase_add_test(tc1_1, roman_addition_MMCCC_MMCCC_equals_MMMMDC);
    tcase_add_test(tc1_1, roman_addition_0_0_equals_0);
    tcase_add_test(tc1_1, roman_addition_III_III_equals_VI);
    tcase_add_test(tc1_1, roman_subtraction_III_I_equals_II);
    tcase_add_test(tc1_1, valid_roman_character_M_equals_1000);
    tcase_add_test(tc1_1, Invalid_roman_character_A_equals_NULL);
    tcase_add_test(tc1_1, single_roman_char_conversion);
    tcase_add_test(tc1_1, invalid_roman_digit);
    tcase_add_test(tc1_1, roman_string_to_decimal);
    tcase_add_test(tc1_1, roman_string_to_decimal_1);
    tcase_add_test(tc1_1, invalid_roman_string);
    tcase_add_test(tc1_1, II_equals_2);
    tcase_add_test(tc1_1, IV_equals_4);
    tcase_add_test(tc1_1, VI_equals_6);
    tcase_add_test(tc1_1, XXXVII_equals_37);
    tcase_add_test(tc1_1, invalid_roman_string_1);
    tcase_add_test(tc1_1, MMCCCXLV_equals_2345);
    tcase_add_test(tc1_1, zero_equals_zero);
    tcase_add_test(tc1_1, XXXC_equals_70);
    tcase_add_test(tc1_1, LV_equals_55);
    tcase_add_test(tc1_1, _1000_equals_M);
    tcase_add_test(tc1_1, _500_equals_D);
    tcase_add_test(tc1_1, _1500_equals_MD);
    tcase_add_test(tc1_1, _1900_equals_MCM);
    tcase_add_test(tc1_1, _150_equals_CL);
    tcase_add_test(tc1_1, _15_equals_XV);
    tcase_add_test(tc1_1, _4_equals_IV);
    tcase_add_test(tc1_1, _2_equals_II);
    tcase_add_test(tc1_1, roman_addition_M_D_equals_MD);
    tcase_add_test(tc1_1, roman_addition_i_X_equals_XI);
    tcase_add_test(tc1_1, roman_addition_I_I_equals_II);
    tcase_add_test(tc1_1, roman_addition_BAD_XXLL_equals_NULL);
    tcase_add_test(tc1_1, roman_addition_XX_BAD_equals_NULL);
    tcase_add_test(tc1_1, string_upper_iii_equals_III);
    
    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
