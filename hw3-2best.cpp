#include <iostream>
#include <vector>
#include <pthread.h>

using namespace std;

int data[1000005];
int countz = 0;

typedef struct{
    int str;
    int mid;
    int end;
}pra;

void* bubble(void* input){
    
    int amount = countz / 8;
    long start = (long)input * amount;
    if((long)input == 3) amount += (countz % 8);
    
    
    for(int i=0;i<amount-1;i++){
        for(int j=0;j<amount-1-i;j++){
            if(data[start+j] > data[start+j+1]){
                int temp = data[start+j];
                data[start+j] = data[start+j+1];
                data[start+j+1] = temp;
            }
        }
    }
    /*
    for(int i=0;i<amount;i++){
        cout<<data[start + i]<<" ";
    }
    cout<<"\n";
    */
    pthread_exit(NULL);
    return NULL;
}

void* merge(void* input){
    pra* set = (pra*)input;
    int str = set->str;
    int mid = set->mid;
    int end = set->end;
    vector<int> temp;
    int L = str;
    int R = mid;
    while(1){
        if(L == mid){
            while(R!=end){
                temp.push_back(data[R]);
                R++;
            }
            break;
        }
        if(R == end){
            while(L!=mid){
                temp.push_back(data[L]);
                L++;
            }
            break;
        }
        if(data[L]<data[R]){
            temp.push_back(data[L]);
            L++;
        }
        else{
            temp.push_back(data[R]);
            R++;
        }
    }
    for(int i=0;i<temp.size();i++){
        //cout<<temp[i]<<" ";
        data[str + i] = temp[i];
    }
    //cout<<"\n";
    pthread_exit(NULL);
    return NULL;
}

int main(){
    for(int i=0;i<=1000005;i++){
        data[i] = 0;
    }
    
    while(cin>>data[countz]){
        countz++;
    }
    //cout<<"countz = "<<countz<<"\n";
    pthread_t t1, t2, t3 ,t4, t5, t6, t7, t8;
    
    pthread_create(&t1, NULL, bubble, (void*)0);
    pthread_create(&t2, NULL, bubble, (void*)1);
    pthread_create(&t3, NULL, bubble, (void*)2);
    pthread_create(&t4, NULL, bubble, (void*)3);
    pthread_create(&t5, NULL, bubble, (void*)4);
    pthread_create(&t6, NULL, bubble, (void*)5);
    pthread_create(&t7, NULL, bubble, (void*)6);
    pthread_create(&t8, NULL, bubble, (void*)7);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    pthread_join(t5, NULL);
    pthread_join(t6, NULL);
    pthread_join(t7, NULL);
    pthread_join(t8, NULL);
    
    int len = countz/8;
    int s1 = len*0;
    int s2 = len*1;
    int s3 = len*2;
    int s4 = len*3;
    int s5 = len*4;
    int s6 = len*5;
    int s7 = len*6;
    int s8 = len*7;
    
    pra pra1;
    pra1.str = s1;
    pra1.mid = s2;
    pra1.end = s3;
    pthread_create(&t1, NULL, merge, &pra1);
    
    pra pra2;
    pra2.str = s3;
    pra2.mid = s4;
    pra2.end = s5;
    pthread_create(&t2, NULL, merge, &pra2);
    
    pra pra3;
    pra3.str = s5;
    pra3.mid = s6;
    pra3.end = s7;
    pthread_create(&t3, NULL, merge, &pra3);
    
    pra pra4;
    pra4.str = s7;
    pra4.mid = s8;
    pra4.end = countz;
    pthread_create(&t4, NULL, merge, &pra4);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    //=============================================
    pra1.str = s1;
    pra1.mid = s3;
    pra1.end = s5;
    pthread_create(&t1, NULL, merge, &pra1);
    
    pra2.str = s5;
    pra2.mid = s7;
    pra2.end = countz;
    pthread_create(&t2, NULL, merge, &pra2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    //==============================================
    pra1.str = s1;
    pra1.mid = s5;
    pra1.end = countz;
    pthread_create(&t1, NULL, merge, &pra1);
    pthread_join(t1, NULL);
    
    for(int i=0;i<countz;i++) cout<<data[i]<<" ";
    return 0;
}
