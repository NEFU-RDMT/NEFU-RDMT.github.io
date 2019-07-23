#include<iostream> 
#include<string> 
#include<fstream> 
using namespace std; 

const N=50; // ����ϵͳ��¼���Ա�������ֵ 

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


int Employee::MaxNum() //����ϵͳ�Ѿ��洢������ 
{ 
int MN = 0; 
ifstream myf; 
myf.open("EmployeeMaxNum.txt"); 
myf>>MN; 
cout<<MN<<endl; 
myf.close(); 
return MN; 
} 



void Employee::NewInfo() //����³�Ա���� 
{ 
cout<<"��Ա������: "; 
cin>>Employee::Employeename; 

Employee::Employeenum = EmployeeMaxNum + Employee::MaxNum()+1; 

cout<<"��Ա���Ա� (FΪŮ�ԣ�MΪ����): "; 
cin>>Employee::Employeesex; 

cout<<"��Ա������: "; 
cin>>Employee::Employeeage; 

cout<<"��Ա������״����YΪ�ѻ飬NΪδ�飩: "; 
cin>>Employee::Employeemarriage; 

cout<<"��Ա��ѧ��,��������Ӧѧ�������: "<<endl; 
cout<<" [1:���� 2:���� 3:���� 4:˶ʿ 5:��ʿ] "; 
cin>>Employee::Employeedegree; 
while(Employee::Employeedegree !=1&&Employee::Employeedegree !=2&&Employee::Employeedegree !=3&&Employee::Employeedegree !=4&&Employee::Employeedegree !=5) 
{ 
cout<<"������������������:"<<endl; 
cout<<" [1:���� 2:���� 3:���� 4:˶ʿ 5:��ʿ]"; 
cin>>Employee::Employeedegree; 
} 

cout<<"��Ա�����ڲ���,��������Ӧ���ŵ����:"<<endl; 
cout<<" [1:���»� 2:�г��� 3:���ز� 4:�ͷ����� 5:��Ϣ����] "; 
cin>>Employee::Employeedepart; 
while(Employee::Employeedepart !=1&&Employee::Employeedepart !=2&&Employee::Employeedepart !=3&&Employee::Employeedepart !=4&&Employee::Employeedepart!=5) 
{ 
cout<<"������������������:"<<endl; 
cout<<" [1:���»� 2:�г��� 3:���ز� 4:�ͷ����� 5:��Ϣ����] "; 
cin>>Employee::Employeedepart; 
} 

cout<<"��Ա��ְλ, ��������Ӧְλ�����: "<<endl; 
cout<<" [1:��ʱְԱ 2: ��ʽְԱ 3:���� 4:���ž��� 5:���³�] "; 
cin>>Employee::Employeeposition; 
while(Employee::Employeeposition !=1&&Employee::Employeeposition !=2&&Employee::Employeeposition !=3&&Employee::Employeeposition !=4&&Employee::Employeeposition !=5) 
{ 
cout<<"������������������:"<<endl; 
cout<<" [1:��ʱְԱ 2: ��ʽְԱ 3:���� 4:���ž��� 5:���³�] "; 
cin>>Employee::Employeeposition; 
} 

cout<<"��Ա���Ĺ���ʱ(����Ҫ���뵥λ): "; 
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
cout<<" ����³�Ա�ɹ���"<<endl; 

return; 
} 



void Employee::ShowInfo() //�������� ����������� 
{ 

int choice1,choice2,min,max; 
long searchnum; 
Employee e; 


cout<<" ��ѡ���ѯ��ʽ��"<<endl; 
cout<<"******************************************"<<endl; 
cout<<"* ���ȫ��ְ����Ϣ--------------------- 1"<<endl; 
cout<<"* ��ְ���������----------------------- 2"<<endl; 
cout<<"* ��ְ��ѧ�����----------------------- 3"<<endl; 
cout<<"* ��ְ���������----------------------- 4"<<endl; 
cout<<"* ��ְ��������----------------------- 5"<<endl; 
cout<<"******************************************"<<endl; 
cin>>choice1; 

switch(choice1) 
{ 
case 1: showall();break; 
case 2: cout<<"������Ҫ��ѯְ���Ĳ��ű��: [1:���»� 2:�г��� 3:���ز� 4:�ͷ����� 5:��Ϣ����] " ; 
cin>>choice2; 
e.showdepart(choice2);break; 
case 3: cout<<"������Ҫ��ѯְ����ѧ�����: [1:���� 2:���� 3:���� 4:˶ʿ 5:��ʿ] "; 
cin>>choice2; 
e.showdegree(choice2);break; 
case 4: cout<<"������Ҫ��ѯ�����䷶Χ: "; 
cout<<"��Сֵ: "; 
cin>>min; 
cout<<"���ֵ: "; 
cin>>max; 
e.showage(min,max);break; 
case 5: cout<<"������Ҫ��ѯ��Ա����: "; 
cin>>searchnum; 
e.shownum(searchnum);break; 

default: cout<<"������! "<<endl;break; 

} 

} 

