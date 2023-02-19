
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        int n = nums.size();
        int i = n-1;
        vector<int> ans;
        while(i>=0 || k>0)
        {
            if(i>=0)
            {
                k = k + nums[i];
            }
            ans.push_back(k%10);
            k = k/10;
            i--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
int main()
{
    vector<int> nums = {1,2,0,0};
    Solution s;
    int k = 34;
    vector<int> ans2 = s.addToArrayForm(nums ,k);
    for(int i=0;i<ans2.size();i++)
    {
        cout<<ans2[i]<<" ";
    }
 return 0;
}