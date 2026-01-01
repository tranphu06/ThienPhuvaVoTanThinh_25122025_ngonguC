int main() { 

#ifdef USE_TEMPLATES 

ring_buffer<int, 10> buffer1; 

ring_buffer<float, 10> buffer2; 

#else 

ring_buffer_int buffer1; 

ring_buffer_float buffer2; 

#endif 

for (int i = 0; i < 20; i++) { 

buffer1.push(i); 

buffer2.push(i + 0.2f); 

} 

for (int i = 0; i < 10; i++) { 

printf("%d, %.2f\r\n", buffer1.pop(), buffer2.pop()); 

} 

return 0; 

}