#ifndef BLOK_DEBUG_H
#define BLOK_DEBUG_H

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>

#define BLOK_DEBUG_MECHANISMS_ENABLED 1

void blokDebugConsoleOpen();

void blokDebugConsoleClose();

void blokDebugConsoleLog(const char *message);

#if BLOK_DEBUG_MECHANISMS_ENABLED

#define BLOK_DEBUG_CONSOLE_OPEN() blokDebugConsoleOpen()

#define BLOK_DEBUG_CONSOLE_CLOSE() blokDebugConsoleClose()

#define BLOK_LOG(MESSAGE) blokDebugConsoleLog(MESSAGE)

#else

#define BLOK_DEBUG_CONSOLE_OPEN() 

#define BLOK_DEBUG_CONSOLE_CLOSE() 

#define BLOK_LOG(MESSAGE)

#endif

#endif