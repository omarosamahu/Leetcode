#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
#include <cmath>

std::unordered_map<int,char> hashmap = {
        {1,'I'},
        {5,'V'},
        {10,'X'},
        {50,'L'},
        {100,'C'},
        {500,'D'},
        {1000,'M'},
    };

std::string getNum(int n){
    std::string out;
    if(n >= 1000){
        while(n != 0){
            out += 'M';
            n = n - 1000;
        }
        return out;
    }
    if(n < 1000 && n >= 500){
        if(n != 900){
            out += 'D';
        }
        else{
            out += 'C';
            out += 'M';
        }
        n = n - 500;
    }
    
    if(n < 500 && n >= 100){
        while (n != 0)
        {
            if(n == 400){
                out += "X";
                out += "C";
            }
            else{
                out += 'C';
            }
            n = n - 100;
        }
        
    }

    if(n < 100 && n>=50){
        if(n != 90){
            out += "XC";
        }
        else{
            out += 'L';
        }
        n = n - 50;
    }

    if(n < 50 && n >= 10){
        while(n != 0){
            if(n == 40){
                out += "XL";
            }
            else{
                out += 'X';
            }
            n = n - 10;
        }
    }

    if(n < 10 && n >= 5){
        if(n == 9){
            out += "IX";
        }
        else{
            out += 'V';
        }
        out =  n - 5;
    }

    if(n < 5 && n >= 1){
        while(n != 0){
            if(n == 4){
                out += "IV";
            }
            else{
                out += 'I';
            }
            n = n - 1;
        }
    }
    return out;
}

std::string intToRoman(int num){
    std::string roman("");

    int sum = 0;
    std::vector<int> data;
    int p = 0;

    while (num > 0){
        auto rem = num % 10 * std::pow(10,p);
        data.insert(data.begin(),rem);
        num = num / 10;
        ++p;
    }

    for (size_t i = 0; i < data.size(); i++)
    {
        std::cout << getNum(data[i]) << "\n";
        roman += getNum(data[i]);
    }
    std::cout << roman << "\n";
    
    
    return roman;
}

int main(int argc, char const *argv[])
{
    intToRoman(1994);
    return 0;
}
