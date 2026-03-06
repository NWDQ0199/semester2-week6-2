/**
 * @file 1_tests.c
 * @brief Unit testing with Acutest - test the is_palindrome() function
 *
 * COMP1850 Week 6 Session 2 - Task 2
 *
 * Write test functions using Acutest to verify is_palindrome() works correctly.
 * An example test is provided - add more tests covering different cases.
 */

#include "acutest.h"
#include <string.h>

/* Function prototype */
int is_palindrome(const char *str);
void test_obvious_palindrome(void);
void test_empty_string(void);
void test_single_char(void);

/* ============================================================
 * EXAMPLE TEST - Students should follow this pattern
 * ============================================================ */

void test_obvious_palindrome(void)
{
    TEST_CHECK(is_palindrome("racecar")==1);
    TEST_MSG("Expected \"racecar\" to be a palindrome");
}

/* ============================================================
 * TODO: Add your test functions below
 *
 * Consider testing:
 * - Single characters: "a"
 * - Empty string: ""
 * - Non-palindromes: "hello", "world"
 * - Even-length palindromes: "abba", "deed"
 * - Edge cases: case sensitivity, spaces
 *
 * Each test function should:
 * 1. Call TEST_CHECK(condition) to verify a condition
 * 2. Use TEST_MSG("message") to explain what went wrong if it fails
 * ============================================================ */

void test_empty_string(void)
{
	TEST_CHECK(is_palindrome("")==1);
	TEST_MSG("Expected \"\" to be a palindrome");
}

void test_single_char(void)
{
	TEST_CHECK(is_palindrome("a")==1);
	TEST_MSG("Expected \"a\" to be a palindrome");
}

/* ============================================================
 * TEST_LIST - Register all your tests here
 *
 * Format: { "test name shown in output", function_name },
 * Must end with { NULL, NULL }
 * ============================================================ */
TEST_LIST=
{
    {"obvious palindrome (racecar)",test_obvious_palindrome},
	{"empty string",test_empty_string},
	{"single character",test_single_char},
    /* TODO: Add your tests here, e.g.:
	 * { "single character", test_single_char },
     * { "empty string", test_empty_string },
     */
    {NULL,NULL}
};

/* ============================================================
 * IMPLEMENTATION - Do not modify
 * ============================================================ */

/**
 * @brief Checks if a given string is a palindrome.
 *
 * @param str The string to be checked.
 * @return int 1 if the string is a palindrome, 0 otherwise.
 */
int is_palindrome(const char *str)
{
    int len=strlen(str);
    for(int i=0;i<len/2;i++)
	{
        if(str[i]!=str[len-i-1])
		{
            return 0;
        }
    }
    return 1;
}
