import sys

input = sys.stdin.readline

str = input().strip()
print(str.count(' ') + 1 if len(str) > 0 else 0)