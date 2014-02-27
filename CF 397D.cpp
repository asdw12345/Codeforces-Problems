///题意：给n个case，每个case给一个int类型的数a，2<=a<=10^9
///          假设不超过a的素数为v[a]，大于a的最小素数为u[a]
///          求sigma(1/(v[i]*u[i])),其中2<=i<=a，并格式化为x/y的形式输出
///          http://codeforces.com/problemset/problem/397/D
///思路：可以暴力找出v[a]和u[a]。另一方面，假设要求的值为sum，并且从2~a的素数为prime[i]，
///          那么可以知道sum=sigma【（prime[ i+1 ]-prime[ i ]）/（prime[ i+1 ]*prime[ i ]）】，
///          这样就可以通过裂项相消来解决。同时注意还要处理一下最后一项时的情况，最后的公式为
///          sum=1 / 2 - 1 / v[ a ] +（a - v[ a ] + 1）/（v[ a ] * u [ a ]）
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cctype>
#include<map>
using namespace std;
typedef long long LL;
//#define MAXN 1000000000+100
//map <LL,LL> mp;

int isprime(LL x)
{
      LL i,j;
      for(i=2; i*i<=x; i++)
      {
            if(x%i==0) return 0;
      }
      return 1;
}
LL max_prime(LL aa)
{
      LL i,j;
      for(i=aa+1;; i++)
      {
            if(isprime(i)) break;
      }
      return i;
}
LL min_prime(LL bb)
{
      LL i,j;
      for(i=bb;; i--)
      {
            if(isprime(i)) break;
      }
      return i;
}
LL GCD(LL a,LL b)
{
      if(a==0||b==0) return 1;
      else
      {
            while(a%b)
            {
                  return GCD(b,a%b);
            }
            return b;
      }
}
int main()
{
      int n;
//    isprime();
      while(cin>>n)
      {
            while(n--)
            {
                  LL a;
                  cin>>a;
                  LL minprime=min_prime(a);
                  LL maxprime=max_prime(a);
//            cout<<a<<" "<<minprime<<" "<<maxprime<<endl;
                  LL fenzi=minprime*maxprime-2*maxprime+2*(a-minprime+1);
                  LL fenmu=2*minprime*maxprime;
                  LL gcd=GCD(fenzi,fenmu);
                  cout<<fenzi/gcd<<"/"<<fenmu/gcd<<endl;
            }
      }
      return 0;
}

