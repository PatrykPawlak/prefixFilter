#include "wordsOperations.h"

wordNode *constructWordNode(void) {
    wordNode *newWordNode;
    newWordNode = malloc(sizeof(wordNode));
    newWordNode->word = malloc(sizeof(char));
    newWordNode->next = NULL;

    return newWordNode;
}

void addWordWithSort(wordNode **head, wordNode **newNode) {
    wordNode *tmp;
    if((*head) == NULL) {
        *head = *newNode;
    } else if(strcmp((*head)->word, (*newNode)->word) > 0) {
        (*newNode)->next = *head;
        *head = *newNode;
    } else {
        tmp = (*head);
        while((tmp->next != NULL) && (strcmp(tmp->next->word, (*newNode)->word) < 0)) {
            tmp = tmp->next;
        }
        (*newNode)->next = malloc(sizeof(*tmp));
        (*newNode)->next = tmp->next;
        tmp->next = (*newNode);
    }
}
