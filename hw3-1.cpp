#include <iostream>
#include <vector>
#include <pthread.h>

using namespace std;

int data[1000005];
int countz = 0;
int num = 0;
int lest = 0;

void* bubble(int input){
    
    int amount = countz / 4;
    int start = input * amount;
    if(input == 3) amount += (countz % 4);
    
    
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
    return NULL;
}

void* merge(int str, int mid, int end){
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
    bubble(0);
    bubble(1);
    bubble(2);
    bubble(3);
    
    int len = countz/4;
    int a = len*0;
    int b = len*1;
    int c = len*2;
    int d = len*3;
    merge(a, b, c);
    merge(c, d, countz);
    
    b = c;
    merge(a, b, countz);
    
    for(int i=0;i<countz;i++) cout<<data[i]<<" ";
    return 0;
}
