#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<random>


using namespace std;

class RandomizedSet {
public:
    map<int,int> hash;
    vector<int> a;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(hash.count(val)){
            return false;
        }else{
            hash[val]=a.size();
            a.push_back(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if(hash.count(val)){
            int i=hash[val];
            hash.erase(val);
            a[i]=a[a.size()-1];
            hash[a[i]]=i;
            a.pop_back();
            return true;
        }else{return false;}
    }
    
    int getRandom() {
        random_device rd;
        mt19937 gen(rd()); 
        uniform_int_distribution<> dis(0, a.size()-1); 

        return a[dis(gen)];
    }
};

int main(){
    RandomizedSet r;
//1
    cout<<r.remove(0)<<endl;
    cout<<"a: ";
    for(int i=0;i<r.a.size();i++){
        cout<<r.a[i]<<" ";
    }
    cout<<endl<<endl;

    cout<<"hash: ";
    for(auto x:r.hash){
        cout<<x.first<<" : "<<x.second<<endl;
    }
    cout<<endl<<endl;

//2
    cout<<r.remove(0)<<endl;
    cout<<"a: ";
    for(int i=0;i<r.a.size();i++){
        cout<<r.a[i]<<" ";
    }
    cout<<endl<<endl;

    cout<<"hash: ";
    for(auto x:r.hash){
        cout<<x.first<<" : "<<x.second<<endl;
    }
    cout<<endl<<endl;

//3
    cout<<r.insert(0)<<endl;
    cout<<"a: ";
    for(int i=0;i<r.a.size();i++){
        cout<<r.a[i]<<" ";
    }
    cout<<endl<<endl;

    cout<<"hash: ";
    for(auto x:r.hash){
        cout<<x.first<<" : "<<x.second<<endl;
    }
    cout<<endl<<endl;

//4
    cout<<r.getRandom()<<endl;
    cout<<"a: ";
    for(int i=0;i<r.a.size();i++){
        cout<<r.a[i]<<" ";
    }
    cout<<endl<<endl;

    cout<<"hash: ";
    for(auto x:r.hash){
        cout<<x.first<<" : "<<x.second<<endl;
    }
    cout<<endl<<endl;

//5
    cout<<r.remove(0)<<endl;
    cout<<"a: ";
    for(int i=0;i<r.a.size();i++){
        cout<<r.a[i]<<" ";
    }
    cout<<endl<<endl;

    cout<<"hash: ";
    for(auto x:r.hash){
        cout<<x.first<<" : "<<x.second<<endl;
    }
    cout<<endl<<endl;

//6
    cout<<r.insert(0)<<endl;
    cout<<"a: ";
    for(int i=0;i<r.a.size();i++){
        cout<<r.a[i]<<" ";
    }
    cout<<endl<<endl;

    cout<<"hash: ";
    for(auto x:r.hash){
        cout<<x.first<<" : "<<x.second<<endl;
    }
    cout<<endl<<endl;

    
    
    
    
    
}