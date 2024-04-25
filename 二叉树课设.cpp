#include<iostream> 
#include<malloc.h> 
#include<string.h> 
#define MAX 128 
#define MAXSTACK 128 
using namespace std; 
typedef struct tre 
{ 
char data; 
tre* left; 
tre* right; 
}*bittre,tree; 
//先序创建树 
void creat(bittre& t) 
{ 
char c; 
cin>>c; 
if(c=='*') 
{ 
t=NULL; 
} 
else 
{ 
t=(tre*)malloc(sizeof(tre)); 
t->data =c; 
creat(t->left ); 
creat(t->right ); 
} 
} 
typedef struct Stack 
{ 
int top; 
int base; 
bittre data[MAXSTACK]; 
}Stack; 
void InitStack (Stack & s) 

                                                   
{ 
 s.base =0; 
 s.top =0; 
} 
 
void Push(Stack & s , bittre t) 
{ 
 s.data [s.top ]=t; 
 s.top ++; 
} 
 
void Pop (Stack & s) 
{ 
 s.top --; 
} 
 int StackEmpty (Stack s) 
 { 
  if(s.base ==s.top ) 
  { 
   return 1; 
  } 
  else 
   return 0; 
 } 
//非递归方式前序遍历： 
void Fpre(bittre t, Stack s) 
{ 
 while (t!=NULL||StackEmpty(s)!=1) 
 { 
  if(t) 
  { 
   cout<<t->data <<" "; 
   Push(s,t); 
   t=t->left ; 
  } 
  else 
  { 
   Pop(s); 
   t=s.data [s.top ]; 
   t=t->right ; 
   
  } 
 } 

                                                   
} 
//非递归后序遍历： 
void FLast (Stack s,bittre t) 
{ 
 bittre p; 
 p=t; 
 bittre r; 
 r=NULL; 
 while(t!=NULL||StackEmpty(s)!=1) 
 { 
  if(p) 
  { 
   Push(s,p); 
   p=p->left ; 
 
  } 
  else 
  { 
   p=s.data [s.top -1];//得到栈顶； 
   if(p==NULL) 
   { 
    break; 
   } 
   if(p->right !=NULL&&p->right !=r) 
   { 
    p=p->right ; 
    Push(s,p); 
    p=p->left ; 
   } 
   else 
   { 
    Pop(s); 
    p=s.data [s.top ]; 
    cout<<p->data <<" "; 
    r=p; 
    p=NULL; 
   } 
  } 
 } 
} 
//非递归中序遍历： 
void FMid(Stack s,bittre t) 
{ 
 
                                                  
 bittre p; 
 p=t; 
 while (p!=NULL||StackEmpty(s)!=1) 
 { 
  if(p) 
  { 
   Push(s,p); 
   p=p->left ; 
  } 
  else 
  { 
   Pop(s); 
   p=s.data [s.top ]; 
   cout<<p->data<<" " ; 
   p=p->right ; 
  } 
 } 
} 
 
//队列 
typedef struct quene 
{ 
 int rear; 
 int front; 
 bittre data[MAX]; 
}quene; 
//初始化队列 
void first(quene &q) 
{ 
 q.front =0; 
 q.rear =0; 
} 
//入队 
void ru (quene & q ,bittre t) 
{ 
 q.data [q.rear ]=t; 
 q.rear ++; 
} 
//出队 
void chu (quene & q) 
{ 
 q.front ++; 
} 
 
                                  
 
