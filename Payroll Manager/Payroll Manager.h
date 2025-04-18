#ifndef LASTNAME_ASSIGNMENTNAME_H
#define LASTNAME_ASSIGNMENTNAME_H

// DATE struct (reuse from your previous assignment)
typedef struct {
    int day;
    int month;
    int year;
} DATE;

// PAYRECORD struct (provided by instructor)
typedef struct {
    char name[100];
    int age;
    float hrlyWage;
    float hrsWorked;
    float regPay;
    float otPay;
    float totalPay;
    DATE payDate;
} PAYRECORD;

#endif
