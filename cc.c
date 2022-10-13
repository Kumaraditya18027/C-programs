#include <stdio.h>

int main ()
{
  int n, a, b, c, i;
  scanf ("%d", &n);
  for (i = 0; i < n; i++)
    {
      scanf ("%d %d %d",&a,&b,&c);
      if (b >= a && b >= c)
          	printf ("Yes");
      else
	    printf ("No");
    }
  return 0;
}
