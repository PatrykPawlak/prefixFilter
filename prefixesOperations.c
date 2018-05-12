#include "prefixesOperations.h"

prefixNode *constructPrefixNode(void) {
    prefixNode *newPrefixNode;
    newPrefixNode = malloc(sizeof(prefixNode));
    newPrefixNode->prefix = malloc(sizeof(char));
    newPrefixNode->next = NULL;
    newPrefixNode->wordListHead = NULL;

    return newPrefixNode;
}

void addPrefixWithSort(prefixNode **head, prefixNode **newNode) {
    prefixNode *tmp;
    if((*head) == NULL) {
        *head = *newNode;
    } else if(strcmp((*head)->prefix, (*newNode)->prefix) > 0) {
        (*newNode)->next = *head;
        *head = *newNode;
    } else {
        tmp = (*head);
        while((tmp->next != NULL) && (strcmp(tmp->next->prefix, (*newNode)->prefix) < 0)) {
            tmp = tmp->next;
        }
        (*newNode)->next = tmp->next;
        tmp->next = (*newNode);
    }
}
