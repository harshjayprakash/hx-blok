#include "logger.h"

static const char *get_timedate(void) {
    return "{timedate not implemented}";
}

static const char *log_level_value(enum log_level _level) {
    switch (_level) {
    case log_info:
        return (const char*)"INFO";
    case log_warn:
        return (const char*)"WARN";
    case log_err:
        return (const char*)"ERR ";
    default:
        return (const char*)"????";
    }
}

void printlog(enum log_level _level, const char *_where, const char *_message) {
    (void)fprintf(stdout, " %s %s | %s | %s", get_timedate(),
                  log_level_value(_level), _where, _message);
}