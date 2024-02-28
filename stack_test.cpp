#include "stack.h"
#include <iostream>

int main() {

     Stack<int> stack;

    std::cout << "Pushing elements onto the stack...\n";
    stack.Stack::push(1);
    stack.Stack::push(2);
    stack.Stack::push(3);

    std::cout << "Current stack size: " << stack.size() << std::endl;

    


    return 0;

}