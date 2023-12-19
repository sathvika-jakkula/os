#include<stdio.h>

int findminntohead(int a[],int n,int head){
	int diff=99999,i;
	int ans;
	for(i=0;i<n;i++){
		if(head-diff>0 && head-a[i]<diff){
			ans=a[i];
	}
	}
	return ans;
}

int findminn(int a[],int n){
	int ans=999999,i;
	for(i=0;i<n;i++){
		if(ans>a[i]){
			ans=a[i];
	}
	}
	return ans;
}


int main(){
	int a[8] = {176,79,34,60,92,11,41,114};
	int n=8,i;
	int sum=0;
	int head = 50;
	int range=199;
	int z = findminntohead(a,n,head);
	printf("%d",range-head+range-findminn(a,n));
	
}
