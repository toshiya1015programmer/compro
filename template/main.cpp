#include<atcoder/all>
#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define bit(x) (1ll<<(x))
#define clz(x) __builtin_clz(x)
#define pcnt(x) __builtin_popcountll(x)
#define rep(i,n) for(int i=0;i<int(n);i++)
#define repc(i,n) for(int i=0;i<=int(n);i++)
#define reps(i,n) for(int i=1;i<=int(n);i++)
#define rrep(i,n) for(int i=int(n)-1;i>=0;i--)
#define rrepc(i,n) for(int i=int(n);i>=0;i--)
#define rreps(i,n) for(int i=int(n);i>=1;i--)
#define sz(x) int((x).size())
using namespace atcoder;
using namespace std;
using i64=long long;
using f80=long double;
using pii=pair<int,int>;
using vi32=vector<int>;
using vi64=vector<i64>;
using vf80=vector<f80>;
using vstr=vector<string>;
template<class T>struct pqasc:priority_queue<T,vector<T>,greater<T>>{};
template<class T>struct pqdesc:priority_queue<T,vector<T>,less<T>>{};
template<class T>bool amax(T&a,const T&b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool amin(T&a,const T&b){if(a>b){a=b;return 1;}return 0;}
template<class T,class S>ostream&operator<<(ostream &o,const pair<T,S>&p){o<<p.first<<","<<p.second;return o;}
template<class T>istream&operator>>(istream&i,vector<T>&v){for(auto&x:v)i>>x;return i;}
template<class T>ostream&operator<<(ostream &o,const vector<T>&v){rep(i,sz(v)){if(i)o<<" ";o<<v[i];}return o;}
void solve();int main(){ios::sync_with_stdio(0);cin.tie(0);cout<<fixed<<setprecision(16);solve();return 0;}
const int INF=1001001001;
const i64 LINF=1001001001001001001ll;
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};

void solve() {
  $0
}
