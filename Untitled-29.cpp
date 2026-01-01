#include <cstdio> 

#include <cstdlib> 

#include <exception> 

#include <array> 

 

int main() { 

    constexpr auto my_terminate_handler = []() { 

        printf("This is my_terminate_handler\r\n"); 

        std::abort(); 

    }; 

    std::set_terminate(my_terminate_handler); 

    std::array<int, 4> arr; 

    for (int i = 0; i < 5; i++) { 

        arr.at(i) = i; 

    } 

    return 0; 

}