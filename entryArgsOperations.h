#ifndef ENTRY_ARGS_OPERATIONS_H
#define ENTRY_ARGS_OPERATIONS_H

#include <ctype.h>
#include "otherFunctions.h"

entryArgs *constructEntryArgs(void);
void modifyEntryArgs(entryArgs **args, char *flag, char *fileName);
entryArgs *readEntryArgs(int argc, char *argv[]);
void freeEntryArgs(entryArgs **args);

#endif // ENTRY_ARGS_OPERATIONS_H
