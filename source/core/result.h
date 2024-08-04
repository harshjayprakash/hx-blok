#ifndef NEON_RESULT_H
#define NEON_RESULT_H

typedef enum _NeonResult
{
    NeonSuccess = 0,
    NeonFail = -1,
    NeonProgramNotInitialised = -2,
    NeonFailedToGetArguments = -3,
} NeonResult;

#endif