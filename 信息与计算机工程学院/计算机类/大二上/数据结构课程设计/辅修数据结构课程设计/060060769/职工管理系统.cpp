#include<iostream> 
#include<string> 
#include<fstream> 
using namespace std; 

const N=50; // 定义系统可录入的员工最大数值 

string Ename[N]; 
long Enum[N]; 
char Esex[N]; 
int Eage[N]; 
char Emarriage[N]; 
int Edepart[N]; 
int Eposition[N]; 
int Edegree[50]; 
int Eworktime[N]; 
float Epay[N]; 

class Employee 
{ 
public: 
string Employeename; 
long Employeenum; 
char Employeesex; 
int Employeeage; 
char Employeemarriage; 
int Employeedepart; 
int Employeeposition; 
int Employeedegree; 
int Employeeworktime; 
float Employeepay; 


static long EmployeeMaxNum; 
static float EmployeeBasePay; 

void NewInfo(); 
void ShowInfo(); 
void showall(); 
void showdepart(int depart); 
void showdegree(int degree); 
void showage(int min,int max); 
void shownum(long number); 
void RefreshInfo(); 
void DeleteInfo(); 
float Pay(int Employeegrade); 
static int MaxNum(); 
}; 



class DBOperate 
{ 
public: 
string Employeename; 
long Employeenum; 
char Employeesex; 
int Employeeage; 
char Employeemarriage; 
int Employeedepart; 
int Employeeposition; 
int Employeedegree; 
int Employeeworktime; 
float Employeepay; 


static long EmployeeMaxNum; 
static float EmployeeBasePay; 


void WriteIn(int iflag); 
void ReadOut(); 
void RefreshMaxNum(int iflag); //i=1 or -1 or 0 
}; 




long Employee::EmployeeMaxNum = 1000; 
float Employee::EmployeeBasePay = 1500; 


int Employee::MaxNum() //返回系统已经存储的人数 
{ 
int MN = 0; 
ifstream myf; 
myf.open("EmployeeMaxNum.txt"); 
myf>>MN; 
cout<<MN<<endl; 
myf.close(); 
return MN; 
} 



void Employee::NewInfo() //添加新成员函数 
{ 
cout<<"新员工姓名: "; 
cin>>Employee::Employeename; 

Employee::Employeenum = EmployeeMaxNum + Employee::MaxNum()+1; 

cout<<"新员工性别 (F为女性，M为男性): "; 
cin>>Employee::Employeesex; 

cout<<"新员工年龄: "; 
cin>>Employee::Employeeage; 

cout<<"新员工婚姻状况（Y为已婚，N为未婚）: "; 
cin>>Employee::Employeemarriage; 

cout<<"新员工学历,请输入相应学历的序号: "<<endl; 
cout<<" [1:初中 2:高中 3:本科 4:硕士 5:博士] "; 
cin>>Employee::Employeedegree; 
while(Employee::Employeedegree !=1&&Employee::Employeedegree !=2&&Employee::Employeedegree !=3&&Employee::Employeedegree !=4&&Employee::Employeedegree !=5) 
{ 
cout<<"输入有误，请重新输入:"<<endl; 
cout<<" [1:初中 2:高中 3:本科 4:硕士 5:博士]"; 
cin>>Employee::Employeedegree; 
} 

cout<<"新员工所在部门,请输入相应部门的序号:"<<endl; 
cout<<" [1:董事会 2:市场部 3:公关部 4:客服中心 5:信息中心] "; 
cin>>Employee::Employeedepart; 
while(Employee::Employeedepart !=1&&Employee::Employeedepart !=2&&Employee::Employeedepart !=3&&Employee::Employeedepart !=4&&Employee::Employeedepart!=5) 
{ 
cout<<"输入有误，请重新输入:"<<endl; 
cout<<" [1:董事会 2:市场部 3:公关部 4:客服中心 5:信息中心] "; 
cin>>Employee::Employeedepart; 
} 

cout<<"新员工职位, 请输入相应职位的序号: "<<endl; 
cout<<" [1:临时职员 2: 正式职员 3:主任 4:部门经理 5:董事长] "; 
cin>>Employee::Employeeposition; 
while(Employee::Employeeposition !=1&&Employee::Employeeposition !=2&&Employee::Employeeposition !=3&&Employee::Employeeposition !=4&&Employee::Employeeposition !=5) 
{ 
cout<<"输入有误，请重新输入:"<<endl; 
cout<<" [1:临时职员 2: 正式职员 3:主任 4:部门经理 5:董事长] "; 
cin>>Employee::Employeeposition; 
} 

cout<<"新员工的工作时(不需要输入单位): "; 
cin>>Employee::Employeeworktime; 


Employee::Employeepay = Employee::Pay(Employee::Employeeposition); 

DBOperate dbo; 
dbo.ReadOut(); 

int MaxNum = Employee::MaxNum(); 

Enum[MaxNum] = Employee::Employeenum; 
Ename[MaxNum] = Employee::Employeename; 
Esex[MaxNum] = Employee::Employeesex; 
Eage[MaxNum] = Employee::Employeeage; 
Emarriage[MaxNum] = Employee::Employeemarriage; 
Edegree[MaxNum] = Employee::Employeedegree; 
Edepart[MaxNum] = Employee::Employeedepart; 
Eposition[MaxNum] = Employee::Employeeposition; 
Eworktime[MaxNum] = Employee::Employeeworktime; 
Epay[MaxNum] = Employee::Employeepay; 

dbo.WriteIn(1); 
cout<<" 添加新成员成功！"<<endl; 

return; 
} 



