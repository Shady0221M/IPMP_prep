/*Find the missing number in an array


263

5
Problem Statement: Given an integer N and an array of size N-1 containing N-1 numbers between 1 to N. Find the number(between 1 to N), that is not present in the given array.

Examples
Example 1:
Input Format:
 N = 5, array[] = {1,2,4,5}
Result:
 3
Explanation: 
In the given array, number 3 is missing. So, 3 is the answer.

Example 2:
Input Format:
 N = 3, array[] = {1,3}
Result:
 2
Explanation: 
In the given array, number 2 is missing. So, 2 is the answer.*/
#include <iostream> 
#include<vector>
using namespace std;
#include<algorithm>
//O(n) XOR APPROACH
/*Algorithm / Intuition
XOR Approach:
Intuition:
Two important properties of XOR are the following:

XOR of two same numbers is always 0 i.e. a ^ a = 0. ←Property 1.
XOR of a number with 0 will result in the number itself i.e. 0 ^ a = a.  ←Property 2

Now, let’s XOR all the numbers between 1 to N.
xor1 = 1^2^.......^N

Let’s XOR all the numbers in the given array.
xor2 = 1^2^......^N (contains all the numbers except the missing one).

Now, if we again perform XOR between xor1 and xor2, we will get:
xor1 ^ xor2 = (1^1)^(2^2)^........^(missing Number)^.....^(N^N)

Here all the numbers except the missing number will form a pair and each pair will result in 0 according to the XOR property. The result will be = 0 ^ (missing number) = missing number (according to property 2).

So, if we perform the XOR of the numbers 1 to N with the XOR of the array elements, we will be left with the missing number.

Approach:
The steps are as follows:

We will first run a loop(say i) from 0 to N-2(as the length of the array = N-1).
Inside the loop, xor2 variable will calculate the XOR of array elements
i.e. xor2 = xor2 ^ a[i].
And the xor1 variable will calculate the XOR of 1 to N-1 i.e. xor1 = xor1 ^ (i+1).
After the loop ends we will XOR xor1 and N to get the total XOR of 1 to N.
Finally, the answer will be the XOR of xor1 and xor2.
Dry run:

Assume the given array is: {1, 2, 4, 5} and N = 5.
XOR of (1 to 5) i.e. xor1 = (1^2^3^4^5)
XOR of array elements i.e. xor2 = (1^2^4^5)
XOR of xor1 and xor2 = (1^2^3^4^5) ^ (1^2^4^5)
			= (1^1)^(2^2)^(3)^(4^4)^(5^5)
			= 0^0^3^0^0 = 0^3 = 3.
The missing number is 3.
Code
Complexity Analysis

Time Complexity: O(N), where N = size of array+1.
Reason: Here, we need only 1 loop to calculate the XOR. The loop runs for approx. N times. So, the time complexity is O(N).

Space Complexity: O(1) as we are not using any extra space*/

//O(n)
int missingNumber2(vector<int>&a, int N) {
    int sum=(N*(N+1))/2;
    int x=0;
    for(int i=0;i<N-1;i++){
        x+=a[i];
    }
    return sum-x;
}
//O(nlogn)
int missingNumber1(vector<int>&a, int N) {
    sort(a.begin(),a.end());
    for(int i=0;i<N-2;i++){
        if(a[i]==a[i+1]-1) continue;
        else return a[i]+1;
    }
    return N;
}