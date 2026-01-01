#include <stdio.h> 

#define KICH_THUOC_BO_DEM 5 

 

typedef struct { 

    int mang[KICH_THUOC_BO_DEM]; // Mảng lưu trữ trực tiếp các giá trị nguyên 

    size_t chi_so_ghi;           // Chỉ số phần tử tiếp theo để ghi (đẩy vào) 

    size_t chi_so_doc;           // Chỉ số phần tử tiếp theo để đọc (lấy ra) 

    size_t so_luong;             // Số lượng phần tử hiện có trong bộ đệm 

} bo_dem_vong_so_nguyen; 

 

// Khởi tạo bộ đệm vòng 

void khoi_tao_bo_dem_vong(bo_dem_vong_so_nguyen* rb) { 

    rb->chi_so_ghi = 0; 

    rb->chi_so_doc = 0; 

    rb->so_luong = 0; 

} 

 

// Đẩy giá trị vào bộ đệm 

void day_vao_bo_dem(bo_dem_vong_so_nguyen* rb, int gia_tri) { 

    rb->mang[rb->chi_so_ghi] = gia_tri; 

    rb->chi_so_ghi = (rb->chi_so_ghi + 1) % KICH_THUOC_BO_DEM; 

     

    if (rb->so_luong < KICH_THUOC_BO_DEM) { 

        rb->so_luong++; 

    } else { 

        // Bộ đệm đầy, dịch chỉ số đọc 

        rb->chi_so_doc = (rb->chi_so_doc + 1) % KICH_THUOC_BO_DEM; 

    } 

} 

 

// Lấy giá trị từ bộ đệm 

int lay_tu_bo_dem(bo_dem_vong_so_nguyen* rb) { 

    if (rb->so_luong == 0) { 

        return 0; // Trả về 0 nếu bộ đệm rỗng 

    } 

    int gia_tri = rb->mang[rb->chi_so_doc]; 

    rb->chi_so_doc = (rb->chi_so_doc + 1) % KICH_THUOC_BO_DEM; 

    rb->so_luong--; 

    return gia_tri; 

} 

 

int main() { 

    bo_dem_vong_so_nguyen rb; 

    khoi_tao_bo_dem_vong(&rb); 

     

    // Đẩy các giá trị từ 0 đến 9 vào bộ đệm 

    for (int i = 0; i < 10; i++) { 

        day_vao_bo_dem(&rb, i); 

    } 

     

    // Lấy và in tất cả giá trị từ bộ đệm 

    while (rb.so_luong > 0) { 

        int gia_tri = lay_tu_bo_dem(&rb); 

        printf("%d\n", gia_tri); 

    } 

     

    return 0; 

}