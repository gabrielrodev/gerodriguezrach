/*
Name:Gabriel Rodriguez
assignment:Exam3.h
date:4/4/2025
Header file for Champion Tracker - defines Champion struct and declares functions
*/

// Gabriel Rodriguez
// Exam3.h
// Holds struct and function prototypes for the champion tracker

#ifndef EXAM3_H
#define EXAM3_H

typedef struct {
    char name[30];
    char role[15];
    int difficulty;
    float winrate;
} Champion;

// Function Prototypes
void addChampion(Champion* list, int* size, int capacity);
void displayChampions(Champion* list, int size);
void removeChampion(Champion* list, int* size);
void sortChampionsByWinrate(Champion* list, int size);
void searchChampionByName(Champion* list, int size);
void calculateAverageWinrate(Champion* list, int size);

#endif
