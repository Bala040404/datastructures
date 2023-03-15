    #include<bits/stdc++.h>
    using namespace std;
    const int inf=1e5; 
    vector <int> dis(100,inf);

    int main(){
        vector<pair<int,int>> gr[100];

        int n;
        cout<<"nodes ? ";
        cin>>n;
        
        int ed;
        cout<<"edges ? ";
        cin>>ed;

        for(int i = 0;i<ed;i++){
            int x,y,wt;
            cin>>x >>y>>wt;
            gr[x].push_back({y,wt});
        }
        dis[1]=0;
        for(int i = 1;i<=n;i++){
            
            for(auto x:gr[i]){
                if(dis[x.first]>x.second+dis[i]){
                    dis[x.first]=x.second+dis[i];
                }
            }
        }

        for(int i = 1;i<=n;i++){
            cout<<dis[i]<<" ";
        }

    }