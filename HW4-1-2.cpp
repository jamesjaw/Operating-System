#include <iostream>
#include <vector>
#include <pthread.h>
#include <string>
using namespace std;

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m3 = PTHREAD_MUTEX_INITIALIZER;

//pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

string Q;
int p_num;
int lenth;
int amount;

struct pra{
    int start;
    pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
};


long long countz[3];
void* clu(void* input){
    pra* s = (pra*)input;
    for(long i=s->start;i<s->start + amount;i++){
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
    int i = s->start / amount;
    
    if(i!=0){
        
        //pthread_cond_wait(&(s->cond))
    }
    cout<<i<<": "<<countz[i]<<"\n";
    
    pthread_exit(0);
    return NULL;
}

int main(){
    p_num = 3;
    //cin>>p_num;
    cin>>lenth;
    cin>>Q;
    amount = lenth / p_num;
    //cout<<amount<<"\n";
    pthread_t pid[4];
    pra arg[4];
    for(int i=0;i<p_num;i++){
        arg[i].start = i * amount;
        pthread_create(&pid[i], NULL, clu, &arg[i]);
    }
    for(int i=0;i<p_num;i++){
        pthread_join(pid[i], NULL);
    }
        
    return 0;
}
