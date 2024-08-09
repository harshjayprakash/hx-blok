/**
 * @file result.c
 * @date 2024-08-09
 * @brief
 */

#include "result.h"
#include <wchar.h>

NeonResult NeonNewResult(NeonResultCode code, wchar_t *pMessage)
{
    NeonResult result = { 0 };
    result.code = code;

    wprintf(L"%s", pMessage);

    if (pMessage) {
        (void) wcsncpy(result.message, pMessage, 260);
    }

    return result;
}