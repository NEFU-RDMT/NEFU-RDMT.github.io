#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"



void Main_Modify(node *phead)
{
    int running=1;
    int choose;

    int num;
    char name[20];
    int rank;

    while(running)
    {
        printf("\t  666.������һ��  1.��ѧ���޸�  2.�������޸�  3.�������޸�\n");
        printf("\t��ѡ���޸ķ�ʽ:");
        scanf("%d",&choose);

        while( choose!=666 && choose!=1 && choose!=2 && choose!=3  )
        {
            printf("��ȡ��ѡ�񲻷��ϸ�ʽ�����������룡\n");
            printf("\t��ѡ���޸ķ�ʽ:");
            scanf("%d",&choose);
        }
        printf("\n");

        switch(choose)
        {

        case 666:
            running=0;
            break;

        case 1:
            //printf("���е����\n");
            printf("��������Ҫ�޸ĵ�ѧ��ѧ��(1~100)��");
            scanf("%d",&num);
            while( num<1 || num>100 )
            {
                printf("����ѧ�Ÿ�ʽ����,����������!\n");
                scanf("%d",&num);
            }
            //printf("���е����\n");
            Num_Modify(phead,num);
            Rank(phead);
            break;

        case 2:
            printf("��������Ҫ�޸ĵ�ѧ��������");
            scanf("%s",name);
            Name_Modify(phead,name[20]);
            Rank(phead);
            break;

        case 3:
            printf("��������Ҫ�޸ĵ�ѧ��������");
            scanf("%d",&rank);
            while(rank)
            {
                printf("����ѧ�Ÿ�ʽ����,����������!\n");
                scanf("%d",&rank);
            }
            Rank_Modify(phead,rank);
            Rank(phead);
            break;

        }
    }
}

void Num_Modify(node *phead,int num)
{

    node *p=phead;
    int choose2;
//printf("���е����\n");
    while( p->num != num && p->next!=NULL )//������������Ƿ����ѧ��Ϊnum��ѧ���ڵ�
    {
        p=p->next;
    }
    //printf("���е����\n");
    if(p==NULL)//���ƶ����������
    {
        printf("�����ڸ�ѧ��ѧ����Ϣ��\n");

    }
    else if(p!=NULL)
    {
        printf("1.ѧ��2.����3.�Ա�4.��ѧ�ɼ�5.Ӣ��ɼ�6.���ĳɼ�\n");

        printf("��ѡ����Ҫ�޸���Ϣ:");
        scanf("%d",&choose2);

        while( choose2!=1 && choose2!=2 && choose2!=3 &&
                choose2!=4 && choose2!=5 && choose2!=6 )
        {
            printf("��ȡ��ѡ�񲻷��ϸ�ʽ�����������룡\n");
            printf("��ѡ����Ҫ�޸���Ϣ:");
            scanf("%d",choose2);
        }
        printf("\n");

        switch(choose2)
        {

        case 1:
            printf("�ִ��λ�õ�ѧ��ѧ��Ϊ:%d\n",p->num);
            printf("��������Ҫ�޸ĳɵ�ѧ��ѧ��(����)��");
            scanf("%d",&p->num);
            printf("\n�޸����!\n");
            break;

        case 2:
            printf("�ִ��λ�õ�ѧ������Ϊ:%s\n",p->name);
            printf("��������Ҫ�޸ĳɵ�ѧ������(С��20�ַ�)��");
            scanf("%s", p->name);
            printf("\n�޸���ϣ�\n");
            break;

        case 3:
            printf("�ִ��λ�õ�ѧ���Ա�Ϊ:%c\n",p->sex);
            printf("��������Ҫ�޸ĳɵ�ѧ���Ա�(m/f)��");
            scanf("% c", &p->sex);
            printf("\n�޸���ϣ�\n");
            break;

        case 4:
            printf("�ִ��λ�õ�ѧ����ѧ�ɼ�Ϊ:%lf\n",p->math_score);
            printf("��������Ҫ�޸ĳɵ���ѧ�ɼ�(double��)��");
            scanf("%lf",&p->math_score);
            //ѧ�����ܳɼ�
            p->sum_score = p->math_score + p->english_score + p->chinese_score ;
            //ѧ����ƽ���ɼ�
            p->ave_score = ( p->math_score + p->english_score + p->chinese_score )/3;
            printf("\n�޸���ϣ�\n");
            break;

        case 5:
            printf("�ִ��λ�õ�ѧ��Ӣ��ɼ�Ϊ:%lf\n",p->english_score);
            printf("��������Ҫ�޸ĳɵ�Ӣ��ɼ�(double��)��");
            scanf("%lf", &p->english_score);
            //ѧ�����ܳɼ�
            p->sum_score = p->math_score + p->english_score + p->chinese_score ;
            //ѧ����ƽ���ɼ�
            p->ave_score = ( p->math_score + p->english_score + p->chinese_score )/3;
            printf("\n�޸���ϣ�\n");
            break;

        case 6:
            printf("�ִ��λ�õ�ѧ�����ĳɼ�Ϊ:%lf\n",p->chinese_score);
            printf("��������Ҫ�޸ĳɵ����ĳɼ�(double��)��");
            scanf("%lf",&p->chinese_score);
            //ѧ�����ܳɼ�
            p->sum_score = p->math_score + p->english_score + p->chinese_score ;
            //ѧ����ƽ���ɼ�
            p->ave_score = ( p->math_score + p->english_score + p->chinese_score )/3;
            printf("\n�޸���ϣ�\n");
            break;

        }
    }
}

