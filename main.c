#include "entryArgsOperations.h"
#include "otherFunctions.h"
#include "prefixesOperations.h"
#include "myStructures.h"
#include "filesOperations.h"

int main(int argc, char *argv[]) {
    entryArgs *args = readEntryArgs(argc, argv);
    prefixNode *head = NULL;
    readPrefixFile(&head, args->prefixesFile);
    readInputFile(&head, args->inputFile);
    saveToOutputFile(&head, args->outputFile);
    deleteList(&head);
    freeEntryArgs(&args);
    return 0;
}
