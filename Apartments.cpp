#include<bits/stdc++.h>
using namespace std;
 
#define fi(a,b) for(int i=a;i<b;i++)
#define fj(a,b) for(int j=a;j<b;j++)
#define ff first
#define ss second
#define ll long long
#define ld long double
#define ull unsigned long long
#define bp(x) __builtin_popcount(x)
#define pr(x) for(auto it: x) cout<<it<<" "; cout<<endl;
#define endl "\n"
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef vector<long long> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector< pair<ll,ll> > vll;
//find_by_order(k) - no. of elements strictly smaller than k
//order_of_key(k) - index of element k (starting from 0)
//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1};
//int dx[]={-1,0,1,1,1,0,-1,-1};
//int dy[]={-1,-1,-1,0,1,1,1,0};
 
void nikal_pehli_fursat_mai(){
  ll n,m,k;
  cin>>n>>m>>k;
  vl a(n); fi(0,n) cin>>a[i];
  vl b(m); fi(0,m) cin>>b[i];
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  int i=0,j=0;
  int ans=0;
  while(i<n && j<m){
    if(abs(a[i]-b[j])<=k){
      ans++;
      i++;
      j++;
    }
    else if(a[i]>b[j]){
      j++;
    }
    else{
      i++;
    }
  }
  cout<<ans<<endl;
}
 
int main(){
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc=1; 
  //cin>>tc;
  while(tc--){
    nikal_pehli_fursat_mai();
  }
}