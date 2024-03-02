#pragma once

struct listNode {
    int data;
    listNode* next;
};

extern listNode* mainListHeader;
extern listNode* secondaryListHeader;
extern int countMain, countSecond;



bool isListEmpty(listNode*& current);

void addNode(listNode*& current, int newData, int index);

void deleteNode(listNode*& listHeader, int index);

int findIndexByValue(listNode* listHeader, int value);

int printDataFromIndex(listNode* listHeader, int index);

void removeNodeByIndex(listNode*& current, int index);

void removeNodeByData(listNode*& current, int searchData);

void printList(listNode*& current);

void clearList(listNode*& current);
void addFewItems(listNode*& listHeader, int count);
