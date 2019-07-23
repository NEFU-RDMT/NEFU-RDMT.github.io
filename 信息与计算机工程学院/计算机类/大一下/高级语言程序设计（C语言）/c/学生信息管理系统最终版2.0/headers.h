#ifndef HEADERS_H_INCLUDED
#define HEADERS_H_INCLUDED
#endif // HEADERS_H_INCLUDED

typedef struct student
{
    int num;        //学生的编号
    char name[20];  //学生的姓名
    char sex;        //学生的性别

    double math_score; //学生的数学成绩
    double english_score; //学生的英语成绩
    double chinese_score; //学生的语文成绩
    double sum_score;//学生的总成绩
    double ave_score; //学生的平均成绩

    int rank;//学生的排名

    struct student *next;//下一个节点的指针
}node;

//1.Add
node *Input();
void Add();

//2.修改学生信息
void Main_Modify();
void Num_Modify();
void Name_Modify();
void Rank_Modify();

//3.显示学生信息
void Main_Show();
void Num_Show();
void Name_Show();
void Rank_Show();

//4.查询学生信息
void Main_Search();
void Num_Search();
void Name_Search();
void Rank_Search();

//5.删除学生信息
void Main_Delete();
void Num_Delete();
void Name_Delete();
void Rank_Delete();

//6.对学生信息进行排序
void Main_Sort();
    //升序
       void Num_Sort_Up();
       void Name_Sort_Up();
       void Math_Score_Sort_Up();
       void English_Score_Sort_Up();
       void Chinese_Score_Sort_Up();
       void Ave_Score_Sort_Up();
       void Sum_Score_Sort_Up();
    //降序
       void Num_Sort_Down();
       void Name_Sort_Down();
       void Math_Score_Sort_Down();
       void English_Score_Sort_Down();
       void Chinese_Score_Sort_Down();
       void Ave_Score_Sort_Down();
       void Sum_Score_Sort_Down();

//7.保存学生信息至记录文件
void Save_To_File();

//8.从记录文件读取学生信息
void Read_From_File();

//9.新建学生信息文件
void Create_New_Node();

//获取链表长度
int Length();

//显示菜单
void Show_Menu_Head ();
void Show_Menu_Main ();

//输出
void Output();

//为所有节点重新赋排名
void Rank();
