#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>

// std::string longestPalindrome(std::string word){
//     int start = 0;
//     int end = 0;

//     for(int i=0;i<word.size();++i){
//         start = i;
//         end = start + 1;
//         for(int j = end;j<word.size();++j){
//             if(word[start] == word[j]){
//                 end = j;
//                 break;
//             }
//         }    
//     }
// }

std::string mostCommonWord(std::string paragraph, std::vector<std::string>& banned){
    std::unordered_map<std::string, int> hashmap;
        for(int i=0;i<paragraph.size();++i){
            if(paragraph[i] == '?' || paragraph[i] == ',' || paragraph[i] == ';' || paragraph[i] == '.'){
                paragraph[i] = ' ';
            }
        }
        std::string word = "";
        std::stringstream sstr(paragraph);
        
        while (sstr >> word)
        {
            hashmap[word]++;
        }
        
        int max_element = 0;
        std::string mostCommon = "";

        for(const auto& item: banned){
            if(hashmap.find(item) != hashmap.end()){
                hashmap.erase(item);
            }
        }
        for(const auto& pair : hashmap){
            if(pair.second > max_element){
                    max_element = pair.second;
                    mostCommon = pair.first;
                }
        }
        
        return mostCommon;
}

int main(int argc, char const *argv[])
{
    std::string paragraph = "a, a, a, a, b,b,b,c, c";
    std::vector<std::string> banned = {"a"};

    std::cout << "The word is:" << mostCommonWord(paragraph,banned) << "\n";

    return 0;
}
