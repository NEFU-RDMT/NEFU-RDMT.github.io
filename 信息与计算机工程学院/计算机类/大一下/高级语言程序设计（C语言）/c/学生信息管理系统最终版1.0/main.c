#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"


int main()
{
    Show_Menu_Head ();
    Show_Menu_Main ();

    node *phead=NULL; //头节点
    phead->next == NULL;
    int running = 1;//保证程序持续进行的条件
    FILE *fp;
    int choose;//选择

    phead=(node *)malloc(sizeof(node));
    if(phead==NULL) exit(1);


    while(running)
    {
        printf("请输入需要进行的菜单操作数字:");
        scanf("%d",&choose);
        while(  choose!=0 &&
                choose!=1 && choose!=2 && choose!=3 &&
                choose!=4 && choose!=5 && choose!=6 &&
                choose!=7 && choose!=8 && choose!=9 )
        {
            printf("输入操作数字有误，请重新输入！\n");
            printf("请输入需要进行的菜单操作数字:");
            scanf("%d",&choose);
        }
        printf("\n");

        switch( choose )
        {

        case 0:
            running = 0;
            printf("系统已退出，欢迎下次使用!\n");
            break;

        case 1:
            Add(phead);
            break;

        case 2:
            Main_Modify(phead);
            break;

        case 3:
            Main_Show(phead);
            break;

        case 4:
            Main_Search(phead);
            break;

        case 5:
            Main_Delete(phead);
            break;

        case 6:
            Main_Sort(phead);
            break;

        case 7:
            Save_To_File(phead);
            break;

        case 8:
            Read_From_File(phead);
            break;

        case 9:
            Create_New_File(phead);
            break;

        }
    }
    return 0;
}















