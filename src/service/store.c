#include "store.h"

struct square *global_square_get(void) {
    static struct square sq;
    return &sq;
}

RECT global_square_get_winapi_rect(void) {
    struct square *sq = global_square_get();
    RECT rect = { sq->x, sq->y, sq->x + sq->width, sq->y + sq->height };
    return rect;
}
