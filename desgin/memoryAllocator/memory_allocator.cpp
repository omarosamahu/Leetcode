#include "memory_allocator.h"

Allocator::Allocator(uint16_t n) : m_array(new int[n]), memoryLength{n}, freePlaces{n}
{
    std::fill(m_array, m_array + n, INT_MAX);
    for (uint16_t i{0U}; i < n; ++i)
    {
        freeIndeces[i] = true;
    }
}

Allocator::~Allocator()
{
    if (m_array != nullptr)
    {
        delete[] m_array;
    }
}

int16_t Allocator::allocate(uint16_t size, int16_t id, bool isConsecutive)
{
    if (size > freePlaces)
    {
        std::cerr << "Insufficient memory\n";
        return -1;
    }

    return isConsecutive ? appendConsecutive(size, id) : addToFreeIndeces(size, id);
}

int16_t Allocator::getFreeSlots(uint16_t size)
{
    uint16_t count{0U};
    uint16_t endIndx{0U};
    for (uint16_t i{0U}; i < memoryLength; i++)
    {
        if (freeIndeces[i])
        {
            if (++count == size)
            {
                endIndx = i;
                return endIndx;
            }
        }
        else
        {
            count = 0;
        }
    }
    return -1;
}

uint16_t Allocator::freeMemory(int16_t id)
{
    uint16_t freeCount{0U};
    for (uint16_t i{0U}; i < memoryLength; ++i)
    {
        if (m_array[i] == id)
        {
            m_array[i] = INT_MAX;
            freeIndeces[i] = true;
            ++freePlaces;
            ++freeCount;
        }
    }
    return freeCount;
}

int16_t Allocator::addToFreeIndeces(uint16_t size, int16_t id)
{
    bool firstHit = false;
    int16_t idx{0};

    for (uint16_t i{0U}; i < memoryLength; i++)
    {
        if (size > 0 && freeIndeces[i])
        {
            if (!firstHit)
            {
                idx = i;
                firstHit = true;
            }
            m_array[i] = id;
            freeIndeces[i] = false;
            --size;
            --freePlaces;
        }
    }
    return idx;
}

int16_t Allocator::appendConsecutive(uint16_t size, int16_t id)
{
    int16_t endIndex{getFreeSlots(size)};
    if (endIndex == -1)
    {
        return -1;
    }
    while (size > 0)
    {
        m_array[endIndex] = id;
        freeIndeces[endIndex--] = false;
        --freePlaces;
        --size;
    }
    return endIndex + 1;
}

uint16_t Allocator::size()
{
    return (memoryLength - freePlaces);
}

void Allocator::display()
{
    for (int i{0U}; i < memoryLength; i++)
    {
        std::cout << m_array[i] << ((i < (memoryLength - 1)) ? ',' : '\n');
    }
}
