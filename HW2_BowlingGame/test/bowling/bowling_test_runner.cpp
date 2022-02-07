#ifdef __cplusplus
extern "C" {
#endif

#include "unity/fixture/unity_fixture.h"

TEST_GROUP_RUNNER(bowling)
{
   /* Test cases to run */
   RUN_TEST_CASE(bowling, WhenRolled1ScoreIs1);
}

#ifdef __cplusplus
}
#endif
