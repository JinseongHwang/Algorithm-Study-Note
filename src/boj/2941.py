import sys

input = sys.stdin.readline

substitute = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']

str = input().rstrip()
ans = 0

for sub in substitute:
	ans += str.count(sub)
	str = str.replace(sub, '#')

print(ans + len(str.replace('#', '')))