#include <stdio.h>
#ifndef MY_STRUCT_H
#define MY_STRUCT_H

struct markss
{
    float physics;
    float chemistry;
    float c;
    float dbms;
};

struct record
{
    int registrationNo;
    int rollNo;
    char name[20];
    struct markss marks;
};

#endif