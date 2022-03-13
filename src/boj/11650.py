import sys

input = sys.stdin.readline

N = int(input())
coords = []
for _ in range(N):
	X, Y = map(int, input().split())
	coords.append({'x': X, 'y': Y})

coords.sort(key=lambda coord: (coord['x'], coord['y']))

for coord in coords:
	print(f'{coord["x"]} {coord["y"]}')
