#include "otherFunctions.h"

void displayHelp(void) {
    puts("/*** POMOC ***/");
    puts("Uzyj w dowolnej kolejnosci wg wzoru [flaga nazwa_pliku.txt]:");
    puts("-i nazwa_pliku_ze_slowami.txt");
    puts("-o nazwa_pliku_wyjsciowego.txt");
    puts("-f nazwa_pliku_z_prefiksami.txt");
    exit(0);
}

int checkFileExt(char *pattern, char *toCheck) {
    if(pattern != NULL && toCheck != NULL) {
        int i,
            patternLength = strlen(pattern),
            toCheckLength = strlen(toCheck);

            for(i = patternLength - 1; i >= 0; i--) {
                if(tolower(*(pattern + i)) != tolower(*(toCheck + --toCheckLength))) {
                    return 0;
                }
            }
            return 1;
    } else {
        return 0;
    }
}

int checkPrefix(char *prefix, char *word) {
    if(prefix != NULL && word != NULL) {
        int i,
            prefixLength = strlen(prefix);

        for(i = 0; i < prefixLength; i++) {
            if(tolower(*(prefix + i)) != tolower(*(word + i))) {
                return 0;
            }
        }
        return 1;
    } else {
        return 0;
    }
}

void deleteList(prefixNode **head) {
    prefixNode *tmpPrefixNode;
    while((*head) != NULL) {
        tmpPrefixNode = *head;
        *head = (*head)->next;
        if(tmpPrefixNode->prefix) {
            free(tmpPrefixNode->prefix);
        }

        while(tmpPrefixNode->wordListHead != NULL) {
            wordNode *tmpWordNode;
            tmpWordNode = tmpPrefixNode->wordListHead;
            tmpPrefixNode->wordListHead = tmpPrefixNode->wordListHead->next;
            if(tmpWordNode->word) {
                free(tmpWordNode->word);
            }
        }
        free(tmpPrefixNode);
    }
}
