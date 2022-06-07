#include <gtest/gtest.h>
#include "../lib/conway.hpp"

using namespace conway;

//Any live cell with fewer than two live neighbors dies
TEST(RulesTests, AliveLessThanTwoNeighborsDies) {

  //arrange
  Board B;
  State current = ALIVE;

  //act
  for( int liveNeighbors = 0; liveNeighbors < 2; liveNeighbors++ ) {
    State result = B.GetNewState(current, liveNeighbors);

    //assert
    EXPECT_EQ(result, DEAD);
  }
}

//Any live cell with two ot three live neighbors lives
TEST(RulesTests, AliveTwoOrThreeNeighborsLives) {

  //arrange
  Board B;
  State current = ALIVE;

  //act
  for ( int liveNeighbors = 2; liveNeighbors < 4; liveNeighbors++  ) {
    State result = B.GetNewState(current, liveNeighbors);

    //assert
    EXPECT_EQ(result, ALIVE);
  }
}

//Any live cell with more than three live neighbors dies
TEST(RulesTests, AliveMoreThanThreeDies) {

  //arrange
  Board b;
  State current = ALIVE;

  //act
  for (int liveNeighbors = 4; liveNeighbors <= 8; liveNeighbors++) {
    State result = b.GetNewState(current, liveNeighbors);

    //assert
    EXPECT_EQ(result, DEAD);
  }

}

//Any dead cell with exactly three live neighbors becomes alive
TEST(RulesTests, DeadThreeNeighborsLives) {

  //arrange
  Board b;
  State current = DEAD;

  //act
  State result = b.GetNewState(current, 3);

  //assert
  EXPECT_EQ(result, ALIVE);
}
