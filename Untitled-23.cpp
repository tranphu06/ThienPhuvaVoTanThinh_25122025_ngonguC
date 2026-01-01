Base 

Derived
void printer (Base &base) { 

base.print(); 

if(Derived *derived = dynamic_cast<Derived*>(&base); derived!=nullptr) 

{ 

printf("We found Base using RTTI!\r\n"); 

} 

}