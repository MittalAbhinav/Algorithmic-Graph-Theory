#include<bits/stdc++.h>

using namespace std;


/////KADANE's algo
/*The idea of Kadane’s algorithm is to maintain a variable max_ending_here 
that stores the maximum sum contiguous subarray ending at current index and
a variable max_so_far stores the maximum sum of contiguous subarray found
so far, Everytime there is a positive-sum value in max_ending_here compare
it with max_so_far and update max_so_far if it is greater than max_so_far.*/



int sum=0;
int maxsum=INT_MIN;
for (int i=0;i<n;i++){
    sum+=arr[i];
    maxsum=max(sum,maxsum);
    if (sum<0)sum=0;
}
return maxsum;