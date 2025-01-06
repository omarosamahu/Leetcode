#include "memory_allocator.h"

Allocator::Allocator(uint16_t n) : m_array(new int[n]), array_length{n}, idx{0}
{
    std::fill(m_array, m_array + n, INT_MAX);
    for (int i = 0; i < n; ++i)
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

int Allocator::allocate(int size, int id, bool isConsecutive)
{
    if ((idx + size) >= array_length)
    {
        std::cerr << "Insufficient memory\n";
        return -1;
    };

    return isConsecutive ? appendConsecutive(size, id) + 1 : addToFreeIndeces(size, id);
}

int Allocator::getFreeSlots(int size)
{
    int count = 0;
    int pidx;
    for (size_t i = 0; i < array_length; i++)
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

int Allocator::freeMemory(int id)
{
    int freeCount = 0;
    for (int i = 0; i < array_length; ++i)
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

void Allocator::display()
{
    for (size_t i = 0; i < array_length; i++)
    {
        std::cout << m_array[i] << ((i < (array_length - 1)) ? ',' : '\n');
    }
}

int Allocator::addToFreeIndeces(uint32_t size, int id)
{
    bool firstHit = false;
    int pIdx = 0;

    for (size_t i = 0; i < array_length; i++)
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

int Allocator::appendConsecutive(uint32_t size, int id)
{
    int endIndex = getFreeSlots(size);
    while (size > 0)
    {
        m_array[endIndex] = id;
        freeIndeces[endIndex--] = false;
        size--;
        idx++;
    }
    return endIndex;
}
