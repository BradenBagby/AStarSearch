#include "state.h"

State::State(int a, int b, int c, int d, int e, int f, int g, int h, int i) : board{
                                                                                  {a, b, c}, {d, e, f}, {g, h, i}} {};

State::State(int board[3][3])
{
    deepCopyBoard(this->board, board);
}

State::State(State *lastState, Action *action)
{
    // duplicate board
    deepCopyBoard(this->board, board);

    // perform action
    move(this->board, action->direction, action->coords);
}

void deepCopyBoard(int copyFrom[3][3], int copyTo[3][3])
{
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            copyTo[x][y] = copyFrom[x][y];
        }
    }
}

// make a single move
// only works if the space its moving to is 0, otherwise throws an exception
void move(int board[3][3], Direction direction, Coords coords)
{

    Coords *switchCoords;
    switch (direction)
    {
    case Direction::left:
        switchCoords = new Coords(coords.x - 1, coords.y);
        break;
    case Direction::right:
        switchCoords = new Coords(coords.x + 1, coords.y);
        break;
    case Direction::up:
        switchCoords = new Coords(coords.x, coords.y + 1);
        break;
    case Direction::down:
        switchCoords = new Coords(coords.x, coords.y - 1);
        break;
    default:
        break;
    }

    // verify move is good
    if (switchCoords->x < 0 || switchCoords->x >= 3 || switchCoords->y < 0 || switchCoords->y >= 3)
    {
        throw "move out of bounds ";
    }

    if (board[switchCoords->x][switchCoords->y] != 0)
    {
        throw "cannot move to non 0 square";
    }

    // flip with the 0 to perform the move
    board[switchCoords->x][switchCoords->y] = board[coords.x][coords.y];
    board[coords.x][coords.y] = 0;

    delete switchCoords;
}