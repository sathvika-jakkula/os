#include<stdio.h>

struct process{
	int at,bt,ct,wt,tat,c;
};

int getprocess(struct process p[],int n,int ct){
	int ans=-1,i;
	int minn=99999,z=99999;
	for(i=0;i<n;i++){
		if(p[i].at<=ct && p[i].c!=1){
			if(p[i].bt<minn){
				minn = p[i].bt;
				ans=i;
			}
		}
	}
	return ans;
}

int main(){
	int n,i,k=0,index=0,ans=0,ct=0;
	scanf("%d",&n);
	struct process p[n];
	for(i=0;i<n;i++){
		scanf("%d%d",&p[i].at,&p[i].bt);
		p[i].c=-1;
	}

	while(k<n){
		index = getprocess(p,n,ct);
		if(index!=-1){
			printf("p%d| ",index+1);
			p[index].ct = ct+p[index].bt;
			ct = p[index].ct;
			p[index].tat = p[index].ct - p[index].at;
			p[index].wt=p[index].tat-p[index].bt;
			p[index].c=1;
			k++;
		}else{
			ct++;
		}
	
	}
	
	for( i=0;i<n;i++){
			printf("%d %d %d %d %d %d\n",p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
	}
	
	
	
}
