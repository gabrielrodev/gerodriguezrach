/*
Name: Gabriel Rodriguez
Date: 2025-04-04
Purpose: Demonstrate stack vs heap arrays using structs, and saving to binary file
*/

#define _CRT_SECURE_NO_WARNINGS

#include "Rodriguez-dynamicArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    Data stackArray[MAX];
    Data* heapArray = NULL;

    // Step 1: Fill the stack array
    fillStackArray(stackArray, MAX);

    // Step 2: Allocate memory on the heap
    heapArray = (Data*)malloc(MAX * sizeof(Data));
    if (heapArray == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Step 3: Copy data from stack to heap
    copyToHeap(heapArray, stackArray, MAX);

    // Step 4: Print both arrays
    printArray(stackArray, MAX, "Stack Array");
    printArray(heapArray, MAX, "Heap Array");

    // Step 5: Save heap array to a binary file
    saveToBinaryFile(heapArray, MAX, "heapData.bin");

    // Step 6: Clean up
    free(heapArray);
    return 0;
}

// Fill stack array with user input
void fillStackArray(Data arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter ID for item %d: ", i + 1);
        scanf("%d", &arr[i].id);
        while (getchar() != '\n'); // flush newline

        printf("Enter name for item %d: ", i + 1);
        fgets(arr[i].name, sizeof(arr[i].name), stdin);
        arr[i].name[strcspn(arr[i].name, "\n")] = '\0';  // Remove newline

        printf("Enter value for item %d: ", i + 1);
        scanf("%f", &arr[i].value);
        while (getchar() != '\n'); // flush newline
    }
}

// Print contents of an array
void printArray(Data arr[], int size, const char* title) {
    printf("\n--- %s ---\n", title);
    for (int i = 0; i < size; i++) {
        printf("ID: %d | Name: %s | Value: %.2f\n", arr[i].id, arr[i].name, arr[i].value);
    }
}

// Copy values from stack to heap
void copyToHeap(Data* heapArr, Data* stackArr, int size) {
    for (int i = 0; i < size; i++) {
        heapArr[i] = stackArr[i];
    }
}

// Save heap array to binary file
void saveToBinaryFile(Data* arr, int size, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fwrite(arr, sizeof(Data), size, file);
    fclose(file);
    printf("\nHeap array saved to %s\n", filename);
}
