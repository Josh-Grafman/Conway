#include "conway.hpp"

using namespace conway;

Board::Board() {}

Board::~Board() {}

State Board::GetNewState(State current, int liveNeighbors) const {
  State result = current;

  switch (current) {
    case ALIVE:
      if (liveNeighbors < 2 || liveNeighbors > 3)
        result = DEAD;
      break;
    case DEAD:
      if (liveNeighbors == 3)
        result = ALIVE;
      break;
    default:
      break;
  }

  return result;
}
