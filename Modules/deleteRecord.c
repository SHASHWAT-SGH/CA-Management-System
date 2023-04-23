#include <stdio.h>

void deleteRecord(char fileLocation[])
{
    char fileExt[5] = ".txt";
    char registrationNo[10];

    printf("\nEnter Registration Number to DELETE data: ");
    scanf("%s", &registrationNo);

    strcat(fileLocation, registrationNo);
    strcat(fileLocation, fileExt);

    remove(fileLocation);
    printf("\n--- Deleted Record Successfully ---");
}