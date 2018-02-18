/*
 * Created by Jacky Wijaya
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <set>
#include <cctype>
#include <algorithm>
#include <climits>
#include <queue>
#include <functional>
#include <map>

#define FOREACH(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define FOR(a,b,c) for (int (a)=(b);(a)<(c);++(a))
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)

#define ALL(c) (c).begin(), (c).end()
#define F first
#define S second
#define INS insert
#define MP make_pair
#define PB push_back
#define LL long long
#define ULL unsigned long long

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

template <class T> inline T MAX(T a, T b) { if (a > b) return a; return b; }
template <class T> inline T MIN(T a, T b) { if (a < b) return a; return b; }
template <class T> inline T ABS(T x) { if (x < 0) return -x; return x; }

inline void OPEN(const string &s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

const static int INF = 2123123123;

#define MAXA 30

int n;
string valya;
string tolya;
int par[MAXA];

vii resSpell;

int getPar(int x) {
  if (x == par[x]) return x;
  return par[x] = getPar(par[x]);
}

int main() {
  REP(i,26) par[i] = i;

  scanf("%d",&n);
  cin >> valya >> tolya;

  int res = 0;
  REP(i, n) {
    int nodeI = valya[i] - 'a';
    int nodeJ = tolya[i] - 'a';
    int parI = getPar(nodeI);
    int parJ = getPar(nodeJ);
    if (parI != parJ) {
      int newPar = min(parI, parJ);
      par[parJ] = par[parI] = newPar;
      res++;
      resSpell.push_back(MP(nodeI, nodeJ));
    }
  }
  printf("%d\n",res);
  REP(i, res) {
    printf("%c %c\n", resSpell[i].F + 'a', resSpell[i].S + 'a');
  }
  return 0;
}