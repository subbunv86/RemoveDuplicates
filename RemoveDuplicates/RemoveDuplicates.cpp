// RemoveDuplicates.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int nSize = nums.size();
		if (nSize <= 1)
			return nSize;
		int i = 0, j = 1, nCount = 0;

		while (j < nums.size())
		{
			if ((nums[i] == nums[j]))
			{
				if (nCount == 0)
				{
					nums[nCount] = nums[i];
					nums[++nCount] = nums[j];
				}
				else if(nums[nCount]!=nums[i])
				{
					nums[++nCount] = nums[i];
					nums[++nCount] = nums[j];
				}
				i++; 
				j++; 
			}
			else 
			{
				if (nums[nCount] != nums[i])
				{
					nums[++nCount] = nums[i];
					//i++;
				}
				if (nums[nCount] != nums[j])
				{
					nums[++nCount] = nums[j];
					//j++;
				}
				i++;
				j++;
			}
			
			
		}
		if ((nums[nCount] != nums[j - 1]) && (nums[nCount - 1] != nums[j - 1]))
			nums[++nCount] = nums[j];
		return nCount;
	}
	
};

int main()
{
	vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(1);
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(2);
	numbers.push_back(3);
	//numbers.push_back(2);
	//numbers.push_back(3);
	//numbers.push_back(3);
	Solution slns;
	int nSize = slns.removeDuplicates(numbers);
	for (int i = 0; i < nSize+1; i++)
		cout << numbers[i] << endl;
    return 0;
}

