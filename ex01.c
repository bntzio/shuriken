/*
 *
 *  Shuriken v.01
 *  C Path
 *
 *
 *  Instructions
 *  ------------
 *  Fix this code and make the tests pass to continue to the next exercise and get closer to become a C Sensei.
 *  Running this program will produce a test suite, which will check the specified outcome, be sure not to change the test itself, just the code to make them passs.
 *  In every exercise you will be given a story, a code structure and the unit tests you need to complete, make sure to make all the tests pass before continuing.
 *
 *
 *  Example
 *  -------
 *  My calculator is crazy, whenever I write a number plus another number (a sum) the calculator doesn't throw the result! Could you help me?
 *
 *  int x = 3;
 *  int y = 8;
 *  int result = 11;
 *
 *  int sum(int a, int b) {
 *    return a + b;
 *  }
 *
 *  MU_TEST(test_check) {
 *    mu_check(result == x + y);
 *  }
 *
 *  MU_TEST_SUITE(test_suite) {
 *    MU_RUN_TEST(test_check);
 *  }
 *
 *  int main() {
 *    sum(x, y);
 *    MU_RUN_SUITE(test_suite);
 *    MU_REPORT();
 *    return 0;
 *  }
 *
 *
 *  Output - Tests Failing
 *  ----------------------
 *  F
 *  test_check failed:
 *	ex01.c:25: result == x + y
 *
 *  1 tests, 1 assertions, 1 failures
 *
 *  Finished in 0.00002542 seconds (real) 0.00000900 seconds (proc)
 *
 *
 *  Solution
 *  --------
 *  The problem is, first of all, the result variable initialization at the top, it should be 0, not 11, because it should contain the result of x + y.
 *  Next, the second problem we encounter is that the function sum(x, y); in main does return the result of x + y, but the problem is that it isn't being
 *  stored in a variable, we want to store the returned number (the result) in the variable result (because the test checks that result should be equal to x + y.
 *  Finally, we get the test passing. Hooray!
 *
 *
 *  Output - Tests Passing
 *  ----------------------
 *  .
 *  test_check passed:
 *	ex01.c:25: result == x + y
 *
 *  1 tests, 1 assertions, 0 failures
 *
 *  Finished in 0.00002542 seconds (real) 0.00000900 seconds (proc)
 *
 *
 *  Final Notes
 *  -----------
 *  Whenever you run a unit test, you will get a report of the tests you are... well, testing.
 *  If a test fails, the report will produce an F; if a test pass, the report will produce a . (a dot)
 *
 *  If you got 6 tests, and you make 2 passing, and 4 failing, you'll get:
 *  F.FF.F (depending on the tests order)
 *
 *  Make sure to get all the tests passing!
 *  ......
 *
 *  Good luck! ;)
 *
 *  And remember, "May The Force Be With You Always..."
 *
 */


/*
 *
 *  Exercise Details
 *  ----------------
 *  Exercise: Robin Hood
 *  Exercise ID: 001
 *  Level: Apprentice
 *  Points awarded: +5 pts
 *
 *  Story
 *  -----
 *  Hey, Batman here, and I need your help! I don't know why I can't register my partner Robin in the Batcove database, there are some errors appearing when I try to compile
 *  the program, could you help me with this? Thank you very much!
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include "minunit.h"

#define MAX_SIZE 100

char name[MAX_SIZE] = "Robin";
char email[MAX_SIZE] = "robin@hotmail.com";

MU_TEST(test_check) {
    
    mu_check(name[0] == 'R');
    mu_check(name[1] == 'o');
    mu_check(name[2] == 'b');
    mu_check(name[3] == 'i');
    mu_check(name[4] == 'n');
    
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_check);
}

int main(int argc, char *argv[]) {
    
    for (int x = 0; x < sizeof(name); x++) {
        printf("%c", name[x]);
    }
    
    printf("\n");
    
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    
    return 0;
}

