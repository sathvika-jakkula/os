#include<stdio.h>

int main(){
	int a[] = {176,79,34,60,92,11,41,114};
	int n=8,i;
	int sum=0;
	int head = 50;
	int range=199;
	for(i=0;i<8;i++){
		if(head-a[i]>0){
			sum=sum+(head-a[i]);
			head=a[i];
		}else{
			sum=sum+(a[i]-head);
			head=a[i];
		}
	}
	printf("%d",sum);
}
