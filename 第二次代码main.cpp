#include <iostream>
#include<cstring>
#include<algorithm> 
using namespace std;

const int N=1e5,INF=0x3f3f3f3f;
int res=-INF,at=1,ed=1,temp=1;
int a[N];
int f[N];
int n;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		f[i]=max(f[i-1]+a[i],a[i]);
		if(f[i-1]<0)temp=i;
		if(res<f[i])res=f[i],at=temp,ed=i;
		 
	}
	cout<<res<<endl;
	return 0;
}
