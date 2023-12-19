#include<stdio.h>

int main(){
	 int a[]={7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1};
   int n=14,i,temp=0,j,pf=0,hit=0,flag;
    int f=3;
   int frames[f];
   for(i=0;i<f;i++){
   	frames[i]=-1;
   }
   for(i=0;i<n;i++){
   	int flag=0;
   		if(frames[temp]==-1){
   			pf++;
   		
   			frames[temp]=a[i];
   			temp = (temp+1)%f;
   			continue;
		}
   	for(j=0;j<f;j++){
   	
   	 if(frames[j]==a[i]){
   			flag=1;
   			hit++;
   		
   			break;
		   }
	   }
	   if(flag==0){
	   	pf++;
	   	frames[temp]=a[i];
	   	temp = (temp+1)%f;
	   }
   }
   printf("%d\n",pf);
   printf("%d",hit);
   
    
    
}
