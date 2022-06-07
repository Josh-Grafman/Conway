namespace conway {
  enum State { DEAD, ALIVE, ERRSTATE };

  class Board {
    public:
      Board();
      ~Board();

      State GetNewState(State, int) const;
  };
}
