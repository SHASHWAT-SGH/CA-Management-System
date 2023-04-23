#include <stdio.h>
#include <string.h>
#include "storageType.c"

void searchRecord(char fileLocation[])
{
    struct record readUserData;
    char str_registrationNo[10];
    char fileExt[5] = ".txt";
    int registrationNo;

    printf("\nEnter Registration number to search record: ");
    scanf("%d", &registrationNo);

    sprintf(str_registrationNo, "%d", registrationNo);

    FILE *f;
    strcat(fileLocation, str_registrationNo);
    strcat(fileLocation, fileExt);
    f = fopen(fileLocation, "rb");
    if (f == NULL)
    {
        printf("\n***Registraion Number NOT found***\n");
    }
    else
    {
        fread(&readUserData, sizeof(struct record), 1, f);
        printf("\n\n*-*-*-*-*-*-*-*-*-*- Record Of %d -*-*-*-*-*-*-*-*-*-*-*-*-", readUserData.registrationNo);
        printf("\nRegistration Number: %d ", readUserData.registrationNo);
        printf("\nRoll Number: %d", readUserData.rollNo);
        printf("\nName: %s", readUserData.name);
        printf("\nPhysics Marks: %.1f", readUserData.marks.physics);
        printf("\nChemistry Marks: %.1f", readUserData.marks.chemistry);
        printf("\nDBMS Marks: %.1f", readUserData.marks.dbms);
        printf("\nProgramming in C Marks: %.1f", readUserData.marks.c);
    }
    fclose(f);
}
