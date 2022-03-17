import sys

input = sys.stdin.readline

N = int(input().rstrip())

ans = 0
for _ in range(N):
	word = list(input().rstrip())

	# distinct & ordered
	for i in range(1, len(word)):
		if word[i - 1] == word[i]:
			word[i - 1] = '#'
	word = ''.join(word).replace('#', '')

	s = set()
	is_group_word = True
	for ch in word:
		if ch in s:
			is_group_word = False
			break
		else:
			s.add(ch)

	if is_group_word:
		ans += 1

print(ans)