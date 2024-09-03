#include <iostream>
#include <string>
#include <array>

int main(){
    std::cout << "--------------------------" << "\n";
    std::cout << "EXERCISE 1" << "\n";
    std::cout << "--------------------------" << "\n";

    std::array<std::array<std::string, 3>, 3> combinations{{
        {"cube", "ball", "peg"},
        {"suction gripper", "finger gripper"},
        {"red table", "green table", "blue table"}
    }};

    std::array<std::string, 3> output{};

    std::array<char, 3> part{'c', 'b', 'p'};
    std::array<char, 2> gripper{'s', 'f'};
    std::array<char, 3> table{'r', 'g', 'b'};

    char x{};
    char y{};
    char z{};
    char b{};
    do{
        do {
            std::cout << "Which part to pick up (c, b, p)? ";
            std::cin >> x;    
        }while (x != part[0] && x != part[1] && x != part[2]);
        for(int i{0}; i < std::size(part); ++i){
            if(part[i] == x){
                output[0] = combinations[0][i];
            }
        }
        do {
            std::cout << "Which gripper to use (s, f)? ";
            std::cin >> y;
        }while (y != gripper[0] && y != gripper[1]);
        for (int i{0}; i < std::size(gripper); ++i){
            if(gripper[i] == y){
                output[1] = combinations[1][i];
            }
        }
        if (output[0] == "ball"){
            if (y == gripper[0]){
                do {
                    std::cout << "Which table to use (r, g, b)? ";
                    std::cin >> z;
                }while(z != table[0] && z != table[1] && z != table[2]);
                for (int i{0}; i < std::size(table); ++i){
                    if (table[i] == z){
                        output[2] = combinations[2][i];
                    }
                }
                if (z == table[1]){
                    std::cout << "Success: The " << output[0] << " was placed on the " << output[2] << ".\n";
                }
                else
                    std::cout << "Failure: Cannot place the " << output[0] << " on the " << output[2] << ".\n";

            }
            else    
                std::cout << "Faliure: Cannot pick up the ball with the finger gripper.\n";
        }
        else
            if (output[0] == "cube"){
                if (y != gripper[0]){
                    do {
                        std::cout << "Which table to use (r, g, b)? ";
                        std::cin >> z;
                        for (int i{0}; i < std::size(table); ++i){
                            if (table[i] == z){
                                output[2] = combinations[2][i];
                            }
                        }
                    }while(z != table[0] && z != table[1] && z != table[2]);
                    
                    if (z == table[0]){
                        std::cout << "Success: The " << output[0] << " was placed on the " << output[2] << ".\n";
                    }
                    else
                        std::cout << "Failure: Cannot place the " << output[0] << " on the " << output[2] << ".\n";

                }
                else
                    std::cout << "Faliure: Cannot pick up the cube with the suction gripper.\n" ;
            }
            else    
                if (y != gripper[0]){
                    do {
                        std::cout << "Which table to use (r, g, b)? ";
                        std::cin >> z;
                    }while (z != table[0] && z != table[1] && z != table[2]);
                    for (int i{0}; i < std::size(table); ++i){
                        if (table[i] == z){
                            output[2] = combinations[2][i];
                        }
                    }
                    if (z == table[2]){
                        std::cout << "Success: The " << output[0] << " was placed on the " << output[2] << ".\n";
                    }
                    else
                        std::cout << "Failure: Cannot place the " << output[0] << " on the " << output[2] << ".\n";

                }
                else
                    std::cout << "Faliure: Cannot pick up the peg with the suction gripper.\n";

        std::cout << "Try again (y, n)? ";

        std::cin >> b;
    }while (b == 'y');
}

    

    

        