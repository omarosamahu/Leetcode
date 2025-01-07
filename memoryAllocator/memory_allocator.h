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
    explicit Allocator(uint16_t n);
    ~Allocator();
    Allocator(const Allocator &) = delete;
    Allocator &operator=(const Allocator &) = delete;
    Allocator(Allocator &&) = delete;
    Allocator &operator=(Allocator &&) = delete;

    int16_t allocate(uint16_t size, int16_t id, bool isConsecutive = true);
    int16_t getFreeSlots(uint16_t size);
    int16_t addToFreeIndeces(uint16_t size, int16_t id);
    int16_t appendConsecutive(uint16_t size, int16_t id);
    uint16_t size();
    uint16_t freeMemory(int16_t id);
    void display();

private:
    int *m_array{nullptr};
    uint16_t freePlaces;
    uint16_t memoryLength;
    std::unordered_map<uint16_t, bool> freeIndeces;
};