void Employee::showall() //ȫ��Ա��������� 
{ int i; 
long number; 
for(i=0;i<Employee::MaxNum();i++) 
{ 
number = Enum[i]; 
shownum(number); 
} 
} 

void Employee::showdepart(int depart) //��Ա�����ڲ���������� 
{ 
int i; 
switch(depart) 
{ 
case 1: cout<<"���»�ĳ�Ա��: >"<<endl; break; 
case 2: cout<<"�г����ĳ�Ա��: >"<<endl; break; 
case 3: cout<<"���ز��ĳ�Ա��: >"<<endl; break; 
case 4: cout<<"�ͷ����ĳ�Ա��: >"<<endl; break; 
case 5: cout<<"��Ϣ���ĳ�Ա��: >"<<endl; break; 
default: cout<<"�������>"<<endl; break; 
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



void Employee::showdegree(int degree) //��Ա��ѧ��������� 
{ 
int i; 
switch(degree) 
{ 
case 1:cout<<"����ѧ����Ա����:"<<endl;break; 
case 2:cout<<"����ѧ����Ա����:"<<endl;break; 
case 3:cout<<"����ѧ����Ա����:"<<endl;break; 
case 4:cout<<"˶ʿѧλ��Ա����:"<<endl;break; 
case 5:cout<<"��ʿѧλ��Ա����:"<<endl;break; 
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


void Employee::showage(int min,int max) //��Ա�������������� 
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




void Employee::shownum(long number) //��Ա������������ 
{ 
int i; 
for(i=0;i<Employee::MaxNum();i++) 
{ 
if(Enum[i] == number) 
{ 
cout<<"**********************************"<<endl; 
cout<<"Ա����� >"<<Enum[i]<<endl; 
cout<<"�� �� >"<<Ename[i]<<endl; 
cout<<"�� �� >"; 
if(Esex[i]=='F') cout<<"Ů "<<endl; 
else if(Esex[i]=='M') cout<<"�� "<<endl; 
cout<<"�� �� >"<<Eage[i]<<"��"<<endl; 
cout<<"������� >"; 
if(Emarriage[i]=='Y') cout<<"�ѻ� "<<endl; 
else if(Emarriage[i]=='N') cout<<"δ�� "<<endl; 
cout<<"ѧ �� >"; 
switch (Edegree[i]) 
{ 
case 1:cout<<"�� �� "<<endl;break; 
case 2:cout<<"�� �� "<<endl;break; 
case 3:cout<<"�� �� "<<endl;break; 
case 4:cout<<"˶ ʿ "<<endl;break; 
case 5:cout<<"�� ʿ "<<endl;break; 
} 

cout<<"���ڲ��� >"; 
switch (Edepart[i]) 
{ 
case 1:cout<<"���»� "<<endl;break; 
case 2:cout<<"�г��� "<<endl;break; 
case 3:cout<<"���ز� "<<endl;break; 
case 4:cout<<"�ͷ����� "<<endl;break; 
case 5:cout<<"��Ϣ���� "<<endl;break; 
} 

cout<<"����ְ�� >"; 
switch (Eposition[i]) 
{ 
case 1:cout<<"��ʱ��Ա "<<endl;break; 
case 2:cout<<"��ʽԱ�� "<<endl;break; 
case 3:cout<<"���� "<<endl;break; 
case 4:cout<<"���ž��� "<<endl;break; 
case 5:cout<<"���³� "<<endl;break; 
} 

cout<<"����ʱ�� >"<<Eworktime[i]<<"Сʱ"<<endl; 
cout<<"����� >"<<Epay[i]<<"Ԫ"<<endl; 
cout<<"**********************************"<<endl; 
} 
else continue; 
} 
} 



void Employee::RefreshInfo() //�޸�Ա����Ϣ�ĺ��� 
{ 
int cNum = 1000; 
DBOperate dbo; 
dbo.ReadOut(); 
void Employee::shownum(long number); 

cout<<"��������Ҫ�޸ĵ�Ա����ţ� >"; 
cin>>cNum; 
int MN; 
MN = Employee::MaxNum(); 

for(int i=0;i<MN;i++) //���������ļ�������Ҫ�޸ĵ�Ա������ 
{ 
if(Enum[i] == cNum) 
{ 
Employee::shownum(cNum); 

cout<<"�������Ա��������Ϣ: "<<endl; 

cout<<"��Ա������: "; //¼��Ա�����µ����ݣ�Ա���ű��ֲ��� 
cin>>Employee::Employeename; 
Ename[i] = Employee::Employeename; 

cout<<"��Ա���Ա�: [FΪŮ�ԣ�MΪ����]: "; 
cin>>Employee::Employeesex; 
Esex[i] = Employee::Employeesex; 

cout<<"��Ա������: "; 
cin>>Employee::Employeeage; 
Eage[i] = Employee::Employeeage; 

cout<<"��Ա������״����YΪ�ѻ飬NΪδ�飩: "; 
cin>>Employee::Employeemarriage; 
Emarriage[i] = Employee::Employeemarriage; 

cout<<"��Ա��ѧ��,��������Ӧѧ�������:"<<endl; 
cout<<" [1:���� 2:���� 3:���� 4:˶ʿ 5:��ʿ] "; 
cin>>Employee::Employeedegree; 
while(Employee::Employeedegree !=1&&Employee::Employeedegree !=2&&Employee::Employeedegree !=3&&Employee::Employeedegree !=4&&Employee::Employeedegree !=5) 
{ 
cout<<"������������������:"<<endl; 
cout<<" [ 1:ר�� 2:���� 3:˶ʿ 4:��ʿ] "; 
cin>>Employee::Employeedegree; 
} 
Edegree[i] = Employee::Employeedegree; 

cout<<"��Ա�����ڲ���,��������Ӧ���ŵ����: "<<endl; 
cout<<" [1:���»� 2:�г��� 3:���ز� 4:�ͷ����� 5:��Ϣ����] "; 
cin>>Employee::Employeedepart; 
while(Employee::Employeedepart !=1&&Employee::Employeedepart !=2&&Employee::Employeedepart !=3&&Employee::Employeedepart !=4&&Employee::Employeedepart!=5) 
{ 
cout<<"������������������:"<<endl; 
cout<<" [1:���»� 2:�г��� 3:���ز� 4:�ͷ����� 5:��Ϣ����] "; 
cin>>Employee::Employeedepart; 
} 
Edepart[i] = Employee::Employeedepart; 

cout<<"��Ա��ְλ,��������Ӧְλ�����:"<<endl; 
cout<<" [1:��ʱְԱ 2: ��ʽְԱ 3:���� 4:���ž��� 5:���³�] "; 
cin>>Employee::Employeeposition; 
while(Employee::Employeeposition !=1&&Employee::Employeeposition !=2&&Employee::Employeeposition !=3&&Employee::Employeeposition !=4&&Employee::Employeeposition !=5) 
{ 
cout<<"������������������:"<<endl; 
cout<<" [1:��ʱְԱ 2: ��ʽְԱ 3:���� 4:���ž��� 5:���³�] "; 
cin>>Employee::Employeeposition; 
} 
Eposition[i] = Employee::Employeeposition; 



cout<<"��Ա���Ĺ���ʱ (����Ҫ���뵥λ): "; 
cin>>Employee::Employeeworktime; 
Eworktime[i] = Employee::Employeeworktime; 


Epay[i] = Employee::Pay(Employee::Employeeposition); 

break; 
} 
} 


dbo.WriteIn(0); 
} 

void Employee::DeleteInfo() //ɾ��Ա�����ݵĺ��� 
{ char tmp; 
int cNum = 1000; 
DBOperate dbo; 
dbo.ReadOut(); 
void Employee::shownum(long number); 

cout<<"��������Ҫ�޸ĵ�Ա�����>�� "; 
cin>>cNum; 
int MN; 
MN = Employee::MaxNum(); 

for(int i=0;i<MN;i++) //���������ļ�������Ҫɾ����Ա�� 
{ 
if(Enum[i] == cNum) 
Employee::shownum(cNum); 
} 

cout<<"ȷ��Ҫɾ����Ա����Ϣ��(YΪȷ�� NΪ����)�� "; 
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

cout<<" ɾ�������ɹ� ! "<<endl; 
} 

} 

float Employee::Pay(int Employeeposition) //����Ա��ְλ���㹤�ʵĺ��� 
{ 
float tmpPay; 
tmpPay = Employee::EmployeeBasePay + Employee::Employeeposition * Employee::EmployeeBasePay; 
return tmpPay; 
} 


void DBOperate::WriteIn(int iflag) //���ݲ������� д�� 
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


void DBOperate::ReadOut() //���ݲ������� ���� 
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



void DBOperate::RefreshMaxNum(int iflag) //����ϵͳ��Ա�������ļ��ĺ��� 
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


int main() //������ 
{ 


int select = 0; 
while(select!=5) 
{ 

cout<<"          ��ӭ�����ϵͳ"<<endl; 
cout<<"  ��ѡ���� "<<endl; 
cout<<"                             "<<endl; 
cout<<"  1.�½�������ְ������ "<<endl; 
cout<<"  2.���������ְ������ "<<endl; 
cout<<"  3.�޸�ָ��ְ�������� "<<endl; 
cout<<"  4.ɾ������ "<<endl; 
cout<<"  5.�˳� "<<endl; 
cout<<"                            "<<endl; 
cout<<"                             "<<endl; 
cout<<" ��ѡ�������Ŀ: " ; 
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
cout<<"�������"<<endl; 
} 

if(select == 5) 
break; 
} 

exit(1); 
return 0; 
}
