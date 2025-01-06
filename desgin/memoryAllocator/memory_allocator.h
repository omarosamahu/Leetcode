#pragma once

#include <iostream>
#include <climits>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_map>
#include <memory>
#include <algorithm>

class Allocator
{
public:
    Allocator() = default;
    Allocator(uint16_t n);
    ~Allocator();

    int allocate(int size, int id, bool isConsecutive = true);
    int freeMemory(int id);
    int getFreeSlots(int size);
    void display();

    int addToFreeIndeces(uint32_t size, int id);
    int appendConsecutive(uint32_t size, int id);

private:
    int *m_array{nullptr};
    uint16_t idx;
    uint16_t array_length;
    std::unordered_map<int, bool> freeIndeces;
};