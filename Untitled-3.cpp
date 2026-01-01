#include <stdio.h> 

// Macro để định nghĩa hàm tính tổng hai số 

#define DINH_NGHIA_HAM_TONG(KIEU) \ 

KIEU tong_##KIEU(KIEU a, KIEU b) { \ 

return a + b; \ 

} 

// Định nghĩa hàm tổng cho int và float 

DINH_NGHIA_HAM_TONG(int) 

DINH_NGHIA_HAM_TONG(float) 

 

int main() { 

    int ket_qua_int = tong_int(5, 3); 

    printf("Tong so nguyen: %d\n", ket_qua_int); 

     

    float ket_qua_float = tong_float(3.5f, 2.5f); 

    printf("Tong so thuc: %.2f\n", ket_qua_float); 

     

    return 0; 

}