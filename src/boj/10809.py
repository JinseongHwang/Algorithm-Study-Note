import collections
import sys

input = sys.stdin.readline

str = input().rstrip()
data = collections.defaultdict(lambda: -1)
for idx, ch in enumerate(str):
	if data[ch] == -1:
		data[ch] = idx

for o in range(ord('a'), ord('z') + 1):
	print(data[chr(o)], end=' ')
