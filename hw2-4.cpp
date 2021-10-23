#include <iostream>
#include <queue>
#define pa pair<int,int>
using namespace std;

priority_queue<pa,vector<pa>,greater<pa>> ready2;


int main(){
    int pnum;
    cin>>pnum;
    int a[100];
    int b[100];
    int w[100];
    int t[100];
    int r[100];
    for(int i=1;i<=pnum;i++){
        cin>>a[i];
    }
    for(int i=1;i<=pnum;i++){
        cin>>b[i];
    }
    int q;
    cin>>q;
    int count = 0;
    int time = 0;
    queue<int> ready;
    
    time = a[1];
    ready.push(1);
    int next = 2;
    
    while(count != pnum){
        if(ready.empty()){
            if(ready2.empty()){
                time++;
                if(next <= pnum && a[next] <= time){
                    ready.push(next);
                    next++;
                }
            }
            else{
                auto pick = ready2.top();
                ready2.pop();
                int bust = pick.first;
                int now = pick.second;
                int f = 0;
                for(int i=1;i<=bust;i++){
                    time++;
                    if(next <= pnum && a[next] <= time){
                        ready.push(next);
                        next++;
                        
                        pick.first -= i;
                        ready2.push(pick);
                        break;
                    }
                    if(i == bust){
                        f = 1;
                    }
                }
                if(f == 1){
                    t[now] = time - a[now];      //turnover = finshtime - arrvil
                    w[now] = t[now] - b[now];    //wating = turnover - bust
                    count++;
                }
                
            }
        }
        else{
            int now = ready.front();
            ready.pop();
            int f = 0;
            for(int i=0;i<q;i++){
                r[now]++;
                time++;
                if(next <= pnum && a[next] <= time){
                    ready.push(next);
                    next++;
                }
                if(r[now] == b[now]){
                    t[now] = time - a[now];      //turnover = finshtime - arrvil
                    w[now] = t[now] - b[now];    //wating = turnover - bust
                    f = 1;
                    count++;
                    break;
                }
            }
            if(f==0){
                int lest = b[now] - r[now];
                pa zzz;
                zzz.first = lest;
                zzz.second = now;
                ready2.push(zzz);
            }
        }
    }
    //cout<<"???\n";
    int tow = 0;
    int tot = 0;
    for(int i=1;i<=pnum;i++){
        cout<<w[i]<<" "<<t[i]<<"\n";
        tow += w[i];
        tot += t[i];
    }
    cout<<tow<<"\n";
    cout<<tot;
    
    return 0;
}
