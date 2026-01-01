std::vector<std::uint8_t> vec; 

constexpr std::size_t n_elem = 8; 

for (std::uint8_t i = 0; i < n_elem; i++) { 

    vec.push_back(i); 

} 

const auto print_array = [](uint8_t* arr, std::size_t n) { 

    for (std::size_t i = 0; i < n; i++) { 

        printf("%d ", arr[i]); 

    } 

    printf("\r\n"); 

    }; 

print_array(vec.data(), n_elem);