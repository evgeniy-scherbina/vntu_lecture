//#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <ctime>

#define MAXN 500000
#define INF 1000000000
#define pi 3.1415926535
#define LL long long
#define U unsigned
#define mp make_pair
#define pb push_back
#define eps 0.000001

using namespace std;
ifstream cin("input.txt");
ofstream cout("output.txt");

int k;
vector <int> G(40+1);
int mex(vector <bool> flag)
{
	int i;
	for (i=0; i<flag.size(); i++)
	{
		if (!flag[i]) return i;
	}
	return 0;
}
int Grundy(int n)
{
	vector <bool> flag(40+1,false);
	flag[G[n-k]]=true;
	int i;
	for (i=2; i<=n-k; i++)
	{
		flag[G[i-1]^G[n-i-k+1]]=true;
	}
	return mex(flag);
}
int main()
{
	int i,n;
	string s;
	cin >> n >> k;
	cin >> s;
	for (i=0; i<k; i++)
	{
		G[i]=0;
	}
	for (i=k; i<=n; i++)
	{
		G[i]=Grundy(i);
	}
	s.pb('#');
	int u=0,ans=0,e=0;
	for (i=0; i<s.size(); i++)
	{
		if (s[i]=='O') u++;
		else
		{
			if (u>=k) e=1;
			ans=ans^G[u];
			u=0;
		}
	}
	if (e==0) cout << "0\n";
	else
	{
		if (ans==0) cout << "2\n";
		else cout << "1\n";
	}
	return 0;
}