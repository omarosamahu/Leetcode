#include <iostream>
#include <sstream>

// std::string getEmail()
int main(int argc, char const *argv[])
{
    std::string names = "Omar Osama; Alaa Khaled; Leen Omar";
    std::stringstream stream(names);
    std::string name;
    while (std::getline(stream,name,','))
    {
        /* code */
    }
    
    return 0;
}
