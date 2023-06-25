#ifndef BLOK_LOGGER_H
#define BLOK_LOGGER_H

#include <stdio.h>
#include <stdlib.h>

enum log_level {
    log_info,
    log_warn,
    log_err,
};

void printlog(enum log_level _level, const char *_where, const char *_message);

#endif