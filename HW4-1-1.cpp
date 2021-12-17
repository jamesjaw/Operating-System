#include <iostream>
#include <vector>
#include <pthread.h>
#include <string>
using namespace std;

string Q;
int p_num;
int lenth;

long long countz[3];
void* clu(void* input){
    int amount = lenth / p_num;
    
    long start = (long)input * amount;
    if((long)input == p_num - 1) amount += lenth % p_num;
    
    for(long i=start;i<amount;i++){
        if(Q[i] == '0'){
            countz[0]++;
        }
        else if(Q[i] == '1'){
            countz[1]++;
        }
        else if(Q[i] == '2'){
            countz[2]++;
        }
    }
    pthread_exit(0);
    return NULL;
}

int main(){
    //p_num = 3;
    cin>>p_num;
    cin>>lenth;
    cin>>Q;
    
    pthread_t pid[4];
    
    for(int i=0;i<p_num;i++){
        pthread_create(&pid[i], NULL, clu, (void*)i);
    }
    for(int i=0;i<p_num;i++){
        pthread_join(pid[i], NULL);
    }
    
    for(int i=0;i<3;i++){
        cout<<i<<" "<<countz[i]<<"\n";
    }
    
    return 0;
}
