#include <array> 

#include <cstdio> 

 

template <class Kieu, std::size_t KichThuoc>  

struct bo_dem_vong { 

    std::array<Kieu, KichThuoc> mang; 

    std::size_t chi_muc_ghi = 0; // Chỉ mục phần tử tiếp theo sẽ ghi (đẩy vào) 

    std::size_t chi_muc_doc = 0; // Chỉ mục phần tử tiếp theo sẽ đọc (lấy ra) 

    std::size_t dem = 0; // Số lượng phần tử trong bộ đệm 

     

    void day_vao(Kieu gt) { 

        mang.at(chi_muc_ghi) = gt; 

        chi_muc_ghi = (chi_muc_ghi + 1) % KichThuoc; 

        if (dem < KichThuoc) { 

            dem++; 

        } 

        else { 

            // Bộ đệm đầy, di chuyển chi_muc_doc về phía trước 

            chi_muc_doc = (chi_muc_doc + 1) % KichThuoc; 

        } 

    } 

     

    Kieu lay_ra() { 

        if (dem == 0) { 

            // Bộ đệm rỗng, trả về giá trị mặc định của Kieu 

            return Kieu{}; 

        } 

        Kieu gia_tri = mang.at(chi_muc_doc); 

        chi_muc_doc = (chi_muc_doc + 1) % KichThuoc; 

        --dem; 

        return gia_tri; 

    } 

     

    bool la_rong() const { return dem == 0; } 

}; 

 

int main() { 

    bo_dem_vong<int, 5> bdv; 

     

    for (int i = 0; i < 10; ++i) { 

        bdv.day_vao(i); 

    } 

     

    while (!bdv.la_rong()) { 

        printf("%d\n", bdv.lay_ra()); 

    } 

     

    return 0; 

}