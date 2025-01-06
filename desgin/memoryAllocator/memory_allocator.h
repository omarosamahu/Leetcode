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

    uint16_t allocate(int size, int id, bool isConsecutive = true);
    uint16_t freeMemory(int id);
    uint16_t getFreeSlots(int size);
    uint16_t addToFreeIndeces(uint32_t size, int id);
    uint16_t appendConsecutive(uint32_t size, int id);
    void display();

private:
    int *m_array{nullptr};
    uint16_t currentSize;
    uint16_t arrayLength;
    std::unordered_map<int, bool> freeIndeces;
};