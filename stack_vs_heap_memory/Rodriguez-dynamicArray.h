#ifndef RODRIGUEZ_DYNAMIC_ARRAY_H
#define RODRIGUEZ_DYNAMIC_ARRAY_H

#define MAX 10

typedef struct {
    int id;
    char name[50];
    float value;
} Data;

void fillStackArray(Data arr[], int size);
void printArray(Data arr[], int size, const char* title);
void copyToHeap(Data* heapArr, Data* stackArr, int size);
void saveToBinaryFile(Data* arr, int size, const char* filename);

#endif