void Employee::ShowInfo() //程序主体 数据输出函数 
{ 

int choice1,choice2,min,max; 
long searchnum; 
Employee e; 


cout<<" 请选择查询方式："<<endl; 
cout<<"******************************************"<<endl; 
cout<<"* 输出全体职工信息--------------------- 1"<<endl; 
cout<<"* 按职工部门输出----------------------- 2"<<endl; 
cout<<"* 按职工学历输出----------------------- 3"<<endl; 
cout<<"* 按职工年龄输出----------------------- 4"<<endl; 
cout<<"* 按职工编号输出----------------------- 5"<<endl; 
cout<<"******************************************"<<endl; 
cin>>choice1; 

switch(choice1) 
{ 
case 1: showall();break; 
case 2: cout<<"请输入要查询职工的部门编号: [1:董事会 2:市场部 3:公关部 4:客服中心 5:信息中心] " ; 
cin>>choice2; 
e.showdepart(choice2);break; 
case 3: cout<<"请输入要查询职工的学历编号: [1:初中 2:高中 3:本科 4:硕士 5:博士] "; 
cin>>choice2; 
e.showdegree(choice2);break; 
case 4: cout<<"请输入要查询的年龄范围: "; 
cout<<"最小值: "; 
cin>>min; 
cout<<"最大值: "; 
cin>>max; 
e.showage(min,max);break; 
case 5: cout<<"请输入要查询的员工号: "; 
cin>>searchnum; 
e.shownum(searchnum);break; 

default: cout<<"出错啦! "<<endl;break; 

} 

} 

void Employee::showall() //全体员工输出函数 
{ int i; 
long number; 
for(i=0;i<Employee::MaxNum();i++) 
{ 
number = Enum[i]; 
shownum(number); 
} 
} 

void Employee::showdepart(int depart) //按员工所在部门输出函数 
{ 
int i; 
switch(depart) 
{ 
case 1: cout<<"董事会的成员有: >"<<endl; break; 
case 2: cout<<"市场部的成员有: >"<<endl; break; 
case 3: cout<<"公关部的成员有: >"<<endl; break; 
case 4: cout<<"客服中心成员有: >"<<endl; break; 
case 5: cout<<"信息中心成员有: >"<<endl; break; 
default: cout<<"输入错误！>"<<endl; break; 
} 
for(i=0;i<Employee::MaxNum();i++) 
{ 
if(Edepart[i] == depart) 
{ 
long number = Enum[i]; 
shownum(number); 
} else continue; 

} 
} 



