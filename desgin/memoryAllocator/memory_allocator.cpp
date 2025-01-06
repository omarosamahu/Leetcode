#include "memory_allocator.h"

Allocator::Allocator(uint16_t n) : m_array(new int[n]), array_length{n}, idx{0}
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

uint16_t Allocator::allocate(int size, int id, bool isConsecutive)
{
    if ((idx + size) >= array_length)
    {
        std::cerr << "Insufficient memory\n";
        return -1;
    };

    return isConsecutive ? appendConsecutive(size, id) + 1 : addToFreeIndeces(size, id);
}

uint16_t Allocator::getFreeSlots(int size)
{
    uint16_t count{0U};
    uint16_t pidx{0U};
    for (uint16_t i{0U}; i < array_length; i++)
    {
        if (freeIndeces[i])
        {
            if (++count == size)
            {
                pidx = i;
                break;
            }
        }
        else
        {
            count = 0;
        }
    }
    return pidx;
}

uint16_t Allocator::freeMemory(int id)
{
    uint16_t freeCount{0U};
    for (uint16_t i{0U}; i < array_length; ++i)
    {
        if (m_array[i] == id)
        {
            m_array[i] = INT_MAX;
            freeIndeces[i] = true;
            ++freeCount;
            --idx;
        }
    }
    return freeCount;
}

uint16_t Allocator::addToFreeIndeces(uint32_t size, int id)
{
    bool firstHit = false;
    uint16_t pIdx{0U};

    for (uint16_t i{0U}; i < array_length; i++)
    {
        if (size > 0 && freeIndeces[i])
        {
            if (!firstHit)
            {
                pIdx = i;
                firstHit = true;
            }
            m_array[i] = id;
            freeIndeces[i] = false;
            --size;
            ++idx;
        }
    }
    return pIdx;
}

uint16_t Allocator::appendConsecutive(uint32_t size, int id)
{
    uint16_t endIndex{getFreeSlots(size)};
    while (size > 0)
    {
        m_array[endIndex] = id;
        freeIndeces[endIndex--] = false;
        size--;
        idx++;
    }
    return endIndex;
}

void Allocator::display()
{
    for (uint16_t i{0U}; i < array_length; i++)
    {
        std::cout << m_array[i] << ((i < (array_length - 1)) ? ',' : '\n');
    }
}
