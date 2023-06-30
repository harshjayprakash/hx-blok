#include "mark.h"

struct mark mark_new(int x, int y) {
    struct mark mark_ = {x, y, mark_visible};
    return mark_;
}
