void* operator new(std::size_t count) { 

printf("%s, size = %ld\r\n", __PRETTY_FUNCTION__, count); 

return std::malloc(count); 

} 

void operator delete(void* ptr) noexcept { 

printf("%s\r\n", __PRETTY_FUNCTION__); 

std::free(ptr); 

}