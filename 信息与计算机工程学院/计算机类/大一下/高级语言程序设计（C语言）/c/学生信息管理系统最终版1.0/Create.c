#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

//����һ���ڵ�,���᷵��һ���´�����ѧ����Ϣ�ڵ��ָ��
/*
void Create()
{
    int sex;
    student *p = (student *)malloc( sizeof(student) );//��̬����ռ䣬�洢ѧ����Ϣ
    if( p == NULL )
    {
        printf("�����ڴ�ռ�ʧ��!\n");
        return NULL;
    }

    printf("������ѧ����ѧ��(����)��");
    while(scanf("%d", &p->num) !=  1 || GetPrevAddr(p->num) )
    {
        printf("ѧ��������������Ѿ����ڣ�����������ѧ���ı��(����)��");
        fflush(stdin);
    }

    printf("������ѧ��������(С��20�ַ�)��");
    scanf("%20s", p->name);

    printf("��ѡ��ѧ�����Ա�(1.��  2.Ů)��");
    while(scanf("%d", &sex) != 1 || sex < 1 || sex > 2)
    {
        printf("�Ա�ѡ�����������ѡ��ѧ�����Ա�(1.��  2.Ů)��");
        fflush(stdin);
    }
    if(1 == sex)
    {
        pstu->sex = m;
    }
    else
    {
        pstu->sex = f;
    }

    printf("������ѧ������ѧ�ɼ�(С��20�ַ�)��");
    scanf("%20s", p->math_score);
    p->next = NULL;

    printf("������ѧ����Ӣ��ɼ�(С��20�ַ�)��");
    scanf("%20s", p->math_score);
    p->next = NULL;

    printf("������ѧ�������ĳɼ�(С��20�ַ�)��");
    scanf("%20s", p->math_score);
    p->next = NULL;

    //printf("������ѧ�����ܳɼ�(С��20�ַ�)��");
    p->sum_score = p->math_score + p->english_score + p->chinese_score ;
    //printf("������ѧ����ƽ���ɼ�(С��20�ַ�)��");
    p->ave_score = ( p->math_score + p->english_score + p->chinese_score )/3;

}

/*
    printf("������ѧ��������(10 ~ 40)��");
    while(1 != scanf("%d", &pstu->age) || pstu->age < 10 || pstu->age > 40)
    {
        printf("���������������������ѧ��������(10 ~ 40)��");
        fflush(stdin);
    }
    */
