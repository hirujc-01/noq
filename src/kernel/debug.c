#include "debug.h"
#include <stdio.h>
#include "util/ansi-color-codes.h"

static const char* const g_LogSeverityColors[] =
{
    [LVL_DEBUG]        = GRY,
    [LVL_INFO]         = WHT,
    [LVL_WARN]         = YEL,
    [LVL_ERROR]        = RED,
    [LVL_CRITICAL]     = CRIT,
};

static const char* const g_ColorReset = "\033[0m";

void logf(const char* module, DebugLevel level, const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    if (level < MIN_LOG_LEVEL)
        return;

    fputs(g_LogSeverityColors[level], VFS_FD_DEBUG);    // set color depending on level
    fprintf(VFS_FD_DEBUG, "[%s] ", module);             // write module
    vfprintf(VFS_FD_DEBUG, fmt, args);                  // write text
    fputs(g_ColorReset, VFS_FD_DEBUG);                  // reset format
    fputc('\n', VFS_FD_DEBUG);                          // newline

    va_end(args);  
}