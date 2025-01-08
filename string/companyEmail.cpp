#include <iostream>
#include <sstream>
#include <unordered_map>
/*
"John Doe; Peter Benjamin Parker; Mary Jane Watson-Parker; John Elvis Doe; John Evan Doe; Jane Doe; Peter
Brian Parker"
*/

std::string getName(std::string name){
    std::string email;

    for(int i=0;i<name.size();++i){
        if(name[i] != ' '){
            if(name[i] == '-'){
                continue;
            }
            else{
                email += std::tolower(name[i]);
            }
        }
        else{
            email += '.'; 
        }
    }

    auto p1 = email.find_first_of('.');
    auto p2 = email.find_last_of('.');

    if(p1 != p2){
        std::string firstname = email.substr(0,p1);
        std::string lastname = email.substr(p2 + 1,email.length());
        email = firstname + '.'  + lastname;
    }
    return email;
}

std::string solution(std::string& S,std::string& C){
    std::string emails;
    S += ';';
    std::string word = "";
    std::unordered_map<std::string,int> names{};
    
    for(int i=0;i<S.size();++i){
        if(S[i] == ' ' && S[i-1] == ';'){
            continue;
        }
        if(S[i] == ';'){
            auto email = getName(word);
            names[email]++;

            if(names[email] == 1){
                emails += word + " <" + email + '@' + C +".com>";
            }
            else{
                emails += word + " <" + email + std::to_string(names[email]-1) + '@' + C +".com>";
            }
            word.clear();
        }
        else{
            word += S[i];
        }
    }
    return  emails;
}

int main(int argc, char const *argv[])
{
    std::string input = "John Doe; John Doe; Peter Benjamin Parker; Mary Jane Watson-Parker; John Elvis Doe; John Evan Doe; Jane Doe; Peter Brian Parker";
    std::string company = "einfo";

    auto name = solution(input,company);

    std::cout << name << "\n";
    return 0;
}
