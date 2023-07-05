#include "store.h"

struct store *store_instance_get(void)
{
    static struct store store_;
    return &store_;
}
