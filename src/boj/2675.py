import sys

input = sys.stdin.readline

tc = int(input().rstrip())

for _ in range(tc):
	inp = input().rstrip().split()
	reps = int(inp[0])
	res = ''
	for ch in inp[1]:
		res += ch * reps
	print(res)