#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

//��ȡ�û������ѧ���ı��

int GetInputNum()
{
    int num;
    printf("������ѧ���ı��(����)��");
    while(scanf("%d", &num) != 1)
    {
        printf("��������������������ѧ���ı��(����)��");
    }
    return num;
}
