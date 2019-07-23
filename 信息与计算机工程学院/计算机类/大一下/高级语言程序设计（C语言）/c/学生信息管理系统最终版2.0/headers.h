#ifndef HEADERS_H_INCLUDED
#define HEADERS_H_INCLUDED
#endif // HEADERS_H_INCLUDED

typedef struct student
{
    int num;        //ѧ���ı��
    char name[20];  //ѧ��������
    char sex;        //ѧ�����Ա�

    double math_score; //ѧ������ѧ�ɼ�
    double english_score; //ѧ����Ӣ��ɼ�
    double chinese_score; //ѧ�������ĳɼ�
    double sum_score;//ѧ�����ܳɼ�
    double ave_score; //ѧ����ƽ���ɼ�

    int rank;//ѧ��������

    struct student *next;//��һ���ڵ��ָ��
}node;

//1.Add
node *Input();
void Add();

//2.�޸�ѧ����Ϣ
void Main_Modify();
void Num_Modify();
void Name_Modify();
void Rank_Modify();

//3.��ʾѧ����Ϣ
void Main_Show();
void Num_Show();
void Name_Show();
void Rank_Show();

//4.��ѯѧ����Ϣ
void Main_Search();
void Num_Search();
void Name_Search();
void Rank_Search();

//5.ɾ��ѧ����Ϣ
void Main_Delete();
void Num_Delete();
void Name_Delete();
void Rank_Delete();

//6.��ѧ����Ϣ��������
void Main_Sort();
    //����
       void Num_Sort_Up();
       void Name_Sort_Up();
       void Math_Score_Sort_Up();
       void English_Score_Sort_Up();
       void Chinese_Score_Sort_Up();
       void Ave_Score_Sort_Up();
       void Sum_Score_Sort_Up();
    //����
       void Num_Sort_Down();
       void Name_Sort_Down();
       void Math_Score_Sort_Down();
       void English_Score_Sort_Down();
       void Chinese_Score_Sort_Down();
       void Ave_Score_Sort_Down();
       void Sum_Score_Sort_Down();

//7.����ѧ����Ϣ����¼�ļ�
void Save_To_File();

//8.�Ӽ�¼�ļ���ȡѧ����Ϣ
void Read_From_File();

//9.�½�ѧ����Ϣ�ļ�
void Create_New_Node();

//��ȡ������
int Length();

//��ʾ�˵�
void Show_Menu_Head ();
void Show_Menu_Main ();

//���
void Output();

//Ϊ���нڵ����¸�����
void Rank();
