#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> comSum;
        std::unordered_set<int> mSet;

        for (size_t i = 0; i < candidates.size(); i++)
        {
            mSet.insert(candidates[i]);
        }

        for (size_t i = 0; i < candidates.size(); i++)
        {
            int sum = 0;
            int sub = target;
            std::vector<int> tmp;
            while (sum < target)
            {
                
                sub = sub - candidates[i];
                if(mSet.find(sub) == mSet.end()){
                    tmp.push_back(candidates[i]);
                    sum += candidates[i];
                }
                else{
                    tmp.push_back(candidates[i]);
                    tmp.push_back(sub);
                    sum += candidates[i];
                    sum += sub;
                }

            }
            if(sum == target)
            comSum.push_back(tmp);

        }

        return comSum;
}

int main(int argc, char const *argv[])
{
    std::vector<int> candidates = {2,3,5};
    auto result = combinationSum(candidates,8);

    for(const auto& item : result){
        for(int i=0;i<item.size();++i){
            if(i != (item.size() - 1)){
                std::cout << item[i] << ',';
            }
            else{
                std::cout << item[i] << "\n";
            }
        }
    }

    return 0;
}
