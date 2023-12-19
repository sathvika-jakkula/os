#import<stdio.h>

int main(){
	
	int p,m,i,j;
	int process[10],memory[10],flag[10],allocate[10],sum=0,summ=0;
	printf("enter the p");
	scanf("%d",&p);
	printf("enter the m");
	scanf("%d",&m);
	for(i=1;i<=p;i++){
		scanf("%d",&process[i]);
		allocate[i]=-1;
	
	}
	for(i=1;i<=m;i++){
		scanf("%d",&memory[i]);
			flag[i]=0;
	}
	
	for(i=1;i<=p;i++){
		for(j=1;j<=m;j++){
			if(flag[j]!=1 && process[i]<=memory[j]){
				flag[j]=1;
				allocate[i]=j;
				memory[j]=memory[j]-process[i];
				sum+=memory[j];
				break;
			}
		}
	}
	for(i=1;i<=m;i++){
		if(flag[i]==0){
			summ+=memory[i];
		}
	}
	printf("process   memory");
	for(i=1;i<=p;i++){
		printf("%d,%d\n",i,allocate[i]);
	}
	printf("%d",summ);
	
}