void Employee::showdegree(int degree) //按员工学历输出函数 
{ 
int i; 
switch(degree) 
{ 
case 1:cout<<"初中学历的员工有:"<<endl;break; 
case 2:cout<<"高中学历的员工有:"<<endl;break; 
case 3:cout<<"本科学历的员工有:"<<endl;break; 
case 4:cout<<"硕士学位的员工有:"<<endl;break; 
case 5:cout<<"博士学位的员工有:"<<endl;break; 
} 
for(i=0;i<Employee::MaxNum();i++) 
{ 
if(Edegree[i] == degree) 
{ 
long number = Enum[i]; 
shownum(number); 
} else continue; 

} 
} 


void Employee::showage(int min,int max) //按员工年龄段输出函数 
{ 
int i; 
for(i=0;i<Employee::MaxNum();i++) 
{ 
if(Eage[i]>=min&&Eage[i]<=max) 
{ 
long number = Enum[i]; 
shownum(number); 
} 
else continue; 
} 
} 




void Employee::shownum(long number) //按员工编号输出函数 
{ 
int i; 
for(i=0;i<Employee::MaxNum();i++) 
{ 
if(Enum[i] == number) 
{ 
cout<<"**********************************"<<endl; 
cout<<"员工编号 >"<<Enum[i]<<endl; 
cout<<"姓 名 >"<<Ename[i]<<endl; 
cout<<"性 别 >"; 
if(Esex[i]=='F') cout<<"女 "<<endl; 
else if(Esex[i]=='M') cout<<"男 "<<endl; 
cout<<"年 龄 >"<<Eage[i]<<"岁"<<endl; 
cout<<"婚姻情况 >"; 
if(Emarriage[i]=='Y') cout<<"已婚 "<<endl; 
else if(Emarriage[i]=='N') cout<<"未婚 "<<endl; 
cout<<"学 历 >"; 
switch (Edegree[i]) 
{ 
case 1:cout<<"初 中 "<<endl;break; 
case 2:cout<<"高 中 "<<endl;break; 
case 3:cout<<"本 科 "<<endl;break; 
case 4:cout<<"硕 士 "<<endl;break; 
case 5:cout<<"博 士 "<<endl;break; 
} 

cout<<"所在部门 >"; 
switch (Edepart[i]) 
{ 
case 1:cout<<"董事会 "<<endl;break; 
case 2:cout<<"市场部 "<<endl;break; 
case 3:cout<<"公关部 "<<endl;break; 
case 4:cout<<"客服中心 "<<endl;break; 
case 5:cout<<"信息中心 "<<endl;break; 
} 

cout<<"所任职务 >"; 
switch (Eposition[i]) 
{ 
case 1:cout<<"临时成员 "<<endl;break; 
case 2:cout<<"正式员工 "<<endl;break; 
case 3:cout<<"主任 "<<endl;break; 
case 4:cout<<"部门经理 "<<endl;break; 
case 5:cout<<"董事长 "<<endl;break; 
} 

cout<<"工作时长 >"<<Eworktime[i]<<"小时"<<endl; 
cout<<"额定工资 >"<<Epay[i]<<"元"<<endl; 
cout<<"**********************************"<<endl; 
} 
else continue; 
} 
} 



