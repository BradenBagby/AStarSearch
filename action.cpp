#include "action.h"

Coords::Coords(int x, int y)
{
    this->x = x;
    this->y = y;
}

Action::Action(Coords coords, Direction direction) : coords(coords)
{
    this->direction = direction;
}
