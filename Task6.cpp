https://www.codingame.com/ide/puzzle/mime-type

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Extension {
    std::string _MIMEtype;
    std::string _extension;

    Extension(std::string ext, std::string mt) :
        _MIMEtype(mt), _extension(ext) {
    };
};

int indElemInOrder(std::string str) {
    char firstLetter = str[0];
    int indLetter = int(firstLetter) - int('a');
    if (firstLetter < 'a')
        indLetter += (int('a') - int('A'));
    return indLetter;
}

std::string tolower(std::string input) {
    std::string str = input;
    for (auto &letter : str) {
        if (int(letter) <= int('Z') && 
            int(letter) >= int('A'))
            letter = char(int(letter) + (int('a') - int('A')));
    }
    return str;
}

std::string findExtension(std::string fname) {
    if (fname[fname.size() - 1] == '.') return "UNKNOWN";
    for (int i = fname.size() - 1; i >= 0; --i) {
        if (fname[i] == '.') return fname.substr(i + 1);
    }
    return "UNKNOWN";
}

void printMimeType(std::vector<std::vector<Extension>> extensions,
    std::string fileName) {
    auto fileExtension = tolower(findExtension(fileName));
    if (fileExtension == "unknown")
        std::cout << "UNKNOWN" << std::endl;
    else {
        bool matchExt = false;
        int indExt = indElemInOrder(fileExtension);
        for (auto extension : extensions[indExt]) {
            auto ex = tolower(extension._extension);
            if (fileExtension == ex) {
                std::cout << extension._MIMEtype << std::endl;
                matchExt = !matchExt;
                break;
            }
        }
        if (!matchExt) std::cout << "UNKNOWN" << std::endl;
    }
}

int main()
{

    int n;
    std::cin >> n; std::cin.ignore();
    int q;
    std::cin >> q; std::cin.ignore();

    int indType = 0;
    int alphabet = int('Z') - int('A') + 1;
    
    std::vector<std::vector<Extension>> extensions(alphabet);
    std::vector<int> indTypes(alphabet, 0);

    for (int i = 0; i < n; i++) {
        std::string ext;
        std::string mt;
        std::cin >> ext >> mt; std::cin.ignore();

        int indExt = indElemInOrder(ext);
        Extension extension = Extension(ext, mt);
        extensions[indExt].push_back(extension);

    }
    for (int i = 0; i < q; i++) {
        std::string fname;
        std::getline(std::cin, fname);
        printMimeType(extensions, fname);
    }

}
