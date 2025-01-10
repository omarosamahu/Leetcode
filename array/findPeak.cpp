#include <iostream>
#include <vector>
#include <climits>
int findPeakElement(std::vector<int> &nums)
{
    nums.insert(nums.begin(), INT_MIN);
    nums.push_back(INT_MIN);

    int pInx;

    for (size_t i = 1; i < (nums.size() - 1); i++)
    {
        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
        {
            pInx = i;
            return i;
        }
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    return 0;
}
