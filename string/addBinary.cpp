#include <iostream>

std::string addBinary(std::string s1, std::string s2){
    auto n1 = s1.size();
    auto n2 = s2.size();

    int p1 = 0;
    int p2 = 0;

    while (p1 < n1 || p2 < n2)
    {
        if(p1 >= n2){
            s2.push_back('0');
            ++p1;
        }
        else if(p2 >= n1){
            s1.push_back('0');
            ++p2;
        }
        else{
            ++p1;
            ++p2;
        } 
    }
    
    std::string sum;
    int rem = 1;
    for(int i=0;i<n1;++i){
        char x = s1[i] ^ s2[i] ^ rem;
        sum.push_back(x);
        rem = s1[i] & s2[i];
    }

    std::cout << "String s1: " << s1 << "\n";
    std::cout << "String s2: " << s2 << "\n";

    return sum;
       
}
int main(int argc, char const *argv[])
{
    std::cout << "Sum is: " << addBinary("11","1") << "\n"; 
    return 0;
}
