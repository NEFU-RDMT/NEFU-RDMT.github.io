//��ȡ�û�ѡ��Ĳ˵��ı��

int GetMenuChoose()
{
    int num;//�����û�ѡ��Ĳ˵����
    ShowMenu();
    printf("��ѡ��˵�(0 ~ 9):");
    while(1 != scanf("%d", &num) || num < 0 || num > 9)
    {
        ShowMenu();
        printf("ѡ��˵�����������ѡ��(0 ~ 9):");
        fflush(stdin);//������뻺����
    }
    return num;
}
