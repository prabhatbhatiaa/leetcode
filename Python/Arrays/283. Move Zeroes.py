# LC Problem 283: Move Zeroes

# Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zeroes.
# Note that you must do this in-place without making a copy of the array.

# Example 1:
# Input: nums = [0,1,0,3,12]
# Output: [1,3,12,0,0]

# Example 2:
# Input: nums = [0]
# Output: [0]
 

# Approach 1: Two Pointers
class Solution(object):
    def moveZeroes(self, nums):
        j = 0
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[i], nums[j] = nums[j], nums[i]
                j += 1

# Time Complexity: O(N)
# Space Complexity: O(1)

# *Algo*
# Iterate through the array, and for each non zero element, swap it with the earliest zero position found so far.
# Continue this process so that all non zero elements are shifted forward in their original order, and all zeroes are moved to the end.