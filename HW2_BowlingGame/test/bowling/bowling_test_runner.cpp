#ifdef __cplusplus
extern "C" {
#endif

#include "unity/fixture/unity_fixture.h"

TEST_GROUP_RUNNER(bowling)
{
   /* Test cases to run */
   RUN_TEST_CASE(bowling, CASE1_WhenRolledOneScoreIsOneSinglePlayer);
   RUN_TEST_CASE(bowling, CASE2_WhenRolledTwoFramesWithOneStrikeOnFirstRollPartialScoreIsCorrectSinglePlayer);
   RUN_TEST_CASE(bowling, CASE3_WhenRolledTwoFramesWithOneSpareOnFirstFramePartialScoreIsCorrectSinglePlayer);
   RUN_TEST_CASE(bowling, CASE4_WhenRolledLastFrameWithSingleStrikeFinalScoreIsCorrectSinglePlayer);
   RUN_TEST_CASE(bowling, CASE5_WhenRolledTenFramesWithSparesAndStrikesFinalScoreIsCorrectSinglePlayer);
   RUN_TEST_CASE(bowling, CASE6_WhenRolledLastFrameWithDoubleStrikeFinalScoreIsCorrectSinglePlayer);
   RUN_TEST_CASE(bowling, CASE7_WhenRolledLastFrameWithoutStrikeOrSpareFinalScoreIsCorrectSinglePlayer);
}

#ifdef __cplusplus
}
#endif
