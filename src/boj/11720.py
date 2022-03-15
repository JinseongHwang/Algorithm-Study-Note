import sys

input = sys.stdin.readline

ignored = input().rstrip()

nums = list(map(int, input().rstrip()))
print(sum(nums))
