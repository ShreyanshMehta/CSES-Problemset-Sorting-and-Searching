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

void nikal_pehli_fursat_mai(){
    ll n, k;
    cin>>n>>k;
    
    vector<pii> p(n);
    map<int, int>id;

    multiset<int>st;

    fi(1, k+1) st.insert(0);

    fi(0, n) {
        int a, b;
        cin>>a>>b;
        p[i] = {b, a};
    }

    sort(p.begin(), p.end());

    int ans = 0;
    
    fi(0, n){
        auto it = st.upper_bound(p[i].ss);
        if(it==st.begin()) continue;

        it = prev(it);
        ans++;
        st.erase(it);
        st.insert(p[i].ff);
        // pr(st);
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
