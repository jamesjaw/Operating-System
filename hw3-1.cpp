#include <iostream>
#include <vector>
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

void* merge(int input, int por){
    int amount = countz / por;
    int start_L = amount * input;
    int start_R = amount * (input+1);
    int end_L = start_L + amount;
    int end_R = start_R + amount;
    if(input == por - 1) end_R += (countz % por);
    
    int start = start_L;
    vector<int> temp;
    while(1){
        if(start_L == end_L){
            while(start_R != end_R){
                temp.push_back(data[start_R]);
                start_R++;
            }
            break;
        }
        if(start_R == end_R){
            while(start_L != end_L){
                temp.push_back(data[start_L]);
                start_L++;
            }
            break;
        }
        if(data[start_L] < data[start_R]){
            temp.push_back(data[start_L]);
            start_L++;
        }
        else{
            temp.push_back(data[start_R]);
            start_R++;
        }
    }
    for(int i:temp){
        data[start] = i;
        start++;
    }
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
    
    merge(0, 4);
    merge(2, 4);
    merge(0, 2);
 
    for(int i=0;i<countz;i++) cout<<data[i]<<" ";
    return 0;
}
