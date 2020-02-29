#include <iostream>
#include <cctype>
#include <string>

int main(){
    using namespace std;
    string words;
    int vowel=0, consonant=0, other=0;

    cout << "Enter words (q to quit): \n";
    while((cin >> words) && words != "q"){
       if(isalpha(words[0]))
           if( words[0] == 'a' || words[0] == 'e' || words[0] == 'i' || words[0] == 'o' || words[0] == 'u'\
|| words[0] == 'A' || words[0] == 'E' || words[0] == 'I' || words[0] == 'O' || words[0] == 'U' )
               vowel++;
           else consonant++;
       else other++;
    }
    cout << vowel << " words beginning with vowels\n";
    cout << consonant << " words begining with consonants\n";
    cout << other << " others\n";
    return 0;
} 
