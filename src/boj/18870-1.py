import sys

input = sys.stdin.readline

N = input().rstrip()
nums = list(map(int, input().rstrip().split()))

sorted_nums = sorted(set(nums))

compressed_dict = {real_value : compressed for compressed, real_value in enumerate(sorted_nums)}

print(' '.join([str(compressed_dict[num]) for num in nums]))

