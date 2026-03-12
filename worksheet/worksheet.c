/**
 * Week 6 Worksheet - Functions Practice
 *
 * This worksheet tests your understanding of:
 * - Pass by value (returning results)
 * - Pass by reference (modifying via pointers)
 * - Arrays as function arguments
 * - Output parameters
 *
 * Instructions:
 * 1. Implement each function according to its documentation
 * 2. Compile and run to test: gcc worksheet.c -o worksheet && ./worksheet
 * 3. Acutest will show which tests pass/fail
 *
 * Run options:
 *	 ./worksheet							- Run all tests
 *	 ./worksheet --list			 - List all tests
 *	 ./worksheet test_name		- Run specific test
 */

 //oscar hazel (nwdq0199/201941466) 2026-03-12 18-12

#include "acutest.h"

/* ============================================================
 * FUNCTION PROTOTYPES - Do not modify these
 * ============================================================ */

int add_values(int a, int b);
void swap_values(int *a, int *b);
int sum_array(int *arr, int n);
void reverse_array(int *arr, int n);
double average(int *arr, int n);
int find_max(int *arr, int n, int *index);

/* ============================================================
 * STUDENT IMPLEMENTATIONS - Complete these functions
 * ============================================================ */

/**
 * Function 1: add_values
 *
 * Returns the sum of two integers.
 * This demonstrates simple pass-by-value with a return.
 *
 * @param a First integer
 * @param b Second integer
 * @return The sum a + b
 *
 * Example: add_values(3, 4) returns 7
 */
int add_values(int a, int b)
{
	// TODO: Implement this function
	return a+b; // Replace this
}

/**
 * Function 2: swap_values
 *
 * Swaps two integers using pointers (pass by reference).
 * After calling, *a should have the original value of *b,
 * and *b should have the original value of *a.
 *
 * @param a Pointer to first integer
 * @param b Pointer to second integer
 *
 * Example:
 *	 int x = 5, y = 10;
 *	 swap_values(&x, &y);
 *	 // Now x == 10, y == 5
 */
