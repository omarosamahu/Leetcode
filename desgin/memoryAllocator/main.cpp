#include "memory_allocator.h"

bool getArgs(char const *args[])
{
    return (strcmp(args[1], "-consecutive") == 0) ? true : (strcmp(args[1], "-freeIndeces") == 0) ? false
                                                                                                  : throw std::invalid_argument("Invalid Argument");
}
int main(int argc, char const *argv[])
{
    auto allocatorPtr = std::make_unique<Allocator>(10);

    allocatorPtr->allocate(1, 1, getArgs(argv));
    allocatorPtr->allocate(1, 2, getArgs(argv));
    allocatorPtr->allocate(1, 3, getArgs(argv));
    allocatorPtr->freeMemory(2);
    allocatorPtr->allocate(3, 4, getArgs(argv));
    allocatorPtr->allocate(1, 1, getArgs(argv));
    allocatorPtr->allocate(1, 1, getArgs(argv));
    allocatorPtr->display();
    return 0;
}
