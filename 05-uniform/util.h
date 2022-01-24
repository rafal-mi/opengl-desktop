/*
    Copyright 2014 Etay Meiri
*/

#ifndef OGLDEV_UTIL_H
#define OGLDEV_UTIL_H

#ifndef _WIN32
#include <unistd.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <string.h>
#include <assert.h>

#ifdef _WIN32
typedef unsigned int uint;
#endif

using namespace std;

bool readFile(const char* fileName, string& outFile);

void devError(const char* pFileName, uint line, const char* msg, ... );
void devFileError(const char* pFileName, uint line, const char* pFileError);

#define ERROR(msg, ...) devError(__FILE__, __LINE__, msg, __VA_ARGS__)
#define FILE_ERROR(error) devFileError(__FILE__, __LINE__, error);

#ifdef _WIN64
#define SNPRINTF _snprintf_s
#define VSNPRINTF vsnprintf_s
#define RANDOM rand
#define SRANDOM srand((unsigned)time(NULL))
#else
#define SNPRINTF snprintf
#define VSNPRINTF vsnprintf
#define RANDOM random
#define SRANDOM srandom(getpid())
#endif

#endif  /* OGLDEV_UTIL_H */
