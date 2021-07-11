#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

/*
		Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
		You may assume that each input would have exactly one solution, and you may not use the same element twice.
		You can return the answer in any order.

		Example 1:
		Input: nums = [2,7,11,15], target = 9
		Output: [0,1]
		Output: Because nums[0] + nums[1] == 9, we return [0, 1].

		Example 2:
		Input: nums = [3,2,4], target = 6
		Output: [1,2]

		Example 3:
		Input: nums = [3,3], target = 6
		Output: [0,1]

		Constraints:
		2 <= nums.length <= 104
		-109 <= nums[i] <= 109
		-109 <= target <= 109
		Only one valid answer exists.

		Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
*/

/* O(n2) time complexity solution */
class Solution
{
	public:
		std::vector<int> twoSum(std::vector<int>& nums, const int target)
		{
			int first_pos  = 0;
			int second_pos = 0;

			for (auto i = 0; i < nums.size(); ++i)
			{
				const int first_value = nums[i];
				const auto it = std::find(nums.begin(), nums.end(), target - first_value);

				if (it != nums.end() and (std::addressof(*it) != (nums.data() + i)))
				{
					first_pos = i;
					second_pos = std::distance(nums.begin(), it);

					break;
				}
			}

			return { first_pos, second_pos };
		}
};

int main()
{
	return 0;
}
