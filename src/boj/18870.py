import sys

input = sys.stdin.readline

N = int(input())
inps = list(map(int, input().split()))
nums = []
for idx, inp in enumerate(inps):
	nums.append({
		'order': idx,
		'value': inp,
		'compressed': -1
	})

nums.sort(key=lambda num: num['value'])

compressed = 1
nums[0]['compressed'] = 0
for i in range(1, len(nums)):
	if nums[i - 1]['value'] == nums[i]['value']:
		nums[i]['compressed'] = nums[i - 1]['compressed']
	else:
		nums[i]['compressed'] = compressed
		compressed += 1

nums.sort(key=lambda num: num['order'])

for num in nums:
	print(num['compressed'], end=' ')
