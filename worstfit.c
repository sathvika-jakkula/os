#import<stdio.h>

int main(){
	int p,m,i,j,temp,z;
	int process[10],flag[10],memory[10],allocate[10];
	printf("enter p");
	scanf("%d",&p);
	for(i=1;i<=p;i++){
		scanf("%d",&process[i]);
		allocate[i]=-1;
	}
	printf("enter m");
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		scanf("%d",&memory[i]);
		flag[i]=0;
	}

	
	for(i=1;i<=p;i++){
		z=-1;
		for(j=1;j<=m;j++){
			if( process[i]<=memory[j]){
				if(z==-1){
					z=j;
				}else if(memory[z]<memory[j]){
					z=j;
				}
			}
		}
		if(z!=-1){
			allocate[i]=z;
			memory[z]=memory[z]-process[i];
		}
	}
	for(i=1;i<=p;i++){
		printf("%d,%d,%d\n",i,process[i],allocate[i]);
	}
}
