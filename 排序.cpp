#include<stdio.h>
#include<stdlib.h>
 int main(){
 	int i=0,n,j,q1=0,q2=0;
 	int a[99999]={0};
 	int *b,*c;
 	for(i=0;a[i]<99999;i++){
 		a[i]=i;
	 }
	 scanf("%d",&n);
	 b=(int *)malloc(sizeof(int)*n);
	 c=(int *)malloc(sizeof(int)*n);
	 for(j=0;j<n;j++){
	 	scanf("%d",&b[j]);
	 }
	 for(q1=0;q1<99999;q1++){
	 for(j=0;j<n;j++){
	 	
	 	if(b[j]!=a[q1]){
	 		
		 }else{
		 
		 c[q2]=b[j];
		q2+=1;
}}
	j=0;}
	for(j=0;j<n;j++){
		printf("%d",c[j]);
		if(j<n-1)printf(",");
	}
	if(b)free(b);
	if(c)free(c); 
	 return 0;
 }
