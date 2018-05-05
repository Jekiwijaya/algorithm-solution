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

int t;
int d;
string c;

int getCountShoot(string s) {
  int ret = 0;
  REP(i, s.size()) {
    ret += s[i] == 'S';
  }
  return ret;
}

int getTotalShoot(string s) {
  int ret = 0;
  int currentDamage = 1;
  REP(i, s.size()) {
    if (s[i] == 'S') {
      ret += currentDamage;
    } else {
      currentDamage *= 2;
    }
  }
  // printf("%s : %d\n",s.c_str(), ret);
  return ret;
}

string shift(string s) {
  string c = s;
  int idx = -1;
  for(int i = s.size()-1; i >= 1; i--) {
    if (s[i] == 'S' && s[i-1] == 'C') {
      idx = i;
      break;
    }
  }
  swap(c[idx], c[idx-1]);
  return c;
}

int solve(int d, string s) {
  string c = s;
  int ret = 0;
  int currentDamage = getTotalShoot(s);
  if (currentDamage <= d) return 0;
  do {
    ret++;
    c = shift(c);
  }while(getTotalShoot(c) > d);
  return ret;
}

int main() {
  cin >> t;
  REPN(i, t) {
    cin >> d >> c;
    int totalShoot = getCountShoot(c);
    if (totalShoot > d) printf("Case #%d: IMPOSSIBLE\n", i);
    else printf("Case #%d: %d\n", i, solve(d, c));
  }
  return 0;
}