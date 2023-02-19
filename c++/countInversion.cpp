#include<iostream>
#include <bits/stdc++.h>
using namespace std;

long long getInversions(vector<int>& arr, int n){
    // Write your code here.
    long long count = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                count++;
            }
        }
    }
    return count;

}

int merge(vector<int>& nums , int low , int mid , int high)
    {
        // cnt variable stores total number of pairs
        int cnt = 0;
        int j = mid + 1;
        for(int i = low ;i <= mid ; i++ )
        {
            // 2LL means 2 of type long long
            while(j <= high && nums[i] > (long long) 2 * nums[j])
            {
                j++;
            }
            cnt += (j - (mid + 1)); 
        }
        vector<int> temp;
        int left = low , right = mid + 1;
        while(left <= mid && right <= high)
        {
            if(nums[left] <= nums[right])
            {
                temp.push_back(nums[left++]);
            }
            else
            {
                temp.push_back(nums[right++]);
            }
        }
        
        while(left <= mid)
        {
             temp.push_back(nums[left++]);
        }
        while(right <= high)
        {
            temp.push_back(nums[right++]);
        }
        
        for(int i = low ; i <= high ; i++)
        {
            nums[i] = temp[i - low];
        }
        
        return cnt;
    }
    int mergeSort(vector<int>& nums , int low ,int high)
    {
        if(low >= high)
        {
            return 0;
        }
        int mid = (low + high) / 2;
        // left recursion
        int inv = 0;
        inv += mergeSort(nums , low , mid);
        // right recursion
        inv += mergeSort(nums , mid + 1 , high);
        // merge call
        inv += merge(nums , low , mid , high);
        return inv;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums , 0 , nums.size() - 1);
    }
int main()
{
    
    vector<int> arr = {40,25,19,12,9,6,2};

    // cout<<getInversions(arr,n);
    cout << "Reverse pairs are: " << reversePairs(arr) << endl;
 return 0;
}