#include<stdio.h>
#include<math.h>

int a[30],count=0;
int place(int pos) {
	int i;
	for (i=1;i<pos;i++) {
		if((a[i]==a[pos])||((abs(a[i]-a[pos])==abs(i-pos))))
		   return 0;
	}
	return 1;
}
void print_sol(int n) {
	int i,j;
	count++;
	printf("\nSolution #%d:\n",count);
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++) {
			if(a[i]==j)
			    printf(" %d",j); 
		}
	}
}
void queen(int n) {
	int k=1;
	a[k]=0;
	while(k!=0) {
		a[k]=a[k]+1;
		while((a[k]<=n)&&!place(k)){ 
        a[k]++;
    }
		if(a[k]<=n) {
			if(k==n){
        print_sol(n);
      }
			else {
				k++;
				a[k]=0;
			}
		} 
    else{
      k--;
    } 
	}
}
int main() {
	int i,n;
	printf("\nEnter the number of Queens : ");
	scanf("%d",&n);
	queen(n);
	printf("\n\nTotal solutions = %d",count);
	return 0;
}