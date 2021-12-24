#include <iostream>
#include <vector>
#include <pthread.h>
#include <string>
#include <semaphore.h>
using namespace std;

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m3 = PTHREAD_MUTEX_INITIALIZER;

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_cond_t c1 = PTHREAD_COND_INITIALIZER;
pthread_cond_t c2 = PTHREAD_COND_INITIALIZER;
pthread_cond_t c3 = PTHREAD_COND_INITIALIZER;

sem_t sem1_1;
sem_t sem1_2;
sem_t sem2;
sem_t sem3;

string Q;
int p_num;
int lenth;
int amount;

struct pra{
    int start;
    //pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
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
    if(i==0){
        sem_wait(&sem1_1);
        sem_wait(&sem1_2);
        cout<<i<<": "<<countz[i]<<"\n";
        sem_post(&sem1_1);
        sem_post(&sem1_2);
        sem_post(&sem2);
    }
    else if(i==1){
        sem_post(&sem1_1);
        sem_wait(&sem2);
        cout<<i<<": "<<countz[i]<<"\n";
        sem_post(&sem2);
        sem_post(&sem3);
    }
    else if(i==2){
        sem_post(&sem1_2);
        sem_wait(&sem3);
        cout<<i<<": "<<countz[i]<<"\n";
        sem_post(&sem3);
    }
    pthread_exit(0);
    return NULL;
}

int main(){
    sem_init(&sem1_1,0,1);
    sem_init(&sem1_2,0,1);
    sem_init(&sem2,0,1);
    sem_init(&sem3,0,1);
    
    sem_wait(&sem1_1);
    sem_wait(&sem1_2);
    sem_wait(&sem2);
    sem_wait(&sem3);
    
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
