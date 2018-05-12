#ifndef MY_STRUCTURES_H
#define MY_STRUCTURES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _entryArgs entryArgs;
typedef struct _wordNode wordNode;
typedef struct _prefixNode prefixNode;

struct _entryArgs {
    char *inputFile;
    char *outputFile;
    char *prefixesFile;
};

struct _wordNode {
    char *word;
    struct _wordNode *next;
};

struct _prefixNode {
    char *prefix;
    struct _prefixNode *next;
    struct _wordNode *wordListHead;
};

#endif // MY_STRUCTURES_H