void Name_Modify(node *phead,char name[20])
{
    node *p=phead;
    int choose2;

    while(strcpy(p->name,name)!=0 && p->next!=NULL )//������������Ƿ��������Ϊname��ѧ���ڵ�
    {
        p=p->next;
    }
    if(p==NULL)
    {
        printf("�����ڸ�ѧ��ѧ����Ϣ��\n");

    }
    else if(p!=NULL)
    {
        printf("1.ѧ��2.����3.�Ա�4.��ѧ�ɼ�5.Ӣ��ɼ�6.���ĳɼ�\n");
        printf("��ѡ����Ҫ�޸���Ϣ�ı��:");
        scanf("%d",&choose2);

        while( choose2!=1 && choose2!=2 && choose2!=3&&
              choose2!=4 && choose2!=5 && choose2!=6 )
        {
            printf("��ȡ��ѡ�񲻷��ϸ�ʽ�����������룡\n");
            printf("��ѡ����Ҫ�޸���Ϣ�ı��:");
            scanf("%d",&choose2);
        }
        printf("\n");

        switch(choose2)
        {

        case 1:

            printf("�ִ��λ�õ�ѧ��ѧ��Ϊ:%d\n",p->num);
            printf("��������Ҫ�޸ĳɵ�ѧ��ѧ��(����)��");
            scanf("%d",&p->num);
            printf("\n�޸����!\n");
            break;

        case 2:
            printf("�ִ��λ�õ�ѧ������Ϊ:%s\n",p->name);
            printf("��������Ҫ�޸ĳɵ�ѧ������(С��20�ַ�)��");
            scanf("%s", p->name);
            printf("\n�޸���ϣ�\n");
            break;

        case 3:
            printf("�ִ��λ�õ�ѧ���Ա�Ϊ:%c\n",p->sex);
            printf("��������Ҫ�޸ĳɵ�ѧ���Ա�(m/f)��");
            scanf("% c", &p->sex);
            printf("\n�޸���ϣ�\n");
            break;

        case 4:
            printf("�ִ��λ�õ�ѧ����ѧ�ɼ�Ϊ:%lf\n",p->math_score);
            printf("��������Ҫ�޸ĳɵ���ѧ�ɼ�(double��)��");
            scanf("%lf",&p->math_score);
            //ѧ�����ܳɼ�
            p->sum_score = p->math_score + p->english_score + p->chinese_score ;
            //ѧ����ƽ���ɼ�
            p->ave_score = ( p->math_score + p->english_score + p->chinese_score )/3;
            printf("\n�޸���ϣ�\n");
            break;

        case 5:
            printf("�ִ��λ�õ�ѧ��Ӣ��ɼ�Ϊ:%lf\n",p->english_score);
            printf("��������Ҫ�޸ĳɵ�Ӣ��ɼ�(double��)��");
            scanf("%lf", &p->english_score);
            //ѧ�����ܳɼ�
            p->sum_score = p->math_score + p->english_score + p->chinese_score ;
            //ѧ����ƽ���ɼ�
            p->ave_score = ( p->math_score + p->english_score + p->chinese_score )/3;
            printf("\n�޸���ϣ�\n");
            break;

        case 6:
            printf("�ִ��λ�õ�ѧ�����ĳɼ�Ϊ:%lf\n",p->chinese_score);
            printf("��������Ҫ�޸ĳɵ����ĳɼ�(double��)��");
            scanf("%lf",&p->chinese_score);
            //ѧ�����ܳɼ�
            p->sum_score = p->math_score + p->english_score + p->chinese_score ;
            //ѧ����ƽ���ɼ�
            p->ave_score = ( p->math_score + p->english_score + p->chinese_score )/3;
            printf("\n�޸���ϣ�\n");
            break;

        }
    }
}

