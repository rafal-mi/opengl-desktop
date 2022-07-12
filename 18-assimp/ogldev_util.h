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

bool ReadFile(const char* fileName, string& outFile);

void devError(const char* pFileName, uint line, const char* msg, ... );
void devFileError(const char* pFileName, uint line, const char* pFileError);

//#define ERROR(msg, ...) devError(__FILE__, __LINE__, msg, __VA_ARGS__)
#define OGLDEV_FILE_ERROR(error) devFileError(__FILE__, __LINE__, error);

#define ARRAY_SIZE_IN_ELEMENTS(a) (sizeof(a)/sizeof(a[0]))

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

#define SAFE_DELETE(p) if (p) { delete p; p = NULL; }

#define GLCheckError() (glGetError() == GL_NO_ERROR)

#define NOT_IMPLEMENTED \
    printf("Not implemented case in %s:%d\n", __FILE__, __LINE__); \
    exit(0);

#define ASSIMP_LOAD_FLAGS (aiProcess_Triangulate | aiProcess_GenSmoothNormals |  aiProcess_JoinIdenticalVertices )

#endif  /* OGLDEV_UTIL_H */
