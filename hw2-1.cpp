#include <iostream>


using namespace std;

int main(){
    int p_num;
    int p_data[4][100];
    cin>>p_num;
    for(int i=1;i<=p_num;i++){
        cin>>p_data[i][0];
    }
    for(int i=1;i<=p_num;i++){
        cin>>p_data[i][1];
    }
   
    int time = 0;
    for(int i=1;i<=p_num;i++){
        if(time < p_data[i][0]) time = p_data[i][0];
        p_data[i][2] = time - p_data[i][0];
        time += p_data[i][1];
        p_data[i][3] = p_data[i][2] + p_data[i][1];
    }
    int wait_time = 0;
    int turn_time = 0;
    for(int i=1;i<=p_num;i++){
        cout<<p_data[i][2]<<" "<<p_data[i][3]<<"\n";
        wait_time += p_data[i][2];
        turn_time += p_data[i][3];
    }
    cout<<wait_time<<"\n";
    cout<<turn_time;
    return 0;
}
