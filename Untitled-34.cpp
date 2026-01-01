class uart { 

    std::uint32_t baudrate_; 

    std::uint8_t calculate_uartdiv(); 

 void write_brr(std::uint8_t); 

 public: 

 uart(std::uint32_t baud = 9600); 

 void init(); 

 };