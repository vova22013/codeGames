// https://www.codingame.com/ide/puzzle/ascii-art

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int chooseLetter(char letter) {
    int asciiNum = int(letter);
    if (asciiNum <= int('Z') && asciiNum >= int('A') ||
        asciiNum <= int('z') && asciiNum >= int('a')) {

        if (asciiNum >= int('a')) return asciiNum - int('a');
        else return asciiNum - int('A');
    }
    else return -1;
}

void writeRes(std::vector<std::vector<std::string>> letters, std::string t, int h) {
    for (int i = 0; i < h; ++i) {
        std::string row = "";
        for (int j = 0; j < t.length(); ++j) {
            int numLetter = chooseLetter(t[j]);
            if (numLetter == -1) numLetter = letters.size() - 1;
            row += letters[numLetter][i];
        }
        std::cout << row << std::endl;
    }
    return;
}

int main()
{
    int l;
    std::cin >> l; std::cin.ignore();
    int h;
    std::cin >> h; std::cin.ignore();
    std::string t;
    std::getline(std::cin, t);

    auto n = t.length();
    if (0 > l || l > 30) {
        std::cout << "Invalid input";
        return -1;
    }
    if (0 > h || h > 30) {
        std::cout << "Invalid input";
        return -1;
    }
    if (0 > n || n > 200) {
        std::cout << "Invalid input";
        return -1;
    }

    int countLetters;
    std::vector<std::vector<std::string>> letters;
    
    for (int i = 0; i < h; i++) {
        std::string row;
        std::getline(std::cin, row);
        if (i == 0) {
            countLetters = row.length() / l;
            letters.resize(countLetters);
        }
        for (int j = 0; j < countLetters; ++j) {
            letters[j].push_back(row.substr(l * j, l));
        }
    }
    
    writeRes(letters, t, h);

}
