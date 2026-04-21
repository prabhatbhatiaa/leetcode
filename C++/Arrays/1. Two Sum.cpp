// LC Problem 1: Two Sum

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

// Example 1:
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

// Example 2:
// Input: nums = [3,2,4], target = 6
// Output: [1,2]

// Example 3:
// Input: nums = [3,3], target = 6
// Output: [0,1]

// -----------------------------------------------------------------------------------------------------

// Approach 1: Brute Force
// Time Complexity: O(n^2) - Used nested loops

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i,j};
                }
            }
        }
        return {};
    }
};

// -----------------------------------------------------------------------------------------------------

// Approach 2: Two Pointers
// Time Complexity: O(nlogn) -  Sorting: O(nlogn) + Two Pointer: O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> arr;

        for (int i=0; i<nums.size(); i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        int left = 0;
        int right = arr.size()-1;

        while (left < right) {
            int sum = arr[left].first + arr[right].first;
            if (sum == target) {
                return {arr[left].second , arr[right].second};
            }
            else if(sum < target) {
                left ++;
            }
            else {
                right --;
            }
        }

        return {};
    }
};

// -----------------------------------------------------------------------------------------------------

// Approach 3: Hash Map
// Time Complexity: O(n) -  We traverse the list containing n elements only once.

class Solution{
    public:
        vector<int> twoSum(vector<int>& nums, int target) {

            unordered_map<int,int> hmap;

            for (int i=0; i<nums.size(); i++) {
                int check = target - nums[i];

                if(hmap.find(check) != hmap.end()) {
                    return {hmap[check], i};
                }
                hmap[nums[i]] = i;
            }
            return {};
        }
};