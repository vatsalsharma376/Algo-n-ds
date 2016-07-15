#include <stdio.h>
#include <string.h>
#include <math.h>
#define max(a,b) ((a)>(b)?(a):(b))

int map[100][100];
/**
 * O(nlogn) time for pre-processing, recurrence formula:
 * f[i,j]=max(f[i, j-1], f[i + 2^(j-1), j-1])

 */
void pre_handle(int * m , int n)
{
    memset(map, 0, sizeof(map));
    for(int i=0;i<n;i++)
        map[i][0]=m[i];
    int k = (int)(log(n) / log(2));
    /* i is the column, j is the row, every values for a column can be computed (only) from last column. */
    for(int i=1;i<=k;i++)    
        for(int j = 0; j + pow(2,i-1) < n; j++)
            map[j][i]=max(map[j][i-1], map[j+(int)pow(2, i-1)][i-1]);
}

int RMQ(int a, int b)
{
    int k = (int)(log(b-a+1)/log(2)); /* length of the query range is b-a+1 */
    /* the two ranges may be overlapped */
    return max(map[a][k], map[b+1-(int)pow(2, k)][k]);
}

int main()
{
    freopen("in", "r", stdin);
    int n;
    int m[100];
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        scanf("%d", &m[i]);
    pre_handle(m, n);
    printf("%d\n", RMQ(2, 10));
    printf("%d\n", RMQ(20, 30));
    return 0;
}
