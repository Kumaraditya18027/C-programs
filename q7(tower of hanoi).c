#include<stdio.h>
void intial(int *);
void toh(int *,int,char,char,char);


void main()
{
  int n,sn;//sn is step count//
  printf("Enter the no. of disk:");
  scanf("%d",&n);
  intial(&sn);
  toh(&sn,n,'s','a','t');
}
void intial(int *sc)
{
  *sc=0;
}
void toh(int *sc,int n,char s,char a,char t)
{
    if(n>0)
    {
        toh(sc,(n-1),s,t,a);
        printf("\n step no. is %d: Transfer Disk %d from %c to %c",++(*sc),n,s,t);
        toh(sc,(n-1),a,s,t);
    }
}