void Employee::RefreshInfo() //修改员工信息的函数 
{ 
int cNum = 1000; 
DBOperate dbo; 
dbo.ReadOut(); 
void Employee::shownum(long number); 

cout<<"请输入您要修改的员工编号： >"; 
cin>>cNum; 
int MN; 
MN = Employee::MaxNum(); 

for(int i=0;i<MN;i++) //遍历数据文件，查找要修改的员工数据 
{ 
if(Enum[i] == cNum) 
{ 
Employee::shownum(cNum); 

cout<<"请输入该员工的新信息: "<<endl; 

cout<<"新员工姓名: "; //录入员工的新的数据，员工号保持不变 
cin>>Employee::Employeename; 
Ename[i] = Employee::Employeename; 

cout<<"新员工性别: [F为女性，M为男性]: "; 
cin>>Employee::Employeesex; 
Esex[i] = Employee::Employeesex; 

cout<<"新员工年龄: "; 
cin>>Employee::Employeeage; 
Eage[i] = Employee::Employeeage; 

cout<<"新员工婚姻状况（Y为已婚，N为未婚）: "; 
cin>>Employee::Employeemarriage; 
Emarriage[i] = Employee::Employeemarriage; 

cout<<"新员工学历,请输入相应学历的序号:"<<endl; 
cout<<" [1:初中 2:高中 3:本科 4:硕士 5:博士] "; 
cin>>Employee::Employeedegree; 
while(Employee::Employeedegree !=1&&Employee::Employeedegree !=2&&Employee::Employeedegree !=3&&Employee::Employeedegree !=4&&Employee::Employeedegree !=5) 
{ 
cout<<"输入有误，请重新输入:"<<endl; 
cout<<" [ 1:专科 2:本科 3:硕士 4:博士] "; 
cin>>Employee::Employeedegree; 
} 
Edegree[i] = Employee::Employeedegree; 

cout<<"新员工所在部门,请输入相应部门的序号: "<<endl; 
cout<<" [1:董事会 2:市场部 3:公关部 4:客服中心 5:信息中心] "; 
cin>>Employee::Employeedepart; 
while(Employee::Employeedepart !=1&&Employee::Employeedepart !=2&&Employee::Employeedepart !=3&&Employee::Employeedepart !=4&&Employee::Employeedepart!=5) 
{ 
cout<<"输入有误，请重新输入:"<<endl; 
cout<<" [1:董事会 2:市场部 3:公关部 4:客服中心 5:信息中心] "; 
cin>>Employee::Employeedepart; 
} 
Edepart[i] = Employee::Employeedepart; 

cout<<"新员工职位,请输入相应职位的序号:"<<endl; 
cout<<" [1:临时职员 2: 正式职员 3:主任 4:部门经理 5:董事长] "; 
cin>>Employee::Employeeposition; 
while(Employee::Employeeposition !=1&&Employee::Employeeposition !=2&&Employee::Employeeposition !=3&&Employee::Employeeposition !=4&&Employee::Employeeposition !=5) 
{ 
cout<<"输入有误，请重新输入:"<<endl; 
cout<<" [1:临时职员 2: 正式职员 3:主任 4:部门经理 5:董事长] "; 
cin>>Employee::Employeeposition; 
} 
Eposition[i] = Employee::Employeeposition; 



cout<<"新员工的工作时 (不需要输入单位): "; 
cin>>Employee::Employeeworktime; 
Eworktime[i] = Employee::Employeeworktime; 


Epay[i] = Employee::Pay(Employee::Employeeposition); 

break; 
} 
} 


dbo.WriteIn(0); 
} 

void Employee::DeleteInfo() //删除员工数据的函数 
{ char tmp; 
int cNum = 1000; 
DBOperate dbo; 
dbo.ReadOut(); 
void Employee::shownum(long number); 

cout<<"请输入您要修改的员工编号>： "; 
cin>>cNum; 
int MN; 
MN = Employee::MaxNum(); 

for(int i=0;i<MN;i++) //遍历数据文件，查找要删除的员工 
{ 
if(Enum[i] == cNum) 
Employee::shownum(cNum); 
} 

cout<<"确认要删除该员工信息？(Y为确认 N为放弃)： "; 
cin>>tmp; 
if(tmp=='Y') 
{ 
if(i==MN-1) 
dbo.WriteIn(-1); 
else 
{ 
for(int j=i;j<MN-1;j++) 
{ Enum[j] = Enum[j+1]; } 
dbo.WriteIn(-1); 
} 

cout<<" 删除操作成功 ! "<<endl; 
} 

} 

