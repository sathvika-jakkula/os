#include<stdio.h>

struct process {
	int at,bt,tbt,ct,tat,wt,c;
};

int getpos(struct process p[],int n,int ct){
	int max = 99999;
	int i,ans;
	for(i=0;i<n;i++){
		if(p[i].at<=ct && p[i].bt!=0){
			if(p[i].bt<max){
				max=p[i].bt;
				ans=i;
			}
			if(p[i].bt==max){
				if(p[i].at<p[ans].at){
					max = p[i].bt;
					ans=i;
				}
			}
		}
	}
	return ans;
}

int main(){
	struct process p[10];
	int n,i,ans,ct=0,k=0,index,sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&p[i].at,&p[i].bt);
		p[i].c = 0;
		p[i].tbt = p[i].bt;
		sum+=p[i].bt;
	}

	
	while(k<sum){
		index = getpos(p,n,ct);
		if(index!=-1){
			p[index].ct = ct+1;
			p[index].bt = p[index].bt-1;
			ct=p[index].ct;
			
			k++;
		}else{
			ct++;
		}
	}
	
	for( i=0;i<n;i++){
		printf("%d %d %d\n",p[i].at,p[i].tbt,p[i].ct);
	}
	
	
	
}
