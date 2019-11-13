#include<stdio.h>
#include<stdlib.h>
int max(int n, int a[]){int b,max,i;max=a[0];for ( i = 0; i < n-1; i++){if(a[i]>max)max=a[i];}return max;}
 int main(){
 	int i=0,n,j,q1=0,q2=0;
 	int *a,*b,*c;
	 scanf("%d",&n);
	 b=(int *)malloc(sizeof(int)*n);
	 c=(int *)malloc(sizeof(int)*n);
	 for(j=0;j<n;j++){
	 	scanf("%d",&b[j]);
	 }i=max(n,b);
	 a=(int *)malloc(sizeof(int)*(i+1));
	 for(q1=0;q1<=i;q1++){
		a[q1]=q1;
	 }q1=0;
	 for(q1=0;q1<=i;q1++){
	 for(j=0;j<n;j++){
	 	if(b[j]!=a[q1]){}else{
		 c[q2]=b[j];
		q2+=1;
}}j=0;}
	for(j=0;j<n;j++){
		printf("%d",c[j]);
		if(j<n-1)printf(",");}
	if(b)free(b);
	if(c)free(c); 
	 return 0;}