float Employee::Pay(int Employeeposition) //根据员工职位计算工资的函数 
{ 
float tmpPay; 
tmpPay = Employee::EmployeeBasePay + Employee::Employeeposition * Employee::EmployeeBasePay; 
return tmpPay; 
} 


void DBOperate::WriteIn(int iflag) //数据操作函数 写入 
{ 
DBOperate::RefreshMaxNum(iflag); 
ofstream myf("Employee.txt"); 
Employee e; 
int MN; 
MN = e.MaxNum(); 
for(int i=0;i<MN;i++) 
{ 
myf<<Enum[i]<<'\n'<<Ename[i]<<'\n'<<Esex[i]<<'\n'<<Eage[i]<<'\n'<<Emarriage[i]<<'\n'<<Edegree[i]<<'\n'<<Edepart[i]<<'\n'<<Eposition[i]<<'\n'<<Eworktime[i]<<'\n'<<Epay[i]<<'\n'; 
} 
myf.close(); 
return; 
} 


void DBOperate::ReadOut() //数据操作函数 读出 
{ 
ifstream myf("Employee.txt"); 

Employee e; 
int MN; 
MN = e.MaxNum(); 
for(int i=0 ;i<MN;i++) 
{ 
myf>>DBOperate::Employeenum>>DBOperate::Employeename>>DBOperate::Employeesex>>DBOperate::Employeeage>>DBOperate::Employeemarriage 
>>DBOperate::Employeedegree>>DBOperate::Employeedepart>>DBOperate::Employeeposition>>DBOperate::Employeeworktime>>DBOperate::Employeepay; 

Enum[i] = DBOperate::Employeenum; 
Ename[i] = DBOperate::Employeename; 
Esex[i] = DBOperate::Employeesex; 
Eage[i] = DBOperate::Employeeage; 
Emarriage[i] = DBOperate::Employeemarriage; 
Edegree[i] = DBOperate::Employeedegree; 
Edepart[i] = DBOperate::Employeedepart; 
Eposition[i] = DBOperate::Employeeposition; 
Eworktime[i] = DBOperate::Employeeworktime; 
Epay[i] = DBOperate::Employeepay; 
} 
myf.close(); 
} 



void DBOperate::RefreshMaxNum(int iflag) //更新系统中员工计数文件的函数 
{ 
int MaxNum = 0; 
ifstream myif("EmployeeMaxNum.txt"); 
myif>>MaxNum; 
myif.close(); 
MaxNum = MaxNum+iflag; 
ofstream myof("EmployeeMaxNum.txt"); 
myof<<MaxNum; 
myof.close(); 
} 


int main() //主函数 
{ 


int select = 0; 
while(select!=5) 
{ 

cout<<"          欢迎进入此系统"<<endl; 
cout<<"  请选择功能 "<<endl; 
cout<<"                             "<<endl; 
cout<<"  1.新建并输入职工数据 "<<endl; 
cout<<"  2.按条件输出职工数据 "<<endl; 
cout<<"  3.修改指定职工的数据 "<<endl; 
cout<<"  4.删除数据 "<<endl; 
cout<<"  5.退出 "<<endl; 
cout<<"                            "<<endl; 
cout<<"                             "<<endl; 
cout<<" 请选择操作项目: " ; 
cin>>select; 

Employee e; 
DBOperate dbo; 

switch(select) 
{ 
case 1: 
e.NewInfo(); break; 
case 2: 
dbo.ReadOut(); 
e.ShowInfo(); break; 
case 3: 
e.RefreshInfo(); break; 
case 4: 
e.DeleteInfo(); break; 
case 5: break; 
default: 
cout<<"命令错误！"<<endl; 
} 

if(select == 5) 
break; 
} 

exit(1); 
return 0; 
}
