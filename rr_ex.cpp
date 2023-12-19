#include <bits/stdc++.h>
using namespace std;
queue<int> q;
struct s
{
	int pid,at,bt,ct;
};

void sort(struct s p[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(p[j].at>p[j+1].at)
			{
				struct s t=p[j];
				p[j]=p[j+1];
				p[j+1]=t;
			}
		}	
	}
}

int main()
{
	int n,tq;
	cin>>n>>tq;
	
	struct s p[n];
	for(int i=0;i<n;i++)
	{
	p[i].pid=i;
	cin>>p[i].at>>p[i].bt;
	}
	
	sort(p,n);
	for(int i=0;i<n;i++)
	cout<<p[i].pid<<" "<<p[i].at<<" "<<p[i].bt<<endl;
	
	int x=p[0].at,prex=-1;
	q.push(p[0].pid);
	bool stop=true;
	
	
	while(!q.empty() || stop)
	{
		prex=x;
		int temp=q.front(),i;
		q.pop();
		for(int k=0;k<n;k++) if(p[k].pid==temp)  i=k;
		
		if(p[i].bt>tq)
		{
			p[i].bt-=tq;
			x=x+tq;
		}
		else
		{
			x=x+p[i].bt;
			p[i].ct=x;
			p[i].bt=0;
		}
		
		for(int j=0;j<n;j++)
		{
			if(p[j].bt!=0 && p[j].at>prex && p[j].at<=x)
			q.push(p[j].pid);
		}
		if(p[i].bt!=0) q.push(p[i].pid);
		
		stop=false;
		if(q.empty())
		{
			for(int i=0;i<n;i++)
			{
			if(p[i].bt>0) 
			{q.push(p[i].pid); prex=x; x=p[i].at; break;}
			}
		}
	}
	
	cout<<endl;
	for(int i=0;i<n;i++) cout<<p[i].pid+1<<" "<<p[i].ct<<endl;
	
			
}
