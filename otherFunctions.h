#ifndef OTHER_FUNCTIONS_H
#define OTHER_FUNCTIONS_H

#include "myStructures.h"

void displayHelp(void);
int checkFileExt(char *pattern, char *toCheck);
int checkPrefix(char *prefix, char *word);
void deleteList(prefixNode **head);

#endif // OTHER_FUNCTIONS_H
