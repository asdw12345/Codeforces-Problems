#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cctype>
#include<stack>
#include<queue>
using namespace std;
#define MAXN 1000000+10
int n,m,i,j,k,a,b,c;
float r[201][201];
float g[201][201],g0[201],res[201],gtmp;
float ans;
int main()
{
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i)
    {
        scanf("%d%d%d",&a,&b,&c);
        r[a][b]+=(double)1/c;
        r[b][a]+=(double)1/c;
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(r[i][j]!=0) r[i][j]=1/r[i][j];
    for(i=2;i<=n-1;i++)
    {
        for(j=1;j<=n;j++)
            if(r[i][j]!=0)
            {
                g[i][j]+=1/r[i][j];
                g[i][i]-=1/r[i][j];
            }
    }
    for(i=2;i<=n-1;++i) g0[i]-=g[i][1]*10000;
    for(i=2;i<=n-1;++i)
    {
        for(j=i+1;j<=n;++j)
        {
            gtmp=g[j][i]/g[i][i];
            for(k=i+1;k<=n;++k) g[j][k]-=g[i][k]*gtmp;
            g0[j]-=gtmp*g0[i];
        }
    }
    for(i=n-1;i>=2;--i)
    {
        for(j=n;j>=i+1;--j)g0[i]-=g[i][j]*res[j];
        res[i]=g0[i]/g[i][i];
    }
    res[1]=10000;
    for(i=1;i<=n;++i)
        if(r[i][n]!=0) ans+=res[i]/r[i][n];
    ans=10000/ans+0.000001;
    printf("%.2f\n",ans);
}

