#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    while (1) {
        int maxHeight = 0, numMount;
        for (int i = 0; i < 8; i++) {
            int mountain_h; 
            std::cin >> mountain_h; std::cin.ignore();
            if (maxHeight < mountain_h) {
                maxHeight = mountain_h;
                numMount = i;
            }
        }
        std::cout << numMount << std::endl;
    }
}
