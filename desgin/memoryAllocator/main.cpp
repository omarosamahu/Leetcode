#include "memory_allocator.h"

bool getArgs(char const *args[])
{
    return (strcmp(args[1], "-consecutive") == 0) ? true : (strcmp(args[1], "-freeIndeces") == 0) ? false
                                                                                                  : throw std::invalid_argument("Invalid Argument");
}

void Test1(char const *argv[])
{
    auto allocatorPtr = std::make_unique<Allocator>(10);
    std::cout << allocatorPtr->allocate(1, 1, getArgs(argv)) << ",";
    std::cout << allocatorPtr->allocate(1, 2, getArgs(argv)) << ",";
    std::cout << allocatorPtr->allocate(1, 3, getArgs(argv)) << ",";
    std::cout << allocatorPtr->freeMemory(2) << ",";
    std::cout << allocatorPtr->freeMemory(1) << ",";
    std::cout << allocatorPtr->allocate(3, 4, getArgs(argv)) << ",";
    std::cout << allocatorPtr->allocate(1, 1, getArgs(argv)) << ",";
    std::cout << allocatorPtr->allocate(1, 1, getArgs(argv)) << ",";
    std::cout << allocatorPtr->allocate(2, 6, getArgs(argv)) << ",";
    std::cout << allocatorPtr->allocate(1, 7, getArgs(argv)) << "\n";
    allocatorPtr->display();
}

void Test2(char const *argv[])
{
    auto allocatorPtr = std::make_unique<Allocator>(7);
    std::cout << allocatorPtr->allocate(7, 8, getArgs(argv)) << ",";
    std::cout << allocatorPtr->allocate(8, 7, getArgs(argv)) << ",";
    std::cout << allocatorPtr->allocate(6, 2, getArgs(argv)) << ",";
    std::cout << allocatorPtr->freeMemory(9) << ",";
    std::cout << allocatorPtr->freeMemory(8) << ",";
    std::cout << allocatorPtr->allocate(7, 6, getArgs(argv)) << ",";
    std::cout << allocatorPtr->freeMemory(9) << ",";
    std::cout << allocatorPtr->allocate(10, 9, getArgs(argv)) << "\n";
    allocatorPtr->display();
}

void Test3(char const *argv[])
{
    auto allocatorPtr = std::make_unique<Allocator>(50);
    std::cout << allocatorPtr->allocate(12, 6, getArgs(argv)) << ",";
    std::cout << allocatorPtr->allocate(28, 16, getArgs(argv)) << ",";
    std::cout << allocatorPtr->allocate(17, 23, getArgs(argv)) << ",";
    std::cout << allocatorPtr->allocate(50, 23, getArgs(argv)) << ",";
    std::cout << allocatorPtr->freeMemory(6) << ",";
    std::cout << allocatorPtr->freeMemory(10) << ",";
    std::cout << allocatorPtr->freeMemory(10) << ",";
    std::cout << allocatorPtr->allocate(16, 8, getArgs(argv)) << ",";
    std::cout << allocatorPtr->allocate(17, 41, getArgs(argv)) << ",";
    std::cout << allocatorPtr->allocate(44, 27, getArgs(argv)) << ",";
    std::cout << allocatorPtr->allocate(12, 45, getArgs(argv)) << ",";
    std::cout << allocatorPtr->freeMemory(33) << ",";
    std::cout << allocatorPtr->freeMemory(8) << ",";
    std::cout << allocatorPtr->freeMemory(16) << ",";
    std::cout << allocatorPtr->freeMemory(23) << ",";
    std::cout << allocatorPtr->freeMemory(23) << ",";
    std::cout << allocatorPtr->freeMemory(23) << ",";
    std::cout << allocatorPtr->freeMemory(29) << ",";
    std::cout << allocatorPtr->allocate(38, 32, getArgs(argv)) << ",";
    std::cout << allocatorPtr->freeMemory(29) << ",";
    std::cout << allocatorPtr->freeMemory(6) << ",";
    std::cout << allocatorPtr->allocate(40, 11, getArgs(argv)) << ",";
    std::cout << allocatorPtr->freeMemory(16) << ",";
    std::cout << allocatorPtr->allocate(22, 33, getArgs(argv)) << ",";
    std::cout << allocatorPtr->allocate(27, 5, getArgs(argv)) << ",";
    std::cout << allocatorPtr->freeMemory(3) << ",";
    std::cout << allocatorPtr->freeMemory(10) << ",";
    std::cout << allocatorPtr->freeMemory(29) << ",";
    std::cout << allocatorPtr->allocate(16, 14, getArgs(argv)) << ",";
    std::cout << allocatorPtr->allocate(46, 47, getArgs(argv)) << ",";
    std::cout << allocatorPtr->allocate(48, 9, getArgs(argv)) << ",";
    std::cout << allocatorPtr->allocate(36, 17, getArgs(argv)) << ",";
    std::cout << allocatorPtr->freeMemory(33) << ",";
    std::cout << allocatorPtr->allocate(14, 24, getArgs(argv)) << ",";
    std::cout << allocatorPtr->freeMemory(16) << ",";
    std::cout << allocatorPtr->freeMemory(8) << ",";
    std::cout << allocatorPtr->allocate(2, 50, getArgs(argv)) << ",";
    std::cout << allocatorPtr->allocate(31, 36, getArgs(argv)) << ",";
    std::cout << allocatorPtr->allocate(17, 45, getArgs(argv)) << ",";
    std::cout << allocatorPtr->allocate(46, 31, getArgs(argv)) << ",";
    std::cout << allocatorPtr->allocate(2, 6, getArgs(argv)) << ",";
    std::cout << allocatorPtr->allocate(16, 2, getArgs(argv)) << ",";
    std::cout << allocatorPtr->allocate(39, 30, getArgs(argv)) << ",";
    std::cout << allocatorPtr->freeMemory(33) << ",";
    std::cout << allocatorPtr->freeMemory(45) << ",";
    std::cout << allocatorPtr->freeMemory(30) << ",";
    std::cout << allocatorPtr->freeMemory(27) << "\n";
    allocatorPtr->display();
}

int main(int argc, char const *argv[])
{
    Test1(argv);
    Test2(argv);
    Test3(argv);
    return 0;
}
/*

*/
