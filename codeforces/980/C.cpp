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

#define MAXN 100005
#define MAXC 260

int n, k;
int arr[MAXN];
int res[MAXN];

int group[MAXC];

int main() {
  scanf("%d%d", &n, &k);
  REP(i,n) scanf("%d",&arr[i]);
  memset(group, -1, sizeof(group));
  REP(i, n){
    int x = arr[i];
    if (group[x] == -1) {
      for(int j = x; j >= 0 && j >= x - k + 1; j--) {
        if (group[j] != -1) {
          if (x-k < 0) group[x] = group[j];
          else if (group[x-k] != group[j]) {
            group[x] = group[j];
            break;
          }
          break;
        } else group[x] = j;
      }
      res[i] = group[x];
      for(int j = group[x]; j < x; j++) group[j] = group[x];
    } else res[i] = group[x];
  }
  REP(i,n){
    if(i) printf(" ");
    printf("%d",res[i]);
  }
  printf("\n");
  return 0;
}

/*
16 14
0 83 160 230 48 163 47 162 43 143 155 157 235 185 215 3
*/