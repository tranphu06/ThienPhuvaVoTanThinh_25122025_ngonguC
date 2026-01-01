#include <stdio.h>
#include <string.h>
#define KHAI_BAO_BO_DEM_VONG(KIEU, KICH_THUOC) \ 

typedef struct { \ 

    KIEU du_lieu[KICH_THUOC]; \ 

    size_t chi_muc_ghi; \ 

    size_t chi_muc_doc; \ 

    size_t dem; \ 

} bo_dem_vong_##KIEU##_##KICH_THUOC; \ 

\ 

void khoi_tao_bo_dem_vong_##KIEU##_##KICH_THUOC(bo_dem_vong_##KIEU##_##KICH_THUOC *bdv) { \ 

    bdv->chi_muc_ghi = 0; \ 

    bdv->chi_muc_doc = 0; \ 

    bdv->dem = 0; \ 

} \ 

\ 

void day_vao_bo_dem_vong_##KIEU##_##KICH_THUOC(bo_dem_vong_##KIEU##_##KICH_THUOC *bdv, KIEU gia_tri) { \ 

    bdv->du_lieu[bdv->chi_muc_ghi] = gia_tri; \ 

    bdv->chi_muc_ghi = (bdv->chi_muc_ghi + 1) % KICH_THUOC; \ 

    if (bdv->dem < KICH_THUOC) { \ 

        bdv->dem++; \ 

    } else { \ 

        bdv->chi_muc_doc = (bdv->chi_muc_doc + 1) % KICH_THUOC; \ 

    } \ 

} \ 

\ 

int lay_tu_bo_dem_vong_##KIEU##_##KICH_THUOC(bo_dem_vong_##KIEU##_##KICH_THUOC *bdv, KIEU *gia_tri) { \ 

    if (bdv->dem == 0) { \ 

        return 0; /* Bộ đệm rỗng */ \ 

    } \ 

    *gia_tri = bdv->du_lieu[bdv->chi_muc_doc]; \ 

    bdv->chi_muc_doc = (bdv->chi_muc_doc + 1) % KICH_THUOC; \ 

    bdv->dem--; \ 

    return 1; /* Thành công */ \ 

}