#include <iostream>

int main(){
    std::string cars[] = { "Corvette", "Ford", "Toyota" };

    // std::cout << cars << std::endl; // Gives out the array memeory address

    for(int i=0; i < size(cars); i++)
    {
        std::cout << cars[i] << std::endl;
    }

    return 0;
}