void swap_values(int *a, int *b)
{
	// TODO: Implement this function
	// Hint: You'll need a temporary variable
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

/**
 * Function 3: sum_array
 *
 * Returns the sum of all elements in an array.
 * This demonstrates arrays as pointers in function arguments.
 *
 * @param arr Pointer to the first element of the array
 * @param n	 Number of elements in the array
 * @return		Sum of all elements
 *
 * Example: sum_array([1,2,3,4,5], 5) returns 15
 */
int sum_array(int *arr, int n)
{
	// TODO: Implement this function
	int total=0;
	for(int i=0;i<n;i++)
	{
		
	}
	return 0; // Replace this
}

/**
 * Function 4: reverse_array
 *
 * Reverses an array in place.
 * The first element becomes the last, etc.
 *
 * @param arr Pointer to the first element of the array
 * @param n	 Number of elements in the array
 *
 * Example:
 *	 int arr[] = {1, 2, 3, 4, 5};
 *	 reverse_array(arr, 5);
 *	 // Now arr[] == {5, 4, 3, 2, 1}
 *
 * Hint: Swap elements from both ends, moving toward the middle
 */
void reverse_array(int *arr, int n) {
	// TODO: Implement this function
}

/**
 * Function 5: average
 *
 * Returns the average of array elements as a double.
 * This demonstrates returning a different type than the input.
 *
 * @param arr Pointer to the first element of the array
 * @param n	 Number of elements in the array
 * @return		Average as a double
 *
 * Example: average([1,2,3,4,5], 5) returns 3.0
 * Example: average([1,2], 2) returns 1.5
 */
double average(int *arr, int n) {
	// TODO: Implement this function
	// Hint: Be careful with integer division!
	return 0.0; // Replace this
}

/**
 * Function 6: find_max
 *
 * Finds the maximum value in an array AND its index.
 * The maximum value is returned, and the index is stored
 * in the output parameter.
 *
 * @param arr	 Pointer to the first element of the array
 * @param n		 Number of elements in the array
 * @param index Pointer to store the index of the maximum (output parameter)
 * @return			The maximum value
 *
 * Example:
 *	 int arr[] = {3, 7, 2, 9, 4};
 *	 int idx;
 *	 int max = find_max(arr, 5, &idx);
 *	 // max == 9, idx == 3
 */
int find_max(int *arr, int n, int *index) {
	// TODO: Implement this function
	*index = 0;
	return 0; // Replace this
}

/* ============================================================
 * UNIT TESTS - Using Acutest framework
 * https://github.com/mity/acutest
 * ============================================================ */

void test_add_values(void) {
	TEST_CHECK(add_values(3, 4) == 7);
	TEST_MSG("Expected add_values(3, 4) = 7");

	TEST_CHECK(add_values(0, 0) == 0);
	TEST_MSG("Expected add_values(0, 0) = 0");

	TEST_CHECK(add_values(-5, 5) == 0);
	TEST_MSG("Expected add_values(-5, 5) = 0");

	TEST_CHECK(add_values(-3, -7) == -10);
	TEST_MSG("Expected add_values(-3, -7) = -10");
}

void test_swap_values(void) {
	int a, b;

	a = 5;
	b = 10;
	swap_values(&a, &b);
	TEST_CHECK(a == 10 && b == 5);
	TEST_MSG("After swap_values(&5, &10): expected a=10, b=5, got a=%d, b=%d", a,
					 b);

	a = -1;
	b = 1;
	swap_values(&a, &b);
	TEST_CHECK(a == 1 && b == -1);
	TEST_MSG("After swap_values(&-1, &1): expected a=1, b=-1, got a=%d, b=%d", a,
					 b);

	a = 0;
	b = 100;
	swap_values(&a, &b);
	TEST_CHECK(a == 100 && b == 0);
	TEST_MSG("After swap_values(&0, &100): expected a=100, b=0, got a=%d, b=%d",
					 a, b);
}

void test_sum_array(void) {
	int arr1[] = {1, 2, 3, 4, 5};
	TEST_CHECK(sum_array(arr1, 5) == 15);
	TEST_MSG("Expected sum_array([1,2,3,4,5], 5) = 15");

	int arr2[] = {10};
	TEST_CHECK(sum_array(arr2, 1) == 10);
	TEST_MSG("Expected sum_array([10], 1) = 10");

	int arr3[] = {-1, -2, -3};
	TEST_CHECK(sum_array(arr3, 3) == -6);
	TEST_MSG("Expected sum_array([-1,-2,-3], 3) = -6");

	int arr4[] = {0, 0, 0, 0};
	TEST_CHECK(sum_array(arr4, 4) == 0);
	TEST_MSG("Expected sum_array([0,0,0,0], 4) = 0");
}

void test_reverse_array(void) {
	int arr1[] = {1, 2, 3, 4, 5};
	int exp1[] = {5, 4, 3, 2, 1};
	reverse_array(arr1, 5);
	int ok = 1;
	for (int i = 0; i < 5; ++i) {
		if (arr1[i] != exp1[i])
			ok = 0;
	}
	TEST_CHECK(ok);
	TEST_MSG("Expected reverse_array([1,2,3,4,5]) = [5,4,3,2,1]");

	int arr2[] = {1, 2};
	reverse_array(arr2, 2);
	TEST_CHECK(arr2[0] == 2 && arr2[1] == 1);
	TEST_MSG("Expected reverse_array([1,2]) = [2,1]");

	int arr3[] = {42};
	reverse_array(arr3, 1);
	TEST_CHECK(arr3[0] == 42);
	TEST_MSG("Expected reverse_array([42]) = [42] (single element unchanged)");
}

void test_average(void) {
	int arr1[] = {1, 2, 3, 4, 5};
	double avg1 = average(arr1, 5);
	TEST_CHECK(avg1 >= 2.99 && avg1 <= 3.01);
	TEST_MSG("Expected average([1,2,3,4,5]) = 3.0, got %f", avg1);

	int arr2[] = {1, 2};
	double avg2 = average(arr2, 2);
	TEST_CHECK(avg2 >= 1.49 && avg2 <= 1.51);
	TEST_MSG("Expected average([1,2]) = 1.5, got %f", avg2);

	int arr3[] = {10, 20, 30};
	double avg3 = average(arr3, 3);
	TEST_CHECK(avg3 >= 19.99 && avg3 <= 20.01);
	TEST_MSG("Expected average([10,20,30]) = 20.0, got %f", avg3);
}

void test_find_max(void) {
	int arr1[] = {3, 7, 2, 9, 4};
	int idx1;
	int max1 = find_max(arr1, 5, &idx1);
	TEST_CHECK(max1 == 9 && idx1 == 3);
	TEST_MSG("Expected find_max([3,7,2,9,4]) = 9 at index 3, got %d at %d", max1,
					 idx1);

	int arr2[] = {100};
	int idx2;
	int max2 = find_max(arr2, 1, &idx2);
	TEST_CHECK(max2 == 100 && idx2 == 0);
	TEST_MSG("Expected find_max([100]) = 100 at index 0, got %d at %d", max2,
					 idx2);

	int arr3[] = {-5, -2, -8, -1};
	int idx3;
	int max3 = find_max(arr3, 4, &idx3);
	TEST_CHECK(max3 == -1 && idx3 == 3);
	TEST_MSG("Expected find_max([-5,-2,-8,-1]) = -1 at index 3, got %d at %d",
					 max3, idx3);
}

/* ============================================================
 * TEST LIST - Acutest discovers tests from this list
 * ============================================================ */

TEST_LIST = {
		{"add_values", test_add_values},
		{"swap_values", test_swap_values},
		{"sum_array", test_sum_array},
		{"reverse_array", test_reverse_array},
		{"average", test_average},
		{"find_max", test_find_max},
		{NULL, NULL} /* End of list */
};