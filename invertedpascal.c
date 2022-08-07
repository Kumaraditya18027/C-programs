#include <stdio.h>
int main()
{
    int f[20][20], rows;
  
    printf("Enter the number of lines: ");
    scanf("%d",&rows);
    for (int i = 0; i < rows; ++i)
        f[i][i] = f[i][0] = 1;
    for (int i = 2; i != rows; ++i)
        for (int j = 1; j != i; ++j)
            f[i][j] = f[i-1][j] + f[i-1][j-1];
    
    for (int i = rows - 1; i >= 0; --i)
    {
        for (int j = 0; j < rows - i - 1; ++j)
            printf("%4c", ' ');
        for (int j = 0; j <= i; ++j)
            printf("%4d%4c", f[i][j], ' ');
        printf("\n");
    }
    return 0;
}