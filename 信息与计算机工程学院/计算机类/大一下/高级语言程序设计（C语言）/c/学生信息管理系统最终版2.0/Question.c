#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

//��ȡ�û���ѡ��

int Question()

{
    char answer;

    printf("��ѡ��Y/y or N/n����\n");
    scanf("%c", &answer);
    while( (answer != 'Y' && answer != 'N') || (answer != 'y' && answer != 'n') )
    {
        printf("�������!������ѡ��y or n����\n");
        scanf("%c", &answer);
    }
    if( answer == 'Y' || answer == 'y' )
    {
        return 1;
    }
    else if( answer == 'N' || answer == 'n')
    {
        return 0;
    }
}
