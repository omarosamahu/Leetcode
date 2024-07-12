#include <iostream>

// Input: Mississippi
// Result: M

// Input: test

// Output: test

// Input:  rattat

// Output: rt
std::string removeAdjancentDuplicates(std::string input){
    std::string output;
    output += input[0];
    for(int i=1;i<input.size();++i){
        if(input[i] == output.back()){
            output.pop_back();
        }
        else{
            output.push_back(input[i]);
        }
    }
    return output;
}
int main(int argc, char const *argv[])
{
    std::string input = "rattat";
    std::cout << removeAdjancentDuplicates(input) << "\n";
    return 0;
}
