#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define size 100
typedef struct BTNode{
    char data;
    struct BTNode *lchild;
    struct BTNode *rchild;
}BTNode,*BiTree;

void Create_BT(BiTree *,char pre[],char ino[],int,int,int);//ͨ�����������������н���������
void Global_CreateBiTree(BiTree *T,char a[]);//�������ʽ���뽨��������
int search(char ino[],char pre);
void CengCi(BiTree T);//��α���������
void BianLi_2(BiTree T);//����(����,����)�ݹ����
void Non_BianLi_2(BiTree T);//����ǵݹ����
void Non_BianLi_3(BiTree T);//����ǵݹ����
void Print_Global(BiTree T);//�Թ�������ʽ����������

int main()
{   
	BiTree T=NULL;
    char pre[size],ino[size];
    int len,i,c,c1,c2;
	for(;;)
    {
		printf("\t\t\t��������ز���\n\n");
        printf("\t\t   1.�������ݽ���������.    \n\n");
        printf("\t\t   2.����������.          \n\n");
        printf("\t\t   3.�˳�����.            \n\n");
        printf("\n��ѡ��: ");
	    scanf("%d",&c);
		switch(c){
		case 1:
			T=NULL;
			cout<<"�����������뽨��/�������ʽ���뽨�� : 0/1.\n��ѡ��: ";
			cin>>c1;
			switch(c1){
			case 0:
				cout<<"��������������: ";cin>>pre;
				cout<<"��������������: ";cin>>ino;
                len=strlen(pre);
				Create_BT(&T,pre,ino,0,0,len);
				cout<<"�����ɹ�!\n";
				break;
            case 1:
				char a[size];
                cout<<"��������(�Թ������ʽ,����:A(B(D,E(G,H)),C(F(,I))): ";cin>>a;
                Global_CreateBiTree(&T,a);
				cout<<"�����ɹ�!\n";
				break;
            default: 
				cout<<"Erro!";
				break;
			}//switch
			break;
			case 2: 
				if(!T){cout<<"������!";break;}
                cout<<"\t1.�ݹ�����.\n";
                cout<<"\t2.�ǵݹ�����.\n";
				cout<<"\t3.�ǵݹ����.\n";
                cout<<"\t4.��α���.\n";
                cout<<"\t5.�������ʽ����.\n";
				cout<<"��ѡ��: ";
				cin>>c2;
				switch(c2){
				case 1:BianLi_2(T);break;
                case 2:Non_BianLi_2(T);break;
                case 3:Non_BianLi_3(T);break;
                case 4:CengCi(T);break;
                case 5:Print_Global(T);break;
                default:cout<<"Erro!";break;
				}
				break;
				case 3:return;
				default:
					cout<<"Erro!";break;
		}
	}


}

void Create_BT(BiTree *T,char pre[],char ino[],int ps,int is,int n)   //�ݹ��㷨���콨����������ĺ���
{ 
    int k;
    if(n==0) *T=NULL;
    else {
		k=search(ino,pre[ps]);
        if(k==-1) cout<<"Erro!\n";
        else {
			*T=(BiTree)malloc(sizeof(BTNode));
            (*T)->data=pre[ps];
            if(k==is) (*T)->lchild=NULL;
            else Create_BT(&(*T)->lchild,pre,ino,ps+1,is,k-is);
            if(k==is+n-1) (*T)->rchild=NULL;
            else Create_BT(&(*T)->rchild,pre,ino,ps+1+(k-is),k+1,n-(k-is)-1);
		} 
	} 
} 
int search(char ino[],char pre)  //�����������в��������и�Ԫ������λ��
{ 
    int i=0;
    while(ino[i]!=pre&&ino[i]) i++;
	if(ino[i]==pre) return i;
	else  return -1;
}
void Global_CreateBiTree(BiTree *T,char a[])
{
	const int MaxSize=100;//ջ���鳤��>=����������ȼ�һ
    BiTree s[MaxSize];
    int top=-1;
    *T=NULL;
    BiTree p;//����pΪָ�����������ָ��
    int f;//��f��Ϊ�������������������ı��,f=1����������,f=2����������
    int i=0;
    while(a[i]){
		switch(a[i]){
		case ' ':break;//�Կո����κδ���
		case '(':if(top==MaxSize-1){
			cout<<"ջ��!\n";exit(1);
				 }
			top++;s[top]=p;f=1;break;
        case ')':if(top==-1) {
			cout<<"�������Ĺ�����ַ�����!\n";exit(1);
				 }
			top--;break;
		case ',':f=2;break;
		default:p=new BTNode;
               p->data=a[i];p->lchild=p->rchild=NULL;
               if(*T==NULL) *T=p;
               else {
                   if(f==1) s[top]->lchild=p;
                   else     s[top]->rchild=p;
               }
      }
       i++;
  }
}
 //�������򡢺����������
void CengCi(BiTree T)
{
    BiTree q[size];
    int front=0,rear=0;
    if(T==NULL) return ;
    q[++rear]=T;
    while(rear!=front){
        front++;
        printf("%c  ",q[front]->data);
        if(q[front]->lchild!=NULL) {
             rear++;
             q[rear]=q[front]->lchild;
        }
        if(q[front]->rchild!=NULL) {
             rear++;
             q[rear]=q[front]->rchild;
        }
    }
}
void BianLi_2(BiTree T)
 {
	if(T)
	{ 
		BianLi_2(T->lchild);
		cout<<T->data<<"  ";
		BianLi_2(T->rchild);
   
   }
}
void Non_BianLi_2(BiTree T)
 {
	BiTree s[size],p;
    int top=0;
    p=T;
    while(p||top>0){
		while(p){
     //����ʱcout<<p->data;
			top++;
            s[top]=p;
            p=p->lchild;
		}
		if(top>0){
			p=s[top];
            --top;
            cout<<p->data<<"  ";//����
            p=p->rchild;
		}
	}
}
void Non_BianLi_3(BiTree T)
{
   int top=-1;
   BiTree p=T,s[size];
   while(p||top!=-1){//p�ǿ����ջ,��������������,Ϊ������������
	   while(p){
		   s[++top]=p;
		   if(p->lchild)  p=p->lchild;
		   else p=p->rchild;
	   }
	   p=s[top--];//��ջ�õ��Ľ�������Ҷ��,Ҳ���������������ĵ���֧���
       cout<<p->data<<"  ";
       while(top!=-1&&s[top]->rchild==p)
	   {
            p=s[top--];
            cout<<p->data<<"  ";
	   }
	   if(top!=-1)
		   p=s[top]->rchild;
	   else  p=NULL;
   }
}
void Print_Global(BiTree T)
{
	if(T==NULL) return ;
    cout<<T->data;//���������ֵ
    if(T->lchild!=NULL||T->rchild!=NULL)
	{
		cout<<'(';
        Print_Global(T->lchild);//���������
        if(T->rchild!=NULL)
			cout<<',';
		Print_Global(T->rchild);//���������
        cout<<')';
    }
}

  
