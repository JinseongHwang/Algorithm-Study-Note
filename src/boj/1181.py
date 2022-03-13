import sys

input = sys.stdin.readline

N = int(input().rstrip())
words = set()
for _ in range(N):
	words.add(input().rstrip())

words = list(words)
words.sort(key=lambda word: (len(word), word))

for word in words:
	print(word)