#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Rodriguez-Exam3.h"

/*
Name: Gabriel Rodriguez
Assignment: Exam 3
Purpose: Uses a menu to manage champions using struct and dynamic memory
*/

int main() {
    int userChoice;
    int size = 0;
    int capacity = 10;
    Champion* list = malloc(capacity * sizeof(Champion)); // allocate memory for 10 champions to start

    do {
        printf("\n=== Champion Tracker Menu ===\n");
        printf("Add Champion (1)\n");
        printf("Remove Champion (2)\n");
        printf("Display All Champions (3)\n");
        printf("Sort by Winrate (4)\n");
        printf("Search by Name (5)\n");
        printf("Calculate Average Winrate (6)\n");
        printf("Exit (0)\n");
        printf("Choose an option: ");

        // SAFELY read user input
        if (scanf("%d", &userChoice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear invalid input
            continue; // restart the loop
        }

        if (userChoice == 1) {
            addChampion(list, &size, capacity);
        }
        else if (userChoice == 2) {
            removeChampion(list, &size);
        }
        else if (userChoice == 3) {
            displayChampions(list, size);
        }
        else if (userChoice == 4) {
            sortChampionsByWinrate(list, size);
        }
        else if (userChoice == 5) {
            searchChampionByName(list, size);
        }
        else if (userChoice == 6) {
            calculateAverageWinrate(list, size);
        }
        else if (userChoice != 0) {
            printf("Invalid option. Try again.\n");
        }

    } while (userChoice != 0);

    free(list); // Always free malloc’d memory!
    return 0;
}

// === ADD CHAMPION ===
void addChampion(Champion* list, int* size, int capacity) {
    if (*size >= capacity) {
        printf("List is full. Can't add more champions.\n");
        return;
    }

    printf("Enter champion name: ");
    scanf("%s", list[*size].name);

    printf("Enter role (Top, Mid, Jungle, ADC, Support): ");
    scanf("%s", list[*size].role);

    printf("Enter difficulty (1 - 10): ");
    scanf("%d", &list[*size].difficulty);

    printf("Enter winrate (e.g., 51.3): ");
    scanf("%f", &list[*size].winrate);

    (*size)++;
    printf("Champion added successfully!\n");
}

// === DISPLAY CHAMPIONS ===
void displayChampions(Champion* list, int size) {
    if (size == 0) {
        printf("No champions to display yet.\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        printf("\nChampion %d:\n", i + 1);
        printf("  Name: %s\n", list[i].name);
        printf("  Role: %s\n", list[i].role);
        printf("  Difficulty: %d\n", list[i].difficulty);
        printf("  Winrate: %.2f%%\n", list[i].winrate);
        printf("------------------------\n");
    }
}

// === REMOVE CHAMPION ===
void removeChampion(Champion* list, int* size) {
    if (*size == 0) {
        printf("There are no champions to remove.\n");
        return;
    }

    char nameToRemove[30];
    printf("Enter the name of the champion to remove: ");
    scanf("%s", nameToRemove);

    int found = 0;
    for (int i = 0; i < *size; i++) {
        if (strcmp(list[i].name, nameToRemove) == 0) {
            // Shift everything left
            for (int j = i; j < *size - 1; j++) {
                list[j] = list[j + 1];
            }
            (*size)--;
            printf("Champion removed successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Champion not found.\n");
    }
}

// === SORT BY WINRATE ===
void sortChampionsByWinrate(Champion* list, int size) {
    if (size < 2) {
        printf("Not enough champions to sort.\n");
        return;
    }

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (list[j].winrate < list[j + 1].winrate) {
                Champion temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }

    printf("Champions sorted by winrate (high to low).\n");
}

// === SEARCH BY NAME ===
void searchChampionByName(Champion* list, int size) {
    if (size == 0) {
        printf("No champions in the list to search.\n");
        return;
    }

    char searchName[30];
    printf("Enter the name of the champion to search: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(list[i].name, searchName) == 0) {
            printf("\nChampion found!\n");
            printf("  Name: %s\n", list[i].name);
            printf("  Role: %s\n", list[i].role);
            printf("  Difficulty: %d\n", list[i].difficulty);
            printf("  Winrate: %.2f%%\n", list[i].winrate);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Champion not found.\n");
    }
}

// === CALCULATE AVERAGE WINRATE ===
void calculateAverageWinrate(Champion* list, int size) {
    if (size == 0) {
        printf("No champions in the list to calculate average.\n");
        return;
    }

    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += list[i].winrate;
    }

    float average = sum / size;
    printf("Average Winrate of all champions: %.2f%%\n", average);
}
