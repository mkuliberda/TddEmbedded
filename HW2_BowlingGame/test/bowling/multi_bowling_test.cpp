#include "MultiplayerBowlingGame.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "unity/fixture/unity_fixture.h"

TEST_GROUP(multi_bowling);

TEST_SETUP(multi_bowling)
{
    /* Init before every test */
}

TEST_TEAR_DOWN(multi_bowling)
{
    /* Cleanup after every test */
}

TEST(multi_bowling, CASE1_WhenTwoPlayersRollOnesOnFirstFrameTheScoreIsTwoForEach)
{   
    MultiplayerBowlingGame game;
    game.addPlayer("Player1");
    game.addPlayer("Player2");

    for (int pl_nbr = 0; pl_nbr<2; pl_nbr++){
        Player current_player = game.getCurrentPlayer();
        game.roll(1, current_player.name);
        game.roll(1, current_player.name);
    }

    TEST_ASSERT_EQUAL(2, game.score("Player1"));
    TEST_ASSERT_EQUAL(2, game.score("Player2"));
}

#ifdef __cplusplus
}
#endif
