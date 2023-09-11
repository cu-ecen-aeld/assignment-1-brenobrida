#include "unity.h"
#include <stdbool.h>
#include <stdlib.h>
#include "../../examples/autotest-validate/autotest-validate.h"
#include "../../assignment-autotest/test/assignment1/username-from-conf-file.h"

/**
* This function should:
*   1) Call the my_username() function in autotest-validate.c to get your hard coded username.
*   2) Obtain the value returned from function malloc_username_from_conf_file() in username-from-conf-file.h within
*       the assignment autotest submodule at assignment-autotest/test/assignment1/
*   3) Use unity assertion TEST_ASSERT_EQUAL_STRING_MESSAGE to verify the two strings are equal.  See
*       the [unity assertion reference](https://github.com/ThrowTheSwitch/Unity/blob/master/docs/UnityAssertionsReference.md)
*/
void test_validate_my_username()
{
    // 1) Call the my_username() function in autotest-validate.c to get your hard coded username.
    const char* hardcoded_username = my_username();

    // 2) Obtain the value returned from function malloc_username_from_conf_file() in username-from-conf-file.h
    char* config_username = malloc_username_from_conf_file();

    // Check for null values before comparing
    if (hardcoded_username == NULL || config_username == NULL)
    {
        TEST_ASSERT_TRUE_MESSAGE(false, "Either hardcoded_username or config_username is NULL.");
    }
    else
    {
        // 3) Use unity assertion TEST_ASSERT_EQUAL_STRING_MESSAGE to verify the two strings are equal.
        TEST_ASSERT_EQUAL_STRING_MESSAGE(hardcoded_username, config_username, "Username from hardcoded source and config file are not the same.");
    }

    // Free the memory allocated by malloc_username_from_conf_file() if needed
    free(config_username);
}

