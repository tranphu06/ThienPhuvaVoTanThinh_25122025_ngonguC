#include <cstdio> 

struct Base { 

virtual void print () { 

printf("Base\r\n"); 

} 

}; 

struct Derived : public Base { 

void print () override { 

printf("Derived\r\n"); 

} 

}; 

void printer (Base &base) { 

base.print(); 

} 

int main() { 

Base base; 

Derived derived; 

printer(base); 

printer(derived); 

return 0; 

}