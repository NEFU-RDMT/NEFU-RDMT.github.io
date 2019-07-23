#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

//获取用户输入的学生的编号

int GetInputNum()
{
    int num;
    printf("请输入学生的编号(整型)：");
    while(scanf("%d", &num) != 1)
    {
        printf("编号输入错误！请重新输入学生的编号(整型)：");
    }
    return num;
}
