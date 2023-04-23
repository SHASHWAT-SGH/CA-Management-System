#include <stdio.h>
#include <string.h>

int login()
{
    char username[20];
    char password[10];
    char savedpassword[10];
    char filePath[50] = "./UserData/";

    printf("\nEnter Username : ");
    fflush(stdin);
    gets(username);
    printf("\nEnter password : ");
    fflush(stdin);
    gets(password);
    strcat(filePath, username);
    strcat(filePath, ".txt");
    FILE *fp = fopen(filePath, "r");
    if (fp == NULL)
    {
        puts("\n******** Wrong Username! ********\n");
        return 0;
    }
    else
    {
        fscanf(fp, "%s", savedpassword);
        if (strcmp(password, savedpassword) == 0)
        {
            puts("\n******** Login Success ********\n");
            return 1;
        }
        else
        {
            puts("\n******** Invalid Password ********\n");
            return 0;
        }
    }
}
