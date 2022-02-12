#include "SinglePlayerGame.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "unity/fixture/unity_fixture.h"

TEST_GROUP(single_bowling);

TEST_SETUP(single_bowling)
{
    /* Init before every test */
}

TEST_TEAR_DOWN(single_bowling)
{
    /* Cleanup after every test */
}

TEST(single_bowling, CASE1_WhenRolledOneScoreIsOneSinglePlayer)
{    
    SinglePlayerGame player1_scoring;

    player1_scoring.roll(1);

    TEST_ASSERT_EQUAL(1, player1_scoring.score());
}

TEST(single_bowling, CASE2_WhenRolledTwoFramesWithOneStrikeOnFirstRollPartialScoreIsCorrectSinglePlayer)
{    
    SinglePlayerGame player1_scoring;

    player1_scoring.roll(10);
    player1_scoring.roll(1);
    player1_scoring.roll(2);

    TEST_ASSERT_EQUAL(16, player1_scoring.score());
}

TEST(single_bowling, CASE3_WhenRolledTwoFramesWithOneSpareOnFirstFramePartialScoreIsCorrectSinglePlayer)
{    
    SinglePlayerGame player1_scoring;

    player1_scoring.roll(0);
    player1_scoring.roll(10);
    player1_scoring.roll(1);
    player1_scoring.roll(2);

    TEST_ASSERT_EQUAL(14, player1_scoring.score());
}

TEST(single_bowling, CASE4_WhenRolledLastFrameWithSingleStrikeFinalScoreIsCorrectSinglePlayer)
{    
    SinglePlayerGame player1_scoring;
    uint32_t expected{0};

    for (int i=0; i<18; i++){
        player1_scoring.roll(1);
        expected+=1;
    }
    player1_scoring.roll(10);
    expected+=10;
    player1_scoring.roll(2);
    expected+=2;
    player1_scoring.roll(3);
    expected+=3;

    TEST_ASSERT_EQUAL(expected, player1_scoring.score());
}

TEST(single_bowling, CASE5_WhenRolledTenFramesWithSparesAndStrikesFinalScoreIsCorrectSinglePlayer)
{    
    SinglePlayerGame player1_scoring;
    uint32_t expected{0};

    player1_scoring.roll(0);
    expected+=0;
 
    player1_scoring.roll(10);
    expected+=10;
 
    player1_scoring.roll(1);
    expected+=(2*1);
 
    player1_scoring.roll(2);
    expected+=2;
 
    player1_scoring.roll(10);
    expected+=10;
 
    player1_scoring.roll(2);
    expected+=(2*2);
 
    player1_scoring.roll(2);
    expected+=(2*2);
 
    for(int i=0; i<13; i++){
        player1_scoring.roll(0);
        expected+=0;
     
    }
 
    TEST_ASSERT_EQUAL(expected, player1_scoring.score());
}

TEST(single_bowling, CASE6_WhenRolledLastFrameWithDoubleStrikeFinalScoreIsCorrectSinglePlayer)
{    
    SinglePlayerGame player1_scoring;
    uint32_t expected{0};

    for (int i=0; i<18; i++){
        player1_scoring.roll(1);
        expected+=1;
    }
    player1_scoring.roll(10);
    expected+=10;
    player1_scoring.roll(10);
    expected+=10;
    player1_scoring.roll(3);
    expected+=3;

    TEST_ASSERT_EQUAL(expected, player1_scoring.score());
}

TEST(single_bowling, CASE7_WhenRolledLastFrameWithoutStrikeOrSpareFinalScoreIsCorrectSinglePlayer)
{    
    SinglePlayerGame player1_scoring;
    uint32_t expected{0};

    for (int i=0; i<20; i++){
        player1_scoring.roll(1);
        expected+=1;
    }
    player1_scoring.roll(3);

    TEST_ASSERT_EQUAL(expected, player1_scoring.score());
}



#ifdef __cplusplus
}
#endif