void Rank_Modify(node *phead,int rank)
{
    node *p=phead;
    int choose2;

    while(p->rank!=rank && p->next!=NULL )//������������Ƿ��������Ϊrank��ѧ���ڵ�
    {
        p=p->next;
    }
    if(p==NULL)
    {
        printf("�����ڸ�ѧ��ѧ����Ϣ��\n");

    }
    else if(p!=NULL)
    {
        printf("1.ѧ��2.����3.�Ա�4.��ѧ�ɼ�5.Ӣ��ɼ�6.���ĳɼ�\n");
        printf("��ѡ����Ҫ�޸���Ϣ�ı��:");
        scanf("%d",&choose2);

        while(  choose2!=1 && choose2!=2 && choose2!=3 &&
                choose2!=4 && choose2!=5 && choose2!=6 )
        {
            printf("��ȡ��ѡ�񲻷��ϸ�ʽ�����������룡\n");
            printf("��ѡ����Ҫ�޸���Ϣ�ı��:");
            scanf("%d",&choose2);
        }
        printf("\n");

        switch(choose2)
        {


        case 1:
            printf("�ִ��λ�õ�ѧ��ѧ��Ϊ:%d\n",p->num);
            printf("��������Ҫ�޸ĳɵ�ѧ��ѧ��(����)��");
            scanf("%d",&p->num);
            printf("\n�޸����!\n");
            break;

        case 2:
            printf("�ִ��λ�õ�ѧ������Ϊ:%s\n",p->name);
            printf("��������Ҫ�޸ĳɵ�ѧ������(С��20�ַ�)��");
            scanf("%s", p->name);
            printf("\n�޸���ϣ�\n");
            break;

        case 3:
            printf("�ִ��λ�õ�ѧ���Ա�Ϊ:%c\n",p->sex);
            printf("��������Ҫ�޸ĳɵ�ѧ���Ա�(m/f)��");
            scanf("% c", &p->sex);
            printf("\n�޸���ϣ�\n");
            break;

        case 4:
            printf("�ִ��λ�õ�ѧ����ѧ�ɼ�Ϊ:%lf\n",p->math_score);
            printf("��������Ҫ�޸ĳɵ���ѧ�ɼ�(double��)��");
            scanf("%lf",&p->math_score);
            //ѧ�����ܳɼ�
            p->sum_score = p->math_score + p->english_score + p->chinese_score ;
            //ѧ����ƽ���ɼ�
            p->ave_score = ( p->math_score + p->english_score + p->chinese_score )/3;
            printf("\n�޸���ϣ�\n");
            break;

        case 5:
            printf("�ִ��λ�õ�ѧ��Ӣ��ɼ�Ϊ:%lf\n",p->english_score);
            printf("��������Ҫ�޸ĳɵ�Ӣ��ɼ�(double��)��");
            scanf("%lf", &p->english_score);
            //ѧ�����ܳɼ�
            p->sum_score = p->math_score + p->english_score + p->chinese_score ;
            //ѧ����ƽ���ɼ�
            p->ave_score = ( p->math_score + p->english_score + p->chinese_score )/3;
            printf("\n�޸���ϣ�\n");
            break;

        case 6:
            printf("�ִ��λ�õ�ѧ�����ĳɼ�Ϊ:%lf\n",p->chinese_score);
            printf("��������Ҫ�޸ĳɵ����ĳɼ�(double��)��");
            scanf("%lf",&p->chinese_score);
            //ѧ�����ܳɼ�
            p->sum_score = p->math_score + p->english_score + p->chinese_score ;
            //ѧ����ƽ���ɼ�
            p->ave_score = ( p->math_score + p->english_score + p->chinese_score )/3;
            printf("\n�޸���ϣ�\n");
            break;
        }
    }
}

