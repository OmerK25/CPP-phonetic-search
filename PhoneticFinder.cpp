#include "PhoneticFinder.hpp"
#include <iostream>


namespace phonetic{

string find(string text, string word){
    string str = "";
for (size_t i = 0; i < text.length(); i++)
{

if(text[i] != ' '){

if (text[i] == word[i])
str+=text[i];



}
}
return str;
}
}