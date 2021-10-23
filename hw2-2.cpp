#include <iostream>


using namespace std;

int main(){
    int pnum;
    cin>>pnum;
    int a[100];
    int b[100];
    int w[100];
    int t[100];
    for(int i=1;i<=pnum;i++){
        cin>>a[i];
    }
    for(int i=1;i<=pnum;i++){
        cin>>b[i];
    }
    int count = 0;
    int time = 0;
    int flag[100];
    while(count != pnum){
        int f = 0;
        int pick = 0;
        int shortest = INT_MAX;
        for(int i=1;i<=pnum;i++){
            if(a[i] <= time && flag[i] == 0 && b[i] < shortest){
                shortest = b[i];
                pick = i;
                f = 1;
            }
        }
        
        if(f == 1){
            //cout<<"pick:"<<pick<<"\n";
            w[pick] = time - a[pick];
            t[pick] = w[pick] + b[pick];
            time += b[pick];
            flag[pick] = 1;
            count++;
        }
        else{
            time++;
        }
    }
    
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
