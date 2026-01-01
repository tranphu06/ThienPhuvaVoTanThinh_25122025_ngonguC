class sensor { 

public: 

    sensor(uart &u, std::uint32_t read_interval): uart_(u), read_interval_(read_interval) {} 

private: 

    uart &uart_; 

    const std::uint32_t read_interval_; 

}; 

 

int main() { 

    uart uart1; 

    sensor sensor1(uart1, 500); 

    return 0; 

}