#include "state.h"
#include "node.h"
#include "action.h"
#include <iostream>

void testStates();

int main()
{
    std::cout << "starting" << std::endl;
    testStates();

}




void testStates(){
    State* startState = new State(0,1,2,3,4,5,6,7,8);
    std::cout << *startState << std::endl;
}