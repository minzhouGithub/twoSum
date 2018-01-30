#include "utils.h"


int main()
{
	int nums_ori[5] = { 5, 2, 2, 0 };
	vector<int> nums;
	for (int i(0); i < 5; i++)	nums.push_back(nums_ori[i]);

	Solution sol;
	vector<int> rst = sol.twoSum(nums, 7);

	return 0;
}