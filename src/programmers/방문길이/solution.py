def solution(dirs):
	s = set()
	curr = [0, 0]  # current point
	for dir in dirs:
		if dir == 'U':
			if is_ignored([curr[0], curr[1] + 1]): continue
			s.add(to_string([curr[0], curr[1], curr[0], curr[1] + 1]))
			s.add(to_string([curr[0], curr[1] + 1, curr[0], curr[1]]))
			curr[1] += 1
		elif dir == 'D':
			if is_ignored([curr[0], curr[1] - 1]): continue
			s.add(to_string([curr[0], curr[1], curr[0], curr[1] - 1]))
			s.add(to_string([curr[0], curr[1] - 1, curr[0], curr[1]]))
			curr[1] -= 1
		elif dir == 'L':
			if is_ignored([curr[0] - 1, curr[1]]): continue
			s.add(to_string([curr[0], curr[1], curr[0] - 1, curr[1]]))
			s.add(to_string([curr[0] - 1, curr[1], curr[0], curr[1]]))
			curr[0] -= 1
		elif dir == 'R':
			if is_ignored([curr[0] + 1, curr[1]]): continue
			s.add(to_string([curr[0], curr[1], curr[0] + 1, curr[1]]))
			s.add(to_string([curr[0] + 1, curr[1], curr[0], curr[1]]))
			curr[0] += 1

	return len(s) // 2


def is_ignored(nxt):
	return abs(nxt[0]) > 5 or abs(nxt[1]) > 5


def to_string(ls):
	return f'{ls[0]},{ls[1]},{ls[2]},{ls[3]}'


if __name__ == '__main__':
	print(solution("ULURRDLLU"))
	print(solution("LULLLLLLU"))