//层次遍历： 
void level (quene q,bittre t) 
{ 
 if(t==NULL) 
 { 
  return ; 
 } 
 ru(q, t); 
 bittre p; 
 while (q.front !=q.rear ) 
 { 
  cout<<q.data [q.front ]->data <<" "; 
  p=q.data [q.front ]; 
  chu(q); 
  if(p->left !=NULL) 
  { 
   ru(q,p->left ); 
 
  } 
  if(p->right !=NULL) 
  { 
   ru(q,p->right ); 
  } 
 } 
} 
//获得深度： 
int levels(bittre t,quene q) 
{ 
 int leve=0; 
 if(t==NULL) 
 { 
  return 0; 
 
 } 
 bittre p; 
 int size; 
 ru(q,t); 
 while(q.front !=q.rear ) 
 { 
  leve++; 
  size=q.rear -q.front ; 
  while(size--) 
 
                                                  
  { 
   p=q.data [q.front ]; 
   chu(q); 
   if(p->left !=NULL) 
       { 
     ru(q,p->left ); 
    } 
   if(p->right !=NULL) 
   { 
    ru(q,p->right ); 
   } 
  } 
 } 
 return leve; 
} 
//储存数据： 
void stockpile(bittre &t,char * a,int i,int j,int width,int height) 
{ 
 int ti=1; 
 int tj; 
 if(t) 
 { 
  *(a+(i*width)+j)=t->data ; 
  if(t->left ) 
  { 
   for(ti=i+1,tj=j-1;tj>j-(height-i+1)/2;tj--) 
   { 
    *(a+((ti*width))+tj)=-1; 
    ti++; 
   } 
  } 
  if(t->right ) 
  { 
   for(ti=i+1,tj=j+1;tj<j+(height-i+1)/2;tj++) 
   { 
    *(a+(ti*width)+tj)=1; 
    ti++; 
   } 
  } 
   stockpile(t->left ,a,ti,j-(height-i+1)/2,width,height); 
  stockpile(t->right ,a,ti,j+(height-i+1)/2,width,height); 
 
 } 

                                                  
 
} 
//打印树形结构： 
void printtre (bittre & t,int width,int height) 
{ 
 int i=0; 
 int j=0; 
 char * a=(char* )malloc(sizeof(char)*(width*height)); 
 for(i=0;i<height;i++) 
 { 
  for(j=0;j<width;j++) 
  { 
   *(a+(i*width)+j)=0; 
  } 
 } 
 stockpile(t,a,0,(width-1)/2,width,height); 
 for(i=0;i<height;i++) 
 { 
  for(j=0;j<width;j++) 
  { 
   if(*(a+(i*width)+j)==-1) 
   { 
    cout<<"/"; 
   } 
   else 
   { 
    if(*(a+(i*width)+j)==1) 
    { 
     cout<<"\\"; 
    } 
    else 
    { 
     if(*(a+(i*width)+j)==0) 
     { 
      cout<<" "; 
     } 
     else 
     { 
      cout<<*(a+(i*width)+j); 
     } 
    } 
 
   } 

                                              
  } 
  cout<<endl; 
 
 } 
 
} 
//查找指定结点路径： 
void Find(bittre &t,char * c,int &flag,int &i,char aim) 
{ 
 if(t == NULL) 
 { 
  return; 
 } 
 if(t->data ==aim) 
 { 
  flag=1; 
  c[i] = t->data; 
  i++; 
  return; 
 } 
  
 Find(t->left ,c,flag,i,aim); 
 if(flag==1) 
 { 
  c[i]=t->data ; 
  i++; 
  return; 
 } 
 
 Find(t->right ,c,flag,i,aim); 
 if(flag==1) 
 { 
  c[i]=t->data ; 
  i++; 
  return; 
 } 
} 
//菜单： 
void menu() 
{ 
 cout << "****************************************************" << endl; 
 cout << "**************** 1.非递归先序遍历 ******************" << endl; 
 cout << "**************** 2.非递归中序遍历 ******************" << endl; 

                                                 
 cout << "**************** 3.非递归后序遍历 ******************" << endl; 
 cout << "**************** 4.层次遍历       ******************" << endl; 
 cout << "**************** 5.打印树形结构   ******************" << endl; 
 cout << "**************** 6.求指定结点路径 ******************" << endl; 
 cout << "**************** 0.退出  ***************************" << endl; 
 cout << "****************************************************" << endl; 
} 
 
 
int main() 
{ 
 bittre t; 
 creat(t); 
 quene q; 
    quene q1; 
 first (q1); 
 first(q); 
 int width; 
 int height; 
 width=(2<<(levels(t,q1)+1))-3; 
 height=(2<<(levels(t,q1)-1))-1; 
  
 Stack s; 
 InitStack(s); 
 Stack s1; 
 InitStack(s1); 
 Stack s2; 
 InitStack(s2); 
 int input=0; 
 do 
 { 
  menu(); 
  cin>>input; 
     switch (input) 
  { 
  case 1: 
   { 
    cout<<"非递归前序遍历："<<endl; 
             Fpre(t,s); 
    cout<<endl; 
    break; 
   } 
  case 2 : 

                                              
   { 
    cout<<" 非递归中序遍历："<< endl; 
                FMid(s2,t); 
    cout<<endl; 
    break; 
   } 
  case 3 : 
   { 
    cout<<"非递归后序遍历:"<<endl; 
                FLast(s1,t); 
    cout<<endl; 
    break; 
   } 
  case 4: 
   { 
    cout<<"层次遍历："<<endl; 
             level(q,t); 
             cout<<endl; 
    break; 
   } 
  case 5: 
   { 
    cout<<"树的结构："<<endl; 
             printtre(t,width,height); 
    cout<<endl; 
    break; 
 
   } 
  case 6: 
   { 
    char c[20]; 
             int flag=0; 
             int i=0; 
             char aim; 
             cout<<"输入目标结点："<<endl; 
             cin>>aim; 
             cout<<"路径为："; 
             Find(t,c,flag,i,aim); 
             c[i] = '\0'; 
             int count; 
             count=strlen(c); 
             int p; 
             for(p=count-1;p>=0;p--) 

                                             
                { 
                if(p==0) 
                   { 
                      cout<<c[p]; 
                     break; 
                     } 
                   cout<<c[p]<<"->"; 
                } 
  
   } 
  case 0 : 
   { 
   cout<<"退出"<<endl; 
   } 
 
  } 
 
 
 }while(input); 
 
 
 
 
 return 0; 
  
} 