#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char * inputFile;
    char * outputFile;
    char * prefixesFile;
} entryArguments;

void help(void) {
    printf("Uzyj:\n");
    printf(" -i <plik_wejsciowy.txt>\n");
    printf(" -o <plik_wyjsciowy.txt>\n");
    printf(" -f <plik_z_przedrostkami.txt>\n");
}

int readEntryArguments(int argc, char* argv[], entryArguments *args) {
    const char *INPUT_FILE_PREFIX = "-i";
    const char *OUTPUT_FILE_PREFIX = "-o";
    const char *PREFIXES_FILE_PREFIX = "-f";

    for(int i = 1; i < argc; i++) {
        if(strcmp(argv[i], INPUT_FILE_PREFIX) == 0) {
            args->inputFile = malloc(sizeof(args->inputFile) * strlen(argv[++i]));
            strcpy(args->inputFile, argv[i]);
            printf("\ninputFileTemp: %s\n", args->inputFile);
        } else if(strcmp(argv[i], OUTPUT_FILE_PREFIX) == 0) {
            args->outputFile = malloc(sizeof(args->outputFile) * strlen(argv[++i]));
            strcpy(args->outputFile, argv[i]);
            printf("\noutputFileTemp: %s\n", args->outputFile);
        } else if(strcmp(argv[i], PREFIXES_FILE_PREFIX) == 0) {
            args->prefixesFile = malloc(sizeof(args->prefixesFile) * strlen(argv[++i]));
            strcpy(args->prefixesFile, argv[i]);
            printf("\nprefixesFileTemp: %s\n", args->prefixesFile);
        }
    }

    if(strcmp(args->inputFile, "") == 0 || strcmp(args->outputFile, "") == 0 || strcmp(args->prefixesFile, "") == 0) {
        return 0;
    }
    return 1;
}

int main(int argc, char *argv[]) {

    entryArguments args;
    int boolReadEntryArguments = readEntryArguments(argc, argv, &args);
    return 0;
}
