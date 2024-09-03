#include <iostream>
#include <string>
#include <array>
#include <iomanip>
#include <sstream>

int main(){
    

    char red_y_n{};
    char green_y_n{};
    char blue_y_n{};
    std::string red_place{};
    std::string green_place{};
    std::string blue_place{};
    char b{};
    bool flag{0};
    bool f1{1};
    bool fr{1};
    bool flag1{0};
    std::string r_string{};
    std::string g_string{};



    do{
        std::cout << "--------------------------\n"; 
        std::cout << "Exercise 2\n";
        std::cout << "--------------------------\n";
        
        std::array<std::array<std::string,3>,3> slots{{
            {"1", "2", "3"},
            {"4", "5", "6"},
            {"7", "8", "9"}
        }};

        for (int i{0}; i < 3; ++i){
            for (int j{0}; j < 3; ++j){
                std::cout << slots[i][j] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "--------------------------\n";

        

        // Red pegs

        do {
            std::cout << "Do you want to place red pegs (y, n)? ";
            std::cin >> red_y_n;
        }while (red_y_n != 'y' && red_y_n != 'n');

        if (red_y_n == 'y'){
            std::string position;
            do{
                std::cout << "Where to place red pegs (1-9)? ";
                std::getline(std::cin >> std::ws, red_place);
                std::stringstream ss(red_place);

                std::array<std::array<std::string, 3>, 3> r_array{};
                

                for (int i{0}; i < 3; ++i){
                    for (int j{0}; j < 3; ++j){
                        r_array[i][j] = slots[i][j];
                    }
                }

                while (ss >> position){
                    if (position != "1" && position != "2" && position != "3" && position != "4" && position != "5" && position != "6" && position != "7" && position != "8" && position != "9"){
                        break;
                    }

                    for (int i{0}; i < 3; ++i){
                        for (int j{0}; j < 3; ++j){
                            if (slots[i][j] == position) {
                                slots[i][j] = 'r';

                            }
                        }
                    }
                }
                


            }while (position != "1" && position != "2" && position != "3" && position != "4" && position != "5" && position != "6" && position != "7" && position != "8" && position != "9");
        }

        std::cout << "----------------------------\n";



        for (int i{0}; i < 3; ++i){
            for (int j{0}; j < 3; ++j){
                std::cout << slots[i][j] << " ";
            }
            std::cout << "\n";
        }    

        std::cout << "\n";
        for (int i{0}; i < 3; ++i){
            for (int j{0}; j < 3; ++j){
                if (slots[i][j] != "r"){
                    flag = 1;
                    r_string.append(slots[i][j]);
                    
                }
            }
            std::cout << "\n";
        }    
        
        if (flag > 0){
            // Green pegs
            do {
                std::cout << "Do you want to place green pegs (y, n)? ";
                std::cin >> green_y_n;
            }while (green_y_n != 'y' && green_y_n != 'n');
 
            if (green_y_n == 'y'){
             
                do{
                    std::cout << "Where to place green pegs ( ";
                    for (int i{0}; i < 3; ++i){
                        for (int j{0}; j < 3; ++j){
                            if (slots[i][j] != "r"){
                                std::cout << slots[i][j] << " ";
                            }
                        }
                    }
 
                    std::cout << ") ? " ;
                    std::getline(std::cin >> std::ws, green_place);
                    std::stringstream ss(green_place);
 
                    std::string position{};
                    

                    std::array<std::array<std::string, 3>, 3> g_array{};
                    
                    for (int i{0}; i < 3; ++i){
                        for (int j{0}; j < 3; ++j){
                            g_array[i][j] = slots[i][j];
                        }
                    }

                    while (ss >> position){
                        int k = r_string.length() - 1;
                        f1 = 1;
                        do{
                            std::string word{r_string[k]};
                            if (position == word){
                                f1 = 0;
                                break;
                            }
                            

                            --k;
                        }while(k >= 0);

                        if (f1 == 1){
                            break;
                        }

                        // std::cout << positions << "\n";
                        for (int i{0}; i < 3; ++i){
                            for (int j{0}; j < 3; ++j){
                                if (g_array[i][j] == position) {
                                    g_array[i][j] = 'g';

                                }
                            
                            }
                        }
                    } 
                    if (f1 == 0){
                        for (int i{0}; i < 3; ++i){
                            for (int j{0}; j < 3; ++j){
                                slots[i][j] = g_array[i][j];
                            }
                        }
                    }
                    
                }while(f1);

                

            }
            std::cout << "----------------------------\n";
            for (int i{0}; i < 3; ++i){
                for (int j{0}; j < 3; ++j){
                    std::cout << slots[i][j] << " ";
                }
                std::cout << "\n";
            }    
 
            std::cout << "\n";

            std::cout << "\n";
            for (int i{0}; i < 3; ++i){
                for (int j{0}; j < 3; ++j){
                    if (slots[i][j] != "r" && slots[i][j] != "g"){
                        flag1 = 1;
                        g_string.append(slots[i][j]);
                    
                    }
                }
                std::cout << "\n";
            }
 
            // Blue Pegs
            if (flag1 > 0){
                do {
                    std::cout << "Do you want to place blue pegs (y, n)? ";
                    std::cin >> blue_y_n;
                }while (blue_y_n != 'y' && blue_y_n != 'n');
    
                if (blue_y_n == 'y'){
                    
                    do{
                        std::cout << "Where to place blue pegs ( ";
                        for (int i{0}; i < 3; ++i){
                            for (int j{0}; j < 3; ++j){
                                if (slots[i][j] != "r" && slots[i][j] != "g"){
                                    std::cout << slots[i][j] << " ";
                                }
                            }
                        }
    
                        std::cout << ") ? " ;
                        std::getline(std::cin >> std::ws, blue_place);
                        std::stringstream ss(blue_place);
    
                        std::string position{};
                        

                        std::array<std::array<std::string, 3>, 3> b_array{};
                        
                        for (int i{0}; i < 3; ++i){
                            for (int j{0}; j < 3; ++j){
                                b_array[i][j] = slots[i][j];
                            }
                        }

                        while (ss >> position){
                            int k = g_string.length() - 1;
                            f1 = 1;
                            do{
                                std::string word{g_string[k]};
                                if (position == word){
                                    f1 = 0;
                                    break;
                                }
                                

                                --k;
                            }while(k >= 0);

                            if (f1 == 1){
                                break;
                            }

                            // std::cout << positions << "\n";
                            for (int i{0}; i < 3; ++i){
                                for (int j{0}; j < 3; ++j){
                                    if (b_array[i][j] == position) {
                                        b_array[i][j] = 'b';

                                    }
                                
                                }
                            }
                        } 
                        if (f1 == 0){
                            for (int i{0}; i < 3; ++i){
                                for (int j{0}; j < 3; ++j){
                                    slots[i][j] = b_array[i][j];
                                }
                            }
                        }
                        
                    }while(f1);


                    std::cout << "----------------------------\n";
                    for (int i{0}; i < 3; ++i){
                        for (int j{0}; j < 3; ++j){
                            std::cout << slots[i][j] << " ";
                        }
                        std::cout << "\n";
                    }    

                }
            }   
            else 
                std::cout << "Try again (y, n) "; 
        }
        else 
            std::cout << "Try again (y, n) "; 
        
        std::cout << "Try again (y, n) ";
       
        std::cin >> b;
    }while(b == 'y');
}