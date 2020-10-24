#include<bits/stdc++.h>
using namespace std;

#define   fi(a,b) for(int i=a;i<b;i++)
#define   fj(a,b) for(int j=a;j<b;j++)
#define   ff first
#define   ss second
#define   ll long long
#define   ld long double
#define   ull unsigned long long
#define   bp(x) __builtin_popcount(x)
#define   pr(x) for(auto it: x) cout<<it<<" "; cout<<endl;
#define   getMax(x) max_element(x.begin(),x.end())
#define   getMin(x) min_element(x.begin(),x.end())
#define   endl "\n"
typedef   vector<int> vi;
typedef   vector< pair<int,int> > vii;
typedef   vector<long long> vl;
typedef   pair<int,int> pii;
typedef   pair<ll,ll> pll;
typedef   vector< pair<ll,ll> > vll;
//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1};
//int dx[]={-1,0,1,1,1,0,-1,-1};
//int dy[]={-1,-1,-1,0,1,1,1,0};

/***************************Minimum Range Queries******************************/
const int N=3e5+10;;
const int M=log(N)+10;
ll st[N][M];
int cal_log[N];

void precompute(vl array,int n){
  cal_log[1] = 0;
  for (int i = 2; i <= N; i++)
      cal_log[i]=cal_log[i/2]+1;

  int K=log2(n);
  for (int i = 0; i < n; i++)
    st[i][0] = array[i];

  for (int j = 1; j <= K; j++)
    for (int i = 0; i + (1 << j) <= N; i++)
        st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
}

ll get(int n,int L,int R){
  int j = cal_log[R - L + 1];
  return min(st[L][j], st[R - (1 << j) + 1][j]);
}

void nikal_pehli_fursat_mai(){
    int n, a, b;
    cin>>n>>a>>b;

    vl v(n+1, 0);
    fi(1, n+1) {
        cin>>v[i];
        v[i] += v[i-1];
    }


    precompute(v,v.size());

    ll ans = v[a];

    for(int i=a; i<=n; i++){
        int R = max(i-a, 0);
        int L = max(i-b, 0);

        ans = max(ans, v[i] - get(v.size(), L, R));
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
    // cin>>tc;
    while(tc--){
    nikal_pehli_fursat_mai();
    }
}
