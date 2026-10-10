
#include <bits/stdc++.h>
using namespace std;

// Optimal solution using MERGE SORT

class Solution {
public:
    int count = 0;

    vector<int> mergeSort(vector<int>& nums) {
        int n = nums.size();

        // Function of MERGE CODE
        function<void(int, int, int)> merge = [&](int low, int mid, int high) {
            vector<int> temp;

            int left = low;
            int right = mid + 1;

            while(left <= mid && right <= high) {
                if(nums[left] <= nums[right]) {
                    temp.push_back(nums[left]);
                    left++;
                }
                else {
                    temp.push_back(nums[right]);
                    right++;
                }
            }

            while(left <= mid) {
                temp.push_back(nums[left]);
                left++;
            }

            while(right <= high) {
                temp.push_back(nums[right]);
                right++;
            }

            for(int i = low; i <= high; i++) {
                nums[i] = temp[i - low];
            }
        };

        function<void(int, int, int)> countPairs = [&](int low, int mid, int high) {
            int right = mid + 1;

            for(int i = low; i <= mid; i++) {
                while(right <= high && nums[i] > 2LL * nums[right]) {
                    right++;
                }
                count += right - (mid + 1);
            }
        };

        function<void(int, int)> reversePairs = [&](int low, int high) {
            if(low >= high) {
                return;
            }

            int mid = low + (high - low) / 2;

            reversePairs(low, mid);
            reversePairs(mid + 1, high);

            countPairs(low, mid, high);
            merge(low, mid, high);
        };

        reversePairs(0, n - 1);

        return nums;
    }

    int reversePairs(vector<int>& nums) {
        count = 0;
        mergeSort(nums);
        return count;
    }
};
