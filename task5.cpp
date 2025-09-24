https://www.codingame.com/ide/puzzle/unary

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int powerTwo(int p) {
    int res = 1;
    for (int i = 0; i < p; ++i) {
        res *= 2;
    }
    return res;
}

std::vector<int> toBinary(char character) {
    int n = int(character);
    std::vector<int> characterInBinary;
    for (int i = 6; i >= 0; --i) {
        int powTwo = (powerTwo(i));
        int bit = n / powTwo;
        n -= bit * powTwo;
        characterInBinary.push_back(bit);
    }
    return characterInBinary;
}

std::vector<std::string> outMessage(std::vector<std::vector<int>> messageInBinary) {
    std::vector<std::string> outMess;
    bool needSpace = true;
    for (int j = 0; j < messageInBinary.size(); ++j) {
        std::string str = "";
        for (int i = 0; i < messageInBinary[j].size(); ++i) {
            int indLast = messageInBinary[j].size() - 1;
            if (i > 0 && messageInBinary[j][i - 1] == messageInBinary[j][i] ||
                j > 0 && i == 0 && messageInBinary[j - 1][indLast] == messageInBinary[j][i])
                str += '0';
            else {
                std::string space = " ";
                if (needSpace && i == 0) {
                    space = "";
                    needSpace = !needSpace;
                }
                if (messageInBinary[j][i] == 1)
                    str += space + "0 0";
                else str += space + "00 0";
            }
        } 
        outMess.push_back(str);
    }
    return outMess;
}

int main()
{
    std::string message;
    std::getline(std::cin, message);

    std::vector<std::vector<int>> translatedMessageToBinary;
    for (int i = 0; i < message.length(); ++i) {
        std::vector<int> binaryView;
        binaryView = toBinary(message[i]);
        translatedMessageToBinary.push_back(binaryView);
    }

    std::string outMessageInBinary = "";
    auto buf = outMessage(translatedMessageToBinary);
    for (auto elem : buf) {
        outMessageInBinary += elem;
    }
    std::cout << outMessageInBinary << std::endl;
}
