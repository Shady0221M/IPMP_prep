#include<iostream>
#include<cmath>
using namespace std;
int hours_taken(int*piles,int pilesSize, int k){
    int sum=0,i;
    for(i=0;i<pilesSize;i++){
        sum+=(int)ceil((double)piles[i]/k);
    }

    return sum;
}
int max_value(int*piles, int pilesSize){
    int m=piles[0];
    int i;
    for(i=1;i<pilesSize;i++){
        if(piles[i]>m){m=piles[i];}
    }
    return m;
}
int minEatingSpeed(int* piles, int pilesSize, int h) {
    int n=max_value(piles,pilesSize);
    int x=0,b;
    for(b=n;b>=1;b/=2){
        cout<<x<<"  "<<b<<"   "<<x+b<<"   "<<hours_taken(piles,pilesSize,x+b)<<endl;
        while(hours_taken(piles,pilesSize,x+b) > h){x+=b;}
    }
    return x+1;
}
int main(){
    int pilesSize=4;
    int piles[]={3,6,7,11};
    int h=8;
    cout<<minEatingSpeed(piles,pilesSize,h);
}