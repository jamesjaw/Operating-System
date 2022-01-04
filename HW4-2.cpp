#include <iostream>
#include <vector>
#include <pthread.h>
#include <cstdlib>
using namespace std;

int thr_num;
int point_num;
long long countz = 0;

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
void* mtcl_pi(void* input){
    
    int num = point_num / thr_num;
    double x,y;
    for(int i=0;i<num;i++){
        // forget turn to double = =
        x = (double)rand()/RAND_MAX;
        //cout<<x<<" ";
        y = (double)rand()/RAND_MAX;
        //cout<<y<<" ";
        if((x*x + y*y) < 1){
            pthread_mutex_lock(&m);
            countz++;
            pthread_mutex_unlock(&m);
        }
    }
    
    return NULL;
}

int main(){
    cin>>thr_num>>point_num;
    pthread_t pid[5];
    
    for(int i=0;i<thr_num;i++){
        pthread_create(&pid[i], NULL, mtcl_pi, (void*)0);
    }
    for(int i=0;i<thr_num;i++){
        pthread_join(pid[i], NULL);
    }
    double pi = 4.0 * countz / point_num;
    cout<<"get: "<<countz<<"\n";
    cout<<"Pi: "<<pi<<"\n";
    return 0;
}
