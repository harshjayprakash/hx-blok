/**
 * @file log.c
 * @date 2024-08-09
 * @brief
 */

#include "log.h"
#include <stdio.h>

static NeonLogTechnique mLogTechnique = NeonConsole;

void NeonInitLogger(const NeonLogTechnique technique)
{
    mLogTechnique = technique;
}

void NeonLog(const NeonLogLevel level, const NeonResult information)
{
    wchar_t *levelsAsString[] = {
        L"Unknown",
        L"Information", 
        L"Warning", 
        L"Error",
    };

    int levelAsIndex = (int) level;


    (void) fwprintf(
        stdout, L"Project Neon | %s | %s", 
        levelsAsString[levelAsIndex], information.message 
    );
}

NeonResult NeonLogAndReturn(const NeonLogLevel level, const NeonResult information)
{
    NeonLog(level, information);
    return information;
}

void NeonFreeLogger(void)
{

}