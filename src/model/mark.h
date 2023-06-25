#ifndef BLOK_MARK_H
#define BLOK_MARK_H

enum mark_status {
    mark_invisible = 0,
    mark_visible = 1,
};

struct mark {
    int x;
    int y;
    enum mark_status illumated;
};

struct mark mark_new(int x, int y);

#endif