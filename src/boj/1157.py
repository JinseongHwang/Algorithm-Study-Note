import collections
import sys

input = sys.stdin.readline
str = input().rstrip()

res = collections.Counter(list(str.upper())).most_common()
if len(res) == 1:
	print(res[0][0])
else:
	if res[0][1] == res[1][1]:
		print('?')
	else:
		print(res[0][0])