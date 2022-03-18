result = 0
N = int(input().rstrip())
for _ in range(N):
	word = input().rstrip()
	if list(word) == sorted(word, key=word.find):
		result += 1

print(result)
