#include <iostream>
#include <unordered_set>
#include <vector>

std::unordered_set<int> digits {0,1,2,3,4,5,6,7,8,9};
int myAtoi(std::string s) {
        int number = 0;

        int startPos = 0;
        while (s[startPos] == ' ')
        {
            ++startPos;
        }

        bool nesgative = 0;
        if(s.find("0-") != std::string::npos){
            return 0;
        }

        if(s[startPos] == '-'){
            nesgative = true;
            ++startPos;
        }else if(s[startPos] == '+'){
            ++startPos;
        }

        if(s[startPos] == '0'){
            ++startPos;
        }
        
        for(int i=startPos;i<s.size();++i){
            char digit = s[i] - '0';

            if(digits.find(digit) == digits.end()){
                break;
            }
            else{
                number = number * 10 + digit;
            }
        }
        return !nesgative ? number : (number * -1);
} 
int main(int argc, char const *argv[])
{
    std::string input = "word of 973";

    auto result = myAtoi(input);
    std::cout << "Result is: " << result << "\n";

    return 0;
}
