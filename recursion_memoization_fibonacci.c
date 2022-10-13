#include<stdio.h>
int f[10];//time complexity is order of n for this method as n no. of calls occur//
int fibo(int n)
{
   
   if(n<=1)
   {
      f[n]=n;
      return n;
   }
   else
   {
      if(f[n-2]==-1)
      f[n-2]=fibo(n-2);
      if(f[n-1]==-1)
      f[n-1]==fibo(n-1);
      return fibo(n-2)+fibo(n-1);
   }
}


void main()
{
   int n;
   scanf("%d",&n);
   int i=0;
   for(int i=0;i<10;i++)
   {
      f[i]=-1;
   }
   printf("%d",fibo(n));
}