#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

string getListOfNumber() {
    string numberArray;
    getline(cin, numberArray); // Read the entire line from 
    if (!numberArray.empty() && numberArray.back() != '#') {
        return "Invaiid input";
    }
    else {
        int  position = numberArray.find("#");
        return numberArray.substr(0, (position));
    }
}

void welcomeWord() {
    cout << "Welcome to old phone..." << endl << "Type list of number: ";
}

string OldPhonePad(string input) {
    const unordered_map<string, string> phonePad = {
        {"1", "&"}, {"11", "'"}, {"111", "("},
        {"2", "A"}, {"22", "B"}, {"222", "C"},
        {"3", "D"}, {"33", "E"}, {"333", "F"},
        {"4", "G"}, {"44", "H"}, {"444", "I"},
        {"5", "J"}, {"55", "K"}, {"555", "L"},
        {"6", "M"}, {"66", "N"}, {"666", "O"},
        {"7", "P"}, {"77", "Q"}, {"777", "R"}, {"7777", "S"},
        {"8", "T"}, {"88", "U"}, {"888", "V"},
        {"9", "W"}, {"99", "X"}, {"999", "Y"}, {"9999", "Z"}
    };

    auto letter = phonePad.find(input);
    return (letter != phonePad.end()) ? letter->second : "";
}

string DeleteLetter(string input) {

    int  position = input.find("*");
    return input.substr(0, (position - 1));
}

// breck number if there are empty space between input numbers
 vector<string> SeparateNumber(string input) { 
    vector<string> result;
    string tem;

    for (const auto& numbers : input) {

        if (numbers == ' ') {
            result.push_back(tem);
            tem.clear();
        }
        else {
            tem += numbers;
        }
    }
    if (!tem.empty()) {
        result.push_back(tem);
    }

    return result;
}



 string DisplayLetter(string input) {
     string letterResults;

     for (const auto& item : SeparateNumber(input)) {
         letterResults += OldPhonePad(DeleteLetter(item));
     }
     return letterResults;
 }

int main()
{
    string listNumber;
    
    welcomeWord();
    listNumber = getListOfNumber();
    if (listNumber == "Invaiid input") {
        cout << listNumber;
    }
    else {
        cout << DisplayLetter(listNumber);
    }
 
    cout << endl;
    return 0;
}