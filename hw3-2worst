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
    
    int amount = countz / 4;
    long start = (long)input * amount;
    if((long)input == 3) amount += (countz % 4);
    
    
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
    pthread_t t1, t2, t3 ,t4;
    
    pthread_create(&t1, NULL, bubble, (void*)0);
    pthread_create(&t2, NULL, bubble, (void*)1);
    pthread_create(&t3, NULL, bubble, (void*)2);
    pthread_create(&t4, NULL, bubble, (void*)3);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    
    int len = countz/4;
    int a = len*0;
    int b = len*1;
    int c = len*2;
    int d = len*3;
    
    pra pra1;
    pra1.str = a;
    pra1.mid = b;
    pra1.end = c;
    pthread_create(&t1, NULL, merge, &pra1);
    
    pra pra2;
    pra2.str = c;
    pra2.mid = d;
    pra2.end = countz;
    pthread_create(&t2, NULL, merge, &pra2);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    pra1.str = a;
    pra1.mid = c;
    pra1.end = countz;
    pthread_create(&t1, NULL, merge, &pra1);
    pthread_join(t1, NULL);
    
    for(int i=0;i<countz;i++) cout<<data[i]<<" ";
    return 0;
}
