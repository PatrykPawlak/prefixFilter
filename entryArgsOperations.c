#include "entryArgsOperations.h"

#define INPUT_FILE_FLAG "-i"
#define OUTPUT_FILE_FLAG "-o"
#define PREFIXES_FILE_FLAG "-f"
#define EXT_PATTERN ".txt"

entryArgs *constructEntryArgs(void) {
    entryArgs *newEntryArgs;
    newEntryArgs = malloc(sizeof(entryArgs));
    newEntryArgs->inputFile = malloc(sizeof(char));
    newEntryArgs->outputFile = malloc(sizeof(char));
    newEntryArgs->prefixesFile = malloc(sizeof(char));

    return newEntryArgs;
}

void modifyEntryArgs(entryArgs **args, char *flag, char *fileName) {
    if(strcmp(flag, INPUT_FILE_FLAG) == 0) {
        (*args)->inputFile = realloc((*args)->inputFile, strlen(fileName) + 1);
        strcpy((*args)->inputFile, fileName);
    } else if(strcmp(flag, OUTPUT_FILE_FLAG) == 0) {
        (*args)->outputFile = realloc((*args)->outputFile, strlen(fileName) + 1);
        strcpy((*args)->outputFile, fileName);
    } else if(strcmp(flag, PREFIXES_FILE_FLAG) == 0) {
        (*args)->prefixesFile = realloc((*args)->prefixesFile, strlen(fileName) + 1);
        strcpy((*args)->prefixesFile, fileName);
    }
}

entryArgs *readEntryArgs(int argc, char *argv[]) {
    entryArgs *args = constructEntryArgs();
    int i;
    for(i = 1; i < argc; i++) {
        if(strcmp(argv[i], INPUT_FILE_FLAG) == 0) {
            if(argv[++i] != NULL && checkFileExt(EXT_PATTERN, argv[i])) {
                modifyEntryArgs(&args, INPUT_FILE_FLAG, argv[i]);
            } else {
                displayHelp();
            }
        } else if(strcmp(argv[i], OUTPUT_FILE_FLAG) == 0) {
            if(argv[++i] != NULL && checkFileExt(EXT_PATTERN, argv[i])) {
                modifyEntryArgs(&args, OUTPUT_FILE_FLAG, argv[i]);
            } else {
                displayHelp();
            }
        } else if(strcmp(argv[i], PREFIXES_FILE_FLAG) == 0) {
            if(argv[++i] != NULL && checkFileExt(EXT_PATTERN, argv[i])) {
                modifyEntryArgs(&args, PREFIXES_FILE_FLAG, argv[i]);
            } else {
                displayHelp();
            }
        } else {
            displayHelp();
        }
    }
    return args;
}

void freeEntryArgs(entryArgs **args) {
    free((*args)->inputFile);
    free((*args)->outputFile);
    free((*args)->prefixesFile);
    free((*args));
}
