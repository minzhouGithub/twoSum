#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::runtime_error;


class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {

		// in case the input array is empty
		if (nums.size()<2)
			throw runtime_error("empty array");

		// copy & sort the array
		vector<int> nums_copy;
		nums_copy.assign(nums.begin(), nums.end());
		int length_nums = nums_copy.size();
		vector<size_t> inx = _sortIndexes(nums);
		sort(nums_copy.begin(), nums_copy.begin() + length_nums);

		// roughly judge whether target is out of range
		if (target > 2 * nums_copy[length_nums - 1] || target < 2 * nums_copy[0])
			throw runtime_error("Target is not in the proper range");

		// search proper nums
		vector<int> returnNums;
		while (--length_nums>0)
		{
			int num1 = nums_copy[length_nums];
			int num2 = target - num1;
			int num2_posi = -1;

			if (_findNum2(nums_copy, 0, length_nums - 1, num2, num2_posi))
			{
				returnNums.push_back(std::min(inx[length_nums], inx[num2_posi]));
				returnNums.push_back(std::max(inx[length_nums], inx[num2_posi]));
				break;
			}
		}

		if (returnNums.empty())
			throw runtime_error("There are no matched numbers for this target");
		else
			return returnNums;
	}

private:
	// search num2
	bool _findNum2(const vector<int>& nums, int first, int end, int num2, int& num2_posi)
	{
		if (first < 0 && end >= nums.size() && end < first)
			throw runtime_error("error");

		int middle = (first + end) / 2;
		if (nums[middle] == num2)    { num2_posi = middle; return true; }
		else if (end - first <= 0)    { return false; }
		else if (nums[middle] < num2){ return _findNum2(nums, middle + 1, end, num2, num2_posi); }
		else if (middle <= first)    { return false; }
		else                        { return _findNum2(nums, first, middle - 1, num2, num2_posi); }
	}

	//sort & return index
	template<typename T>
	vector<size_t> _sortIndexes(const vector<T> &v)
	{
		vector<size_t> idx(v.size());
		for (size_t i = 0; i != idx.size(); ++i)    idx[i] = i;

		sort(idx.begin(), idx.end(), [&v](size_t i1, size_t i2) {return v[i1]<v[i2]; });
		return idx;
	}
};