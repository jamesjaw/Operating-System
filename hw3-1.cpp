#include <iostream>
#include <pthread.h>

using namespace std;

int data[1000005];
int countz = 0;
int num = 0;
int lest = 0;

void* bubble(int input){
    int amount = num;
    if(input == 3) amount += lest;
    int start = input * num;
    
    for(int i=0;i<amount-1;i++){
        for(int j=0;j<amount-1-i;j++){
            if(data[start+j] > data[start+j+1]){
                int temp = data[start+j];
                data[start+j] = data[start+j+1];
                data[start+j+1] = temp;
            }
        }
    }
    return NULL;
}

void* merge(void* input){
    
    return NULL;
}

int main(){
    for(int i=0;i<=1000005;i++){
        data[i] = 0;
    }
    
    while(cin>>data[countz]){
        countz++;
    }
    num = countz / 4;
    lest = countz % 4;
    bubble(0);
    bubble(1);
    bubble(2);
    bubble(3);
    
    
    for(int i=0;i<countz;i++) cout<<data[i]<<" ";
    return 0;
}
