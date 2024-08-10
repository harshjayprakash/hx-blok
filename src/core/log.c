/**
 * @file log.c
 * @date 2024-08-09
 * @brief
 */

#include "log.h"
#include <stdio.h>
#include <time.h>

static NeonLogTechnique mLogTechnique = NeonConsole;
static FILE *logFile = NULL;
static time_t mTime;
static struct tm mTm;

void NeonInitLogger(const NeonLogTechnique technique)
{
    mLogTechnique = technique;


    if (mLogTechnique == NeonFile)
    {
        logFile = fopen("log.txt", "w");
    }
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

    mTime = time(NULL);
    mTm = *localtime(&mTime);

    if (mLogTechnique == NeonFile)
    {
        if (!logFile) { return; }

        (void) fwprintf(
            logFile, L"Neon | %d/%d/%d %d:%d:%d | %ls | %ls\n", 
            mTm.tm_year+1900, mTm.tm_mon, mTm.tm_mday, mTm.tm_hour, mTm.tm_min, mTm.tm_sec,
            levelsAsString[levelAsIndex], information.message 
        );

        return;
    }

    (void) fwprintf(
        stderr, L"Neon | %d/%d/%d %d:%d:%d | %ls | %ls\n", 
        mTm.tm_year+1900, mTm.tm_mon, mTm.tm_mday, mTm.tm_hour, mTm.tm_min, mTm.tm_sec,
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
    if (logFile)
    {
        fclose(logFile);
    }
}