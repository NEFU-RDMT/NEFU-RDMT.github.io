//获取用户选择的菜单的编号

int GetMenuChoose()
{
    int num;//保存用户选择的菜单编号
    ShowMenu();
    printf("请选择菜单(0 ~ 9):");
    while(1 != scanf("%d", &num) || num < 0 || num > 9)
    {
        ShowMenu();
        printf("选择菜单错误，请重新选择(0 ~ 9):");
        fflush(stdin);//清空输入缓冲区
    }
    return num;
}
