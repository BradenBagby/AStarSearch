

#ifndef action_h
#define action_h

enum class Direction
{
    left,
    right,
    up,
    down,
};


class Coords
{
public:
    int x;
    int y;
    Coords(int x, int y);
};

// move coords in direction
class Action
{
public:
    Coords coords;
    Direction direction;
    Action(Coords coords, Direction direction);
};
#endif