#include <cstdint> 

 

class uart { 

public: 

    static void init(std::uint32_t baudrate) { 

        write_brr(calculate_uartdiv(baudrate)); 

    } 

     

private: 

    static std::uint8_t calculate_uartdiv(std::uint32_t baudrate) { 

        return baudrate / 32000; 

    } 

    static void write_brr(std::uint8_t) {} 

}; 

 

int main() { 

    uart::init(115200); 

    return 0; 

}