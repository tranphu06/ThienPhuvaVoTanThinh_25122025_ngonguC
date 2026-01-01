using namespace std; 

using namespace std::pmr; 

 

array<uint8_t, sizeof(uint8_t) * 8> buffer{0}; 

monotonic_buffer_resource mbr{buffer.data(), buffer.size()}; 

polymorphic_allocator<uint8_t> pa{&mbr}; 

std::pmr::vector<uint8_t> vec{pa};