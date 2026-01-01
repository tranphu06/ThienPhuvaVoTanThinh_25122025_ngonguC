class MyClass 

{ 

private: 

int num; 

public: 

MyClass(int t_num):num(t_num){} 

~MyClass(){} 

int getNum() const { 

return num; 

} 

}; 

int main () { 

MyClass obj(1); 

return obj.getNum(); 

}