
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"



//�����еĽڵ�������ݵ�����

node * Input(node *p)
{
    //ѧ��
    printf("\t������ѧ����ѧ��(1~100,����0ʱ����):");
    scanf("%d",&p->num);
    while( p->num>100 )
    {
        printf("����ѧ�Ÿ�ʽ�������������룡\n");
        printf("\t������ѧ����ѧ��(1~100,����0ʱ����):");
        scanf("%d",&p->num);
    }
    printf("\n");

    if(p->num == 0)
    {
        free(p);//�ͷ��ڴ�
        p=NULL;//����p
        return NULL;//��ʾ����
    }
//����
    printf("\t������ѧ��������(С��20�ַ�):");
    scanf("%s", p->name);
    while( strlen(p->name)>20 )
    {
        printf("����������ʽ�������������룡\n");
        printf("\t������ѧ��������(С��20�ַ�):");
        scanf("%s", p->name);
    }
    printf("\n");
//�Ա�
    printf("\t������ѧ�����Ա�(m������/f��Ů��):");
    getchar();
    //printf("���е�����1\n");
    scanf("%c",&p->sex);

    while( p->sex!='m' && p->sex!='f' )
    {
        printf("�����Ա��ʽ�������������룡\n");
        printf("\t������ѧ�����Ա�(m������/f��Ů��):");
        getchar();
        scanf("%c",&p->sex);

        //p->sex=getchar();
    }
    printf("\n");
//��ѧ�ɼ�
    printf("\t������ѧ������ѧ�ɼ�(double��,0.00~100.00):");
    scanf("%lf",&p->math_score);
    while( p->math_score<0 || p->math_score>100 )
    {
        printf("������ѧ�ɼ���ʽ�������������룡\n");
        printf("\t������ѧ������ѧ�ɼ�(double��):");
        scanf("%lf",&p->math_score);
    }
    printf("\n");
//Ӣ��ɼ�
    printf("\t������ѧ����Ӣ��ɼ�(double��,0.00~100.00):");
    scanf("%lf",&p->english_score);
    while( p->english_score<0 || p->english_score>100 )
    {

        printf("����Ӣ��ɼ���ʽ�������������룡\n");
        printf("\t������ѧ����Ӣ��ɼ�(double��):");
        scanf("%lf",&p->english_score);
    }
    printf("\n");
//���ĳɼ�
    printf("\t������ѧ�������ĳɼ�(double��,0.00~100.00):");
    scanf("%lf",&p->chinese_score);
    while( p->chinese_score<0 || p->chinese_score>100 )
    {
        printf("����Ӣ��ɼ���ʽ�������������룡\n");
        printf("\t������ѧ�������ĳɼ�(double��):");
        scanf("%lf",&p->chinese_score);
    }
    printf("\n");

    //ѧ�����ܳɼ�(double��,0.00~100.00)
    p->sum_score = p->math_score + p->english_score + p->chinese_score ;
    //ѧ����ƽ���ɼ�(double��,0.00~100.00)
    p->ave_score = ( p->math_score + p->english_score + p->chinese_score )/3;

    p->next ==NULL;
    return p;
}
