#ifdef __cplusplus
extern "C" {
#endif

#include "unity/fixture/unity_fixture.h"

TEST_GROUP_RUNNER(single_bowling)
{
   /* Test cases to run */
   RUN_TEST_CASE(single_bowling, CASE1_WhenRolledOneScoreIsOneSinglePlayer);
   RUN_TEST_CASE(single_bowling, CASE2_WhenRolledTwoFramesWithOneStrikeOnFirstRollPartialScoreIsCorrectSinglePlayer);
   RUN_TEST_CASE(single_bowling, CASE3_WhenRolledTwoFramesWithOneSpareOnFirstFramePartialScoreIsCorrectSinglePlayer);
   RUN_TEST_CASE(single_bowling, CASE4_WhenRolledLastFrameWithSingleStrikeFinalScoreIsCorrectSinglePlayer);
   RUN_TEST_CASE(single_bowling, CASE5_WhenRolledTenFramesWithSparesAndStrikesFinalScoreIsCorrectSinglePlayer);
   RUN_TEST_CASE(single_bowling, CASE6_WhenRolledLastFrameWithDoubleStrikeFinalScoreIsCorrectSinglePlayer);
   RUN_TEST_CASE(single_bowling, CASE7_WhenRolledLastFrameWithoutStrikeOrSpareFinalScoreIsCorrectSinglePlayer);
}

#ifdef __cplusplus
}
#endif
