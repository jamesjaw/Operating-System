#include <iostream>
#include <vector>
#include <pthread.h>
#include <string>
using namespace std;

pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m3 = PTHREAD_MUTEX_INITIALIZER;

string Q;
int p_num;
int lenth;

long long countz[3];
void* clu(void* input){
    int amount = lenth / p_num;
    
    long start = (long)input * amount;
    //if((long)input == p_num - 1) amount += lenth % p_num;
    
    for(long i=start;i<amount;i++){
        if(Q[i] == '0'){
            pthread_mutex_lock(&m1);
            countz[0]++;
            pthread_mutex_unlock(&m1);
        }
        else if(Q[i] == '1'){
            pthread_mutex_lock(&m2);
            countz[1]++;
            pthread_mutex_unlock(&m2);
        }
        else if(Q[i] == '2'){
            pthread_mutex_lock(&m3);
            countz[2]++;
            pthread_mutex_unlock(&m3);
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
        cout<<i<<": "<<countz[i]<<"\n";
    }
    
    return 0;
}
