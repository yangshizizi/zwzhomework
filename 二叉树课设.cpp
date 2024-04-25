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
//���򴴽��� 
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
//�ǵݹ鷽ʽǰ������� 
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
//�ǵݹ��������� 
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
   p=s.data [s.top -1];//�õ�ջ���� 
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
//�ǵݹ���������� 
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
 
//���� 
typedef struct quene 
{ 
 int rear; 
 int front; 
 bittre data[MAX]; 
}quene; 
//��ʼ������ 
void first(quene &q) 
{ 
 q.front =0; 
 q.rear =0; 
} 
//��� 
void ru (quene & q ,bittre t) 
{ 
 q.data [q.rear ]=t; 
 q.rear ++; 
} 
//���� 
void chu (quene & q) 
{ 
 q.front ++; 
} 
 
                                  
 
//��α����� 
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
//�����ȣ� 
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
//�������ݣ� 
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
//��ӡ���νṹ�� 
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
//����ָ�����·���� 
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
//�˵��� 
void menu() 
{ 
 cout << "****************************************************" << endl; 
 cout << "**************** 1.�ǵݹ�������� ******************" << endl; 
 cout << "**************** 2.�ǵݹ�������� ******************" << endl; 

                                                 
 cout << "**************** 3.�ǵݹ������� ******************" << endl; 
 cout << "**************** 4.��α���       ******************" << endl; 
 cout << "**************** 5.��ӡ���νṹ   ******************" << endl; 
 cout << "**************** 6.��ָ�����·�� ******************" << endl; 
 cout << "**************** 0.�˳�  ***************************" << endl; 
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
    cout<<"�ǵݹ�ǰ�������"<<endl; 
             Fpre(t,s); 
    cout<<endl; 
    break; 
   } 
  case 2 : 

                                              
   { 
    cout<<" �ǵݹ����������"<< endl; 
                FMid(s2,t); 
    cout<<endl; 
    break; 
   } 
  case 3 : 
   { 
    cout<<"�ǵݹ�������:"<<endl; 
                FLast(s1,t); 
    cout<<endl; 
    break; 
   } 
  case 4: 
   { 
    cout<<"��α�����"<<endl; 
             level(q,t); 
             cout<<endl; 
    break; 
   } 
  case 5: 
   { 
    cout<<"���Ľṹ��"<<endl; 
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
             cout<<"����Ŀ���㣺"<<endl; 
             cin>>aim; 
             cout<<"·��Ϊ��"; 
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
   cout<<"�˳�"<<endl; 
   } 
 
  } 
 
 
 }while(input); 
 
 
 
 
 return 0; 
  
} 