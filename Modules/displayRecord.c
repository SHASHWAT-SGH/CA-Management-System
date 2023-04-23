#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include "storageType.c"

void displayRecord(char fileLocation[])
{
    struct record userData;
    char fileExt[5] = ".txt";
    FILE *f;
    DIR *d;
    struct dirent *dir;

    d = opendir(fileLocation);
    char fileLocationLocal[20];
    int i = 0;
    while ((dir = readdir(d)) != NULL)
    {
        strcpy(fileLocationLocal, fileLocation);
        if (i < 2)
        {
            i++;
            continue;
        }

        strcat(fileLocationLocal, dir->d_name);

        f = fopen(fileLocationLocal, "rb");
        fread(&userData, sizeof(struct record), 1, f);
        printf("\n\n-----------------------------------------------------\n");
        printf("\nRegistration Number: %d ", userData.registrationNo);
        printf("\nRoll Number: %d", userData.rollNo);
        printf("\nName: %s", userData.name);
        printf("\nPhysics Marks: %.1f", userData.marks.physics);
        printf("\nChemistry Marks: %.1f", userData.marks.chemistry);
        printf("\nDBMS Marks: %.1f", userData.marks.dbms);
        printf("\nProgramming in C Marks: %.1f", userData.marks.c);

        fclose(f);
    }
    closedir(d);
}