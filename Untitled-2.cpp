#include <stdio.h> 

#include <string.h> 

#define KICH_THUOC_BO_DEM 20 // Tổng số byte có sẵn trong bộ đệm 

 

typedef struct { 

    unsigned char du_lieu[KICH_THUOC_BO_DEM]; // Mảng lưu trữ các giá trị byte 

    size_t chi_muc_ghi; // Chỉ mục của byte tiếp theo sẽ ghi 

    size_t chi_muc_doc; // Chỉ mục của byte tiếp theo sẽ đọc 

    size_t dem; // Số byte hiện đang được sử dụng trong bộ đệm 

    size_t kich_thuoc_phan_tu; // Kích thước của mỗi phần tử tính bằng byte 

} bo_dem_vong; 

 

void khoi_tao_bo_dem_vong(bo_dem_vong* bdv, size_t kich_thuoc_phan_tu) { 

    bdv->chi_muc_ghi = 0; 

    bdv->chi_muc_doc = 0; 

    bdv->dem = 0; 

    bdv->kich_thuoc_phan_tu = kich_thuoc_phan_tu; 

} 

 

void day_vao_bo_dem_vong(bo_dem_vong* bdv, void* gia_tri) { 

    if (bdv->dem + bdv->kich_thuoc_phan_tu <= KICH_THUOC_BO_DEM) { 

        bdv->dem += bdv->kich_thuoc_phan_tu; 

    } else { 

        bdv->chi_muc_doc = (bdv->chi_muc_doc + bdv->kich_thuoc_phan_tu) % KICH_THUOC_BO_DEM; 

    } 

    memcpy(&bdv->du_lieu[bdv->chi_muc_ghi], gia_tri, bdv->kich_thuoc_phan_tu); 

    bdv->chi_muc_ghi = (bdv->chi_muc_ghi + bdv->kich_thuoc_phan_tu) % KICH_THUOC_BO_DEM; 

} 

 

int lay_tu_bo_dem_vong(bo_dem_vong* bdv, void* gia_tri) { 

    if (bdv->dem < bdv->kich_thuoc_phan_tu) { 

        // Không đủ dữ liệu để lấy 

        return 0; 

    } 

    memcpy(gia_tri, &bdv->du_lieu[bdv->chi_muc_doc], bdv->kich_thuoc_phan_tu); 

    bdv->chi_muc_doc = (bdv->chi_muc_doc + bdv->kich_thuoc_phan_tu) % KICH_THUOC_BO_DEM; 

    bdv->dem -= bdv->kich_thuoc_phan_tu; 

    return 1; // Thành công 

} 

 

int main() { 

    bo_dem_vong bdv; 

    khoi_tao_bo_dem_vong(&bdv, sizeof(int)); // Khởi tạo bộ đệm cho giá trị int 

     

    for (int i = 0; i < 10; i++) { 

        int gt = i; 

        day_vao_bo_dem_vong(&bdv, &gt); 

    } 

     

    int gia_tri_lay_ra; 

    while (lay_tu_bo_dem_vong(&bdv, &gia_tri_lay_ra)) { 

        printf("%d\n", gia_tri_lay_ra); 

    } 

     

    return 0; 

}