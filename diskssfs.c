#include<stdio.h>

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
	int a[8] = {176,79,34,60,92,11,41,114};
	int n=8,i;
	int sum=0;
	int head = 50;
	int range=199;
	int minn = findminn(a,n);
	int maxx = findmaxx(a,n);
	
	printf("%d",head-minn+maxx-minn);
}
