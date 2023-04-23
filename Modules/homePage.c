#include <stdio.h>
#include "createRecord.c"
#include "searchRecord.c"
#include "modifyRecord.c"
#include "deleteRecord.c"
#include "displayRecord.c"
#include "login.c"
#include "signup.c"

void homePage()
{
    int loginMode;
    do
    {
        puts("1. LOGIN");
        puts("2. SIGN UP\n");
        printf(">>> ");
        scanf("%d", &loginMode);
        if (loginMode == 1)
        {
            int loginStatus = login();
            if (loginStatus)
                break;
        }
        else if (loginMode == 2)
        {
            signup();
        }

    } while (1);

    char location[30] = "./Files/";
    int choice = 1;
    while (choice)
    {
        printf("\n-------------------------------------------------------");
        printf("\nSelect any one option: ");
        printf("\n1. CREATE RECORD");
        printf("\n2. SEARCH RECORD");
        printf("\n3. MODIFY RECORD");
        printf("\n4. DISPLAY ALL RECORD");
        printf("\n5. DELETE RECORD");
        printf("\n>>> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createRecord(location);
            strcpy(location, "./Files/");
            break;
        case 2:
            searchRecord(location);
            strcpy(location, "./Files/");
            break;
        case 3:
            modifyRecord(location);
            strcpy(location, "./Files/");
            break;
        case 4:
            displayRecord(location);
            strcpy(location, "./Files/");
            break;
        case 5:
            deleteRecord(location);
            strcpy(location, "./Files/");
            break;

        default:
            printf("\n********   ** WRONG CHOICE **    ********\n");
            break;
        }
        printf("\n\nCONTINUE ?? 1/0: ");
        scanf("%d", &choice);
    }
}