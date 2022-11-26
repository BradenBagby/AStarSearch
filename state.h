
#ifndef state_h
#define state_h

#include "action.h"
#include <iostream>

// state of the 3x3 board with nubmers for each tile
class State
{
public:
    int board[3][3];

    // initialize a state manually
    State(int a, int b, int c, int d, int e, int f, int g, int h, int i);

    // initialize a state from an action
    State(State *oldState, Action *action);

    // initialize from board array
    State(int board[3][3]);

    inline friend std::ostream & operator<<(std::ostream & _stream, State const & mc) {
        _stream << "tesstttt" << std::endl;
        return _stream;
    }
};
#endif