import sys

input = sys.stdin.readline

N = int(input().rstrip())
users = []
for order in range(N):
	inp = input().rstrip().split()
	users.append({
		'order': order,
		'age': int(inp[0]),
		'name': inp[1]
	})

users.sort(key=lambda user: (user['age'], user['order']))

for user in users:
	print(f'{user["age"]} {user["name"]}')
