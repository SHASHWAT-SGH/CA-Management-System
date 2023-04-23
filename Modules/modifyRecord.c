#include <stdio.h>
#include "storageType.c"

void modifyRecord(char fileLocation[])
{
    int registrationNo;
    struct record userData;
    char fileExt[5] = ".txt";
    char str_registrationNo[10];

    printf("\nEnter Registration number to update record: ");
    scanf("%d", &registrationNo);

    sprintf(str_registrationNo, "%d", registrationNo);

    FILE *f;
    strcat(fileLocation, str_registrationNo);
    strcat(fileLocation, fileExt);
    f = fopen(fileLocation, "rb");

    if (f == NULL)
    {
        printf("\n*** User Data NOT Found ***");
    }
    else
    {
        fread(&userData, sizeof(struct record), 1, f);
        printf("\n---- Current data ---- ");
        printf("\nRegistration Number: %d ", userData.registrationNo);
        printf("\nRoll Number: %d", userData.rollNo);
        printf("\nName: %s", userData.name);
        printf("\nPhysics Marks: %.1f", userData.marks.physics);
        printf("\nChemistry Marks: %.1f", userData.marks.chemistry);
        printf("\nDBMS Marks: %.1f", userData.marks.dbms);
        printf("\nProgramming in C Marks: %.1f", userData.marks.c);
        printf("\n\n---- Enter updated data ---- ");

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

        FILE *f;
        f = fopen(fileLocation, "wb");
        fwrite(&userData, sizeof(struct record), 1, f);
        fclose(f);
        printf("\n--- Update Success ---");
    }

    fclose(f);
}