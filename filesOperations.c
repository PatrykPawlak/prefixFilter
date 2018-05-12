#include "filesOperations.h"

void readPrefixFile(prefixNode **head, char *fileName) {
    FILE *prefixFile = fopen(fileName, "r");
    if(prefixFile == NULL) {
        perror(fileName);
        exit(0);
    }

    char buffer[256];
    while(!feof(prefixFile)) {
        fscanf(prefixFile, "%255s", buffer);
        prefixNode *node = constructPrefixNode();
        node->prefix = realloc(node->prefix, (strlen(buffer) + 1));
        strcpy(node->prefix, buffer);
        addPrefixWithSort(*&head, &node);
    }

    fclose(prefixFile);
}

void readInputFile(prefixNode **head, char *fileName) {
    FILE *inputFile = fopen(fileName, "r");
    if(inputFile == NULL) {
        perror(fileName);
        deleteList(*&head);
        exit(0);
    }
    char buffer[256], *tmpStr;
    while(!feof(inputFile)) {
        prefixNode *tmpPrefixHead;
        tmpPrefixHead = *head;
        fscanf(inputFile, "%255s", buffer);
        while(tmpPrefixHead != NULL) {
            if(checkPrefix(tmpPrefixHead->prefix, buffer) == 1) {
                wordNode *node = constructWordNode();
                node->word = realloc(node->word, (strlen(buffer) + 1));
                strcpy(node->word, buffer);
                addWordWithSort(&tmpPrefixHead->wordListHead, &node);
            }
            tmpPrefixHead = tmpPrefixHead->next;
        }
    }
    fclose(inputFile);
}

void saveToOutputFile(prefixNode **head, char *fileName) {
    FILE *outputFile = fopen(fileName, "w");
    if(outputFile == NULL) {
        printf("Nie udalo sie otworzyc pliku: %s", fileName);
        deleteList(*&head);
        exit(0);
    } else {
        prefixNode *tmp = *head;
        while(tmp != NULL) {
            fprintf(outputFile, "** Przedrostek: %s\n", tmp->prefix);
            if(tmp->wordListHead == NULL) {
                fprintf(outputFile, "Nie znaleziono slow dla przedrostka.");
            } else {
                while(tmp->wordListHead != NULL) {
                    fprintf(outputFile, "%s\n", tmp->wordListHead->word);
                    tmp->wordListHead = tmp->wordListHead->next;
                }
            }
            fprintf(outputFile, "\n\n");
            tmp = tmp->next;
        }
        fclose(outputFile);
        printf("Zakonczono zadanie pomyslnie!\n");
    }
}
