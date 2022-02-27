from typing import *


class Solution:
	def searchInsert(self, nums: List[int], target: int) -> int:
		L = 0
		R = len(nums) - 1

		while L <= R:
			mid = int((L + R) / 2)
			if nums[mid] == target:
				return mid
			elif nums[mid] < target:
				L = mid + 1
			else:
				R = mid - 1

		return L


if __name__ == '__main__':
	a = Solution()
	print(a.searchInsert([1, 3, 5, 6], 5))
	print(a.searchInsert([1, 3, 5, 6], 2))
	print(a.searchInsert([1, 3, 5, 6], 7))
