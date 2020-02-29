#include <iostream>
#include <string>
#include <algorithm>

bool ispalindrome(std::string & str);

int main(){
    std::string somestring;
    std::cout << "Enter a string (quit to stop): ";
    while(std::getline(std::cin,somestring) && somestring != "quit"){
        if(ispalindrome(somestring))
             std::cout << somestring << " is a palindrome\n";
        else
             std::cout << somestring << " is not a palindrome\n";
        std::cout << "Enter next string (quit to stop): ";
    }
    return 0;
}

bool ispalindrome(std::string & str){
    std::string reverse_str = str;
    std::reverse(reverse_str.begin(), reverse_str.end());
    if(str == reverse_str)
        return true;
    else
        return false; 
}
