#include <iostream>
#include <vector>

bool repeatedSubstringPattern(std::string s)
{
    if (s.size() == 1)
    {
        return false;
    }

    int l = s.size() / 2;

    auto div = l / 2;
    if (l % 2 != 0)
    {
        l = l - 1;
    }

    int i = 0;
    while (l < s.size())
    {
        if (s[i++] != s[l++])
        {
            return false;
        }
    }

    return true;
}
int main(int argc, char const *argv[])
{
    std::cout << repeatedSubstringPattern("abaababaab") << "\n";
    return 0;
}
