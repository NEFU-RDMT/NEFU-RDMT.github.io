#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

//获取用户的选择

int Question()

{
    char answer;

    printf("请选择（Y/y or N/n）：\n");
    scanf("%c", &answer);
    while( (answer != 'Y' && answer != 'N') || (answer != 'y' && answer != 'n') )
    {
        printf("输入错误!请重新选择（y or n）；\n");
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
