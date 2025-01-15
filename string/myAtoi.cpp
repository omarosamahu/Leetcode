#include <iostream>
#include <unordered_set>
#include <vector>

int myAtoi(std::string s)
{
    int num;
    std::unordered_set<int> digits{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (size_t i = 0; i < s.size(); ++i)
    {
        if ((i == 0) && (s[i] == ' ' || s[i] == '-' || s[i] == '+'))
        {
            continue;
        }
        char x = s[i] - '0';

        if (digits.find(x) == digits.end())
        {
            return 0;
        }
        num = num * 10 + x;
    }
    return s[0] == '-' ? (num * -1) : num;
}
int main(int argc, char const *argv[])
{
    std::string input = "-42";

    auto result = myAtoi(input);
    std::cout << "Result is: " << result << "\n";

    return 0;
}
