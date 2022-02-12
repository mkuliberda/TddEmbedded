#include "Game.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "unity/fixture/unity_fixture.h"

TEST_GROUP(bowling);

TEST_SETUP(bowling)
{
    /* Init before every test */
}

TEST_TEAR_DOWN(bowling)
{
    /* Cleanup after every test */
}

TEST(bowling, CASE1_WhenRolledOneScoreIsOneSinglePlayer)
{    
    Game player1_scoring;

    player1_scoring.roll(1);

    TEST_ASSERT_EQUAL(1, player1_scoring.score());
}

TEST(bowling, CASE2_WhenRolledTwoFramesWithOneStrikeOnFirstRollPartialScoreIsCorrectSinglePlayer)
{    
    Game player1_scoring;

    player1_scoring.roll(10);
    player1_scoring.roll(1);
    player1_scoring.roll(2);

    TEST_ASSERT_EQUAL(16, player1_scoring.score());
}

TEST(bowling, CASE3_WhenRolledTwoFramesWithOneSpareOnFirstFramePartialScoreIsCorrectSinglePlayer)
{    
    Game player1_scoring;

    player1_scoring.roll(0);
    player1_scoring.roll(10);
    player1_scoring.roll(1);
    player1_scoring.roll(2);

    TEST_ASSERT_EQUAL(14, player1_scoring.score());
}

TEST(bowling, CASE4_WhenRolledLastFrameWithSingleStrikeFinalScoreIsCorrectSinglePlayer)
{    
    Game player1_scoring;
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

TEST(bowling, CASE5_WhenRolledTenFramesWithSparesAndStrikesFinalScoreIsCorrectSinglePlayer)
{    
    Game player1_scoring;
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

TEST(bowling, CASE6_WhenRolledLastFrameWithDoubleStrikeFinalScoreIsCorrectSinglePlayer)
{    
    Game player1_scoring;
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

TEST(bowling, CASE7_WhenRolledLastFrameWithoutStrikeOrSpareFinalScoreIsCorrectSinglePlayer)
{    
    Game player1_scoring;
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
