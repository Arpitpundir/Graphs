#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        unordered_map<int, int> l;
        unordered_map<int, int> s;

        int n;
        cin>>n;
        while(n--){

            int st, end;
            cin>>st>>end;
            l[st] = end;
        }

        int m;
        cin>>m;
        while(m--) {

            int st, end;
            cin>>st>>end;
            s[st] = end;
        }

        int curr = 1;
        deque<pair<int, int> > q;

        q.push_front(make_pair(1, 0));

        vector<bool> vis;
        vis.resize(101, false);

        int ans = INT_MAX;
        bool found = false;

        while(!q.empty()){

            int curr = q.back().first;
            int steps = q.back().second;
            q.pop_back();

            //cout<<curr<<" "<<steps<<endl;

            vis[curr] = true;

            if(curr == 100 && steps < ans){

                ans = steps;
                found = true;
            }

            if(l.find(curr) != l.end()){

                if(l[curr] <= 100 && !vis[l[curr]])
                q.push_front(make_pair(l[curr], steps));
            }else if(s.find(curr) != s.end()){

                if(s[curr] <= 100 && !vis[s[curr]])
                q.push_front(make_pair(s[curr], steps));
            }else{

                for(int i = 1;i <= 6;i++){

                    if(curr+i <= 100 && !vis[curr+i]){

                        vis[curr+i] = true;
                        q.push_front(make_pair(curr+i, steps+1));
                        //cout<<"p "<<curr<<" "<<curr+i<<endl;
                    }
                }
            }
        }
        
        if(found)
        cout<<ans<<endl;
        else {
        cout<<"-1"<<endl;
        }
    }
}