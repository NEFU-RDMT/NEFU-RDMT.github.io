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

void Create_BT(BiTree *,char pre[],char ino[],int,int,int);//通过输入先序中序序列建立二叉树
void Global_CreateBiTree(BiTree *T,char a[]);//广义表形式输入建立二叉树
int search(char ino[],char pre);
void CengCi(BiTree T);//层次遍历二叉树
void BianLi_2(BiTree T);//中序(先序,后序)递归遍历
void Non_BianLi_2(BiTree T);//中序非递归遍历
void Non_BianLi_3(BiTree T);//后序非递归遍历
void Print_Global(BiTree T);//以广义表的形式遍历二叉树

int main()
{   
	BiTree T=NULL;
    char pre[size],ino[size];
    int len,i,c,c1,c2;
	for(;;)
    {
		printf("\t\t\t二叉树相关操作\n\n");
        printf("\t\t   1.输入数据建立二叉树.    \n\n");
        printf("\t\t   2.遍历二叉树.          \n\n");
        printf("\t\t   3.退出程序.            \n\n");
        printf("\n请选择: ");
	    scanf("%d",&c);
		switch(c){
		case 1:
			T=NULL;
			cout<<"先序中序输入建立/广义表形式输入建立 : 0/1.\n请选择: ";
			cin>>c1;
			switch(c1){
			case 0:
				cout<<"请输入先序序列: ";cin>>pre;
				cout<<"请输入中序序列: ";cin>>ino;
                len=strlen(pre);
				Create_BT(&T,pre,ino,0,0,len);
				cout<<"建立成功!\n";
				break;
            case 1:
				char a[size];
                cout<<"输入数据(以广义表形式,例如:A(B(D,E(G,H)),C(F(,I))): ";cin>>a;
                Global_CreateBiTree(&T,a);
				cout<<"建立成功!\n";
				break;
            default: 
				cout<<"Erro!";
				break;
			}//switch
			break;
			case 2: 
				if(!T){cout<<"无数据!";break;}
                cout<<"\t1.递归中序.\n";
                cout<<"\t2.非递归中序.\n";
				cout<<"\t3.非递归后序.\n";
                cout<<"\t4.层次遍历.\n";
                cout<<"\t5.广义表形式遍历.\n";
				cout<<"请选择: ";
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

void Create_BT(BiTree *T,char pre[],char ino[],int ps,int is,int n)   //递归算法构造建立二叉链表的函数
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
int search(char ino[],char pre)  //在中序序列中查找先序中该元素所在位置
{ 
    int i=0;
    while(ino[i]!=pre&&ino[i]) i++;
	if(ino[i]==pre) return i;
	else  return -1;
}
void Global_CreateBiTree(BiTree *T,char a[])
{
	const int MaxSize=100;//栈数组长度>=二叉树的深度减一
    BiTree s[MaxSize];
    int top=-1;
    *T=NULL;
    BiTree p;//定义p为指向二叉树结点的指针
    int f;//用f作为处理左子树或右子树的标记,f=1处理左子树,f=2处理右子树
    int i=0;
    while(a[i]){
		switch(a[i]){
		case ' ':break;//对空格不做任何处理
		case '(':if(top==MaxSize-1){
			cout<<"栈满!\n";exit(1);
				 }
			top++;s[top]=p;f=1;break;
        case ')':if(top==-1) {
			cout<<"二叉树的广义表字符串错!\n";exit(1);
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
 //先序、中序、后序遍历函数
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
     //先序时cout<<p->data;
			top++;
            s[top]=p;
            p=p->lchild;
		}
		if(top>0){
			p=s[top];
            --top;
            cout<<p->data<<"  ";//中序
            p=p->rchild;
		}
	}
}
void Non_BianLi_3(BiTree T)
{
   int top=-1;
   BiTree p=T,s[size];
   while(p||top!=-1){//p非空则进栈,并向左子树深入,为空则向右子树
	   while(p){
		   s[++top]=p;
		   if(p->lchild)  p=p->lchild;
		   else p=p->rchild;
	   }
	   p=s[top--];//退栈得到的结点可能是叶子,也可能是无右子树的单分支结点
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
    cout<<T->data;//输出根结点的值
    if(T->lchild!=NULL||T->rchild!=NULL)
	{
		cout<<'(';
        Print_Global(T->lchild);//输出左子树
        if(T->rchild!=NULL)
			cout<<',';
		Print_Global(T->rchild);//输出右子树
        cout<<')';
    }
}

  
