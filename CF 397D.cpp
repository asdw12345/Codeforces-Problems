///���⣺��n��case��ÿ��case��һ��int���͵���a��2<=a<=10^9
///          ���費����a������Ϊv[a]������a����С����Ϊu[a]
///          ��sigma(1/(v[i]*u[i])),����2<=i<=a������ʽ��Ϊx/y����ʽ���
///          http://codeforces.com/problemset/problem/397/D
///˼·�����Ա����ҳ�v[a]��u[a]����һ���棬����Ҫ���ֵΪsum�����Ҵ�2~a������Ϊprime[i]��
///          ��ô����֪��sum=sigma����prime[ i+1 ]-prime[ i ]��/��prime[ i+1 ]*prime[ i ]������
///          �����Ϳ���ͨ�����������������ͬʱע�⻹Ҫ����һ�����һ��ʱ����������Ĺ�ʽΪ
///          sum=1 / 2 - 1 / v[ a ] +��a - v[ a ] + 1��/��v[ a ] * u [ a ]��

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
