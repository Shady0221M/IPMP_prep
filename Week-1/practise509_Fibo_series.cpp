#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int fib(int n) {
        vector<int>a;
        if(n==0){return 0;}
        else if(n==1){return 1;}
        a.push_back(0);
        a.push_back(1);
        for(int i=2;i<=n;i++){a.push_back(a[i-1]+a[i-2]);}
        return a[n];
    }
};