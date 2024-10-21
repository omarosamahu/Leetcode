#include <iostream>
#include <vector>
#include <unordered_map>

int removeElement(std::vector<int>& nums, int val) {
    for(int i=0;i<nums.size();++i){
        if(nums[i] == val){
            nums.erase(nums.begin() + i);
        }
    }
    return nums.size();
}
int main(int argc, char const *argv[])
{
    /* code */
    // std::vector<int> input{0,1,2,2,3,0,4,2};
    // // std::cout << removeElement(input,2) << "\n";

    // for(int i=0;i<input.size();++i){
    //     std::cout << input[i] << "\n";
    // }

    std::unordered_map<bool,bool> bmap;
    std::cout << (bmap[true] == bmap[false]) << "\n";

    return 0;
}
