#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void chooseDirection(int light_x, int light_y,
    int& current_tx, int& current_ty) {
    if (current_tx == light_x && current_ty == light_y) return;
    else if (current_tx > light_x && current_ty > light_y) {
        current_tx--;
        current_ty--;
        std::cout << "NW" << std::endl;
    }
    else if (current_tx < light_x && current_ty > light_y) {
        current_tx++;
        current_ty--;
        std::cout << "NE" << std::endl;
    }
    else if (current_tx > light_x && current_ty < light_y) {
        current_tx--;
        current_ty++;
        std::cout << "SW" << std::endl;
    }
    else if (current_tx < light_x && current_ty < light_y) { 
        current_tx++;
        current_ty++;
        std::cout << "SE" << std::endl; 
    }
    else if (current_tx == light_x && current_ty > light_y) { 
        current_ty--;
        std::cout << "N" << std::endl; 
    }
    else if (current_tx == light_x && current_ty < light_y) {
        current_ty++;
        std::cout << "S" << std::endl;
    }
    else if (current_tx > light_x && current_ty == light_y) {
        current_tx--;
        std::cout << "W" << std::endl;
    }
    else if (current_tx < light_x && current_ty == light_y) {
        current_tx++;
        std::cout << "E" << std::endl;
    }
}

int main()
{
    int light_x; 
    int light_y; 
    int initial_tx; 
    int initial_ty; 
    std::cin >> light_x >> light_y >> initial_tx >> initial_ty; std::cin.ignore();

    int current_tx = initial_tx;
    int current_ty = initial_ty;

    while (1) {
        int remaining_turns; // The remaining amount of turns Thor can move. Do not remove this line.
        std::cin >> remaining_turns; std::cin.ignore();

        chooseDirection(light_x, light_y, current_tx, current_ty);


        // A single line providing the move to be made: N NE E SE S SW W or NW
    }
}
