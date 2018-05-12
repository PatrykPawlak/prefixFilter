#ifndef FILES_OPERATIONS_H
#define FILES_OPERATIONS_H

#include "prefixesOperations.h"

void readPrefixFile(prefixNode **head, char *fileName);
void readInputFile(prefixNode **head, char *fileName);
void saveToOutputFile(prefixNode **head, char *fileName);

#endif // FILES_OPERATIONS_H
