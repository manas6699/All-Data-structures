#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int nby3 = n/3;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        vector<int> ans;
        for(auto i:mp)
        {
            if(i.second>nby3)
            {
                ans.push_back(i.first);
            }
        }
        return ans;
        
    }
};
int main()
{
    vector<int> nums = {3,2,3};
    Solution s;
    vector<int> ans = s.majorityElement(nums);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }


 return 0;
}