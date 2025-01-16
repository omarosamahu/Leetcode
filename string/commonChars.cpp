#include <iostream>
#include <vector>

void countChars(const std::string &word, std::vector<std::vector<int>> &freq, bool stop = false)
{
    for (size_t i = 0; i < word.size(); i++)
    {
        freq[word[i] - 'a'][0]++;
    }

    if (!stop)
    {
        for (int i = 0; i < word.size(); ++i)
        {
            if (freq[word[i] - 'a'][0] != 0)
                freq[word[i] - 'a'].insert(freq[word[i] - 'a'].begin(), 0);
        }
    }
}

std::vector<std::string> commonChars(std::vector<std::string> &words)
{
    std::vector<std::vector<int>> frequencies(26, std::vector<int>(1, 0));
    std::vector<std::string> result;
    int n = words.size() - 1;
    for (int i = 0; i < words.size(); ++i)
    {
        if (i == n)
        {
            countChars(words[i], frequencies, true);
        }
        else
        {
            countChars(words[i], frequencies);
        }
    }

    for (int i = 0; i < frequencies.size(); ++i)
    {
        auto data = frequencies[i];

        if (data.size() < words.size())
        {
            continue;
        }
        else
        {
            // Get the minumum and add the corresponding char to that index
            char c = i + 'a';
            int min = data[0];
            for (int idx = 1; idx < data.size(); ++idx)
            {
                min = std::min(min, data[idx]);
            }
            for (int idx = 0; idx < min; ++idx)
            {
                result.push_back(std::string("") + c);
            }
        }
    }

    return result;
}
int main(int argc, char const *argv[])
{
    std::vector<std::string> words = {
        "cool", "lock", "cook"};

    auto result = commonChars(words);
    for (int i = 0; i < result.size(); ++i)
    {
        if (i != result.size() - 1)
        {
            std::cout << result[i] << ',';
        }
        else
        {
            std::cout << result[i] << '\n';
        }
    }
    return 0;
}
