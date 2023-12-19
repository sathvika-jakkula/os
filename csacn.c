#include<stdio.h>

int findminntohead(int a[],int n,int head){
	int diff=99999,i;
	int ans;
	for(i=0;i<n;i++){
		if(head-a[i]>0 && head-a[i]<diff){
			ans=a[i];
			diff = head-a[i];
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

int findmaxx(int a[],int n){
	int ans=0,i;
	for(i=0;i<n;i++){
		if(ans<a[i]){
			ans=a[i];
		}
	}
	return ans;
}


int main(){
	int a[7] = {82,170,43,140,24,16,190};
	int n=7,i;
	int sum=0;
	int head = 50;
	int range=199;
	int z = findminntohead(a,n,head);
printf("%d",z);
	printf("%d",range-head + range +z);
	
}
