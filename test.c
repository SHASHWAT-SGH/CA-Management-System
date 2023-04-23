#include <stdio.h>
#include <string.h>

void main()
{
    char str_registrationNo[10];
    int num = 123;
    sprintf(str_registrationNo, "%d", num);
    printf("%s", str_registrationNo);
}