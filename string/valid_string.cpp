#include <iostream>
#include <stack>
#include <string>

bool valid(std::string s){
    std::stack<char> stack;
        for(int i=0;i<s.length();++i){
            if(stack.empty()){
                stack.push(s[i]);
            }
            if((s[i]  == ')' && stack.top() == '(') ||
                (s[i] == ']' && stack.top() == '[') ||
                (s[i] == '}' && stack.top() == '{') 
              )
            {
                stack.pop();
            }
            else{
                stack.push(s[i]);
            }
        }
        std::cout << "Number of items in the stack is :" << stack.size() << "\n";
        return stack.empty() ? true : false;
}

int main(int argc, char const *argv[])
{
    std::cout << valid("([{}])") << "\n";
    return 0;
}
