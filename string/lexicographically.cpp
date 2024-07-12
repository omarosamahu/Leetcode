#include <iostream>
#include <list>
#include <vector>


bool checkPalindrome(const std::string& str, int i, int j){
    while(i <= j){
        if(str[i++] != str[j--]){
            return false;
        }
    }
    return true;
}

std::string longestPalindrome(std::string str){
    std::vector<std::string> palindromes;

    for(int i=0;i<str.size();++i){
        for(int j=i+1;j<str.size();++j){
            if(checkPalindrome(str,i,j)){
                palindromes.push_back(str.substr(i,j+1));
            }
        }   
    }

    for(const auto& word : palindromes){
        std::cout << word << "\n";
    }
    return "";
}
int main(int argc, char const *argv[])
{
    std::string input = "aabbaa";

    longestPalindrome(input);
    std::cout << input << "\n";

    return 0;
}
