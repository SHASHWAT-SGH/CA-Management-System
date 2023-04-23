#include <stdio.h>
#include <string.h>
#include "storageType.c"

void createRecord(char fileLocation[])
{
    struct record userData;
    char str_registrationNo[10];
    char fileExt[5] = ".txt";

    printf("\nEnter Registration Number: ");
    scanf("%d", &userData.registrationNo);
    sprintf(str_registrationNo, "%d", userData.registrationNo);
    FILE *f;
    strcat(fileLocation, str_registrationNo);
    strcat(fileLocation, fileExt);
    f = fopen(fileLocation, "rb");
    if (f == NULL)
    {
        fclose(f);
        f = fopen(fileLocation, "wb");
        printf("\nEnter Roll Number: ");
        scanf("%d", &userData.rollNo);
        char name[20];
        printf("\nEnter Name: ");
        fflush(stdin);
        gets(name);
        strcpy(userData.name, name);
        while (1)
        {
            printf("\nEnter Physics Marks: ");
            scanf("%f", &userData.marks.physics);
            if (userData.marks.physics >= 0 && userData.marks.physics <= 100)
            {
                break;
            }
            printf("\n*** Marks Should be between 0 and 100 ***");
        }
        while (1)
        {
            printf("\nEnter Chemistry Marks: ");
            scanf("%f", &userData.marks.chemistry);
            if (userData.marks.chemistry >= 0 && userData.marks.chemistry <= 100)
            {
                break;
            }
            printf("\n*** Marks Should be between 0 and 100 ***");
        }

        while (1)
        {
            printf("\nEnter DBMS Marks: ");
            scanf("%f", &userData.marks.dbms);
            if (userData.marks.dbms >= 0 && userData.marks.dbms <= 100)
            {
                break;
            }
            printf("\n*** Marks Should be between 0 and 100 ***");
        }
        while (1)
        {
            printf("\nEnter Programming in C Marks: ");
            scanf("%f", &userData.marks.c);
            if (userData.marks.c >= 0 && userData.marks.c <= 100)
            {
                break;
            }
            printf("\n*** Marks Should be between 0 and 100 ***");
        }

        fwrite(&userData, sizeof(struct record), 1, f);
        printf("\n ********* STUDENT DATA ADDED SUCCESS *********\n");
    }
    else
    {
        printf("\n ********* STUDENT ALREADY EXISTS *********\n");
    }
    fclose(f);
}
