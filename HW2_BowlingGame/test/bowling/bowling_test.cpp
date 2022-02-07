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

TEST(bowling, WhenRolled1ScoreIs1)
{    
    Game player1_scoring;

    player1_scoring.roll(1);
    TEST_ASSERT_EQUAL(1, player1_scoring.score());
}

#ifdef __cplusplus
}
#endif
