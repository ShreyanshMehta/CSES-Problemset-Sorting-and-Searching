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
    ll n, x;
    cin>>n>>x;

    vl v(n);

    ll sum = 0;
    fi(0, n) {
        cin>>v[i];
        sum += v[i];
    }

    ll low = *getMax(v), high = sum;

    fi(0, 64){
        ll mid = (low + high)/2;
        ll cnt = 0;
        sum = 0;
        fj(0, n){
            sum += v[j];
            if(sum>mid){
                cnt++;
                sum = v[j];
            }
        }
        if(cnt+1<=x)
            high = mid;
        else
            low = mid+1;
    } 
    cout<<low<<endl;

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
