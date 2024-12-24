#include <bits/stdc++.h>

using namespace std;

vector<int> vs;

int solve(int l, int r){
        if ( l>r) return 0;
        int ind = -1;
        int mn = *min_element(vs.begin()+l,vs.begin()+r+1);
        for(int i=l;i<=r;i++){
                vs[i] -=mn;
                if(vs[i]==0) ind = i;  
        }
        assert(ind!=-1);
        return min(solve(l,ind-1)+solve(ind+1,r)+mn,r-l+1); 
}

int main(){
        int n;
        cin >> n;
        for(int i=0;i<n;i++){
                int k;
                cin >> k;
                vs.push_back(k);
        }
        cout << solve(0,n-1) << "\n";
}
