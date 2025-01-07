#include "memory_allocator.h"

bool getArgs(char const *args[])
{
    return (strcmp(args[1], "-consecutive") == 0) ? true : (strcmp(args[1], "-freeIndeces") == 0) ? false
                                                                                                  : throw std::invalid_argument("Invalid Argument");
}
int main(int argc, char const *argv[])
{
    auto allocatorPtr = std::make_unique<Allocator>(50);
    allocatorPtr->allocate(12, 6);
    allocatorPtr->allocate(28, 16);
    allocatorPtr->allocate(17, 23);
    allocatorPtr->allocate(50, 23);
    allocatorPtr->freeMemory(6);
    allocatorPtr->freeMemory(10);
    allocatorPtr->freeMemory(10);
    allocatorPtr->allocate(16, 8);
    allocatorPtr->allocate(17, 41);
    allocatorPtr->allocate(44, 27);
    allocatorPtr->allocate(12, 45);
    allocatorPtr->freeMemory(33);
    allocatorPtr->freeMemory(8);
    allocatorPtr->freeMemory(16);
    allocatorPtr->freeMemory(23);
    allocatorPtr->freeMemory(23);
    allocatorPtr->freeMemory(23);
    allocatorPtr->freeMemory(29);
    allocatorPtr->allocate(38, 32);
    allocatorPtr->freeMemory(29);
    allocatorPtr->freeMemory(6);
    allocatorPtr->allocate(40, 11);
    allocatorPtr->freeMemory(16);
    allocatorPtr->allocate(22, 33);
    allocatorPtr->allocate(27, 5);
    allocatorPtr->freeMemory(3);
    allocatorPtr->freeMemory(10);
    allocatorPtr->freeMemory(29);
    allocatorPtr->allocate(16, 14);
    allocatorPtr->allocate(46, 47);
    allocatorPtr->allocate(48, 9);
    allocatorPtr->allocate(36, 17);
    allocatorPtr->freeMemory(33);
    allocatorPtr->allocate(14, 24);
    allocatorPtr->freeMemory(16);
    allocatorPtr->freeMemory(8);
    allocatorPtr->allocate(2, 50);
    allocatorPtr->allocate(31, 36);
    allocatorPtr->allocate(17, 45);
    allocatorPtr->allocate(46, 31);
    allocatorPtr->allocate(2, 6);
    allocatorPtr->allocate(16, 2);
    allocatorPtr->allocate(39, 30);
    allocatorPtr->freeMemory(33);
    allocatorPtr->freeMemory(45);
    allocatorPtr->freeMemory(30);
    allocatorPtr->freeMemory(27);
    allocatorPtr->display();
    return 0;
}

/*
auto allocatorPtr = std::make_unique<Allocator>(10);

    allocatorPtr->allocate(1, 1, getArgs(argv));
    allocatorPtr->allocate(1, 2, getArgs(argv));
    allocatorPtr->allocate(1, 3, getArgs(argv));
    allocatorPtr->freeMemory(2);
    allocatorPtr->freeMemory(1);
    allocatorPtr->allocate(3, 4, getArgs(argv));
    allocatorPtr->allocate(3, 1, getArgs(argv));
    allocatorPtr->allocate(2, 6, getArgs(argv));
    allocatorPtr->allocate(1, 7, getArgs(argv));
    allocatorPtr->display();
*/