import collections


def solution(maps):
	R = len(maps)
	C = len(maps[0])
	dr = [-1, 1, 0, 0]
	dc = [0, 0, -1, 1]
	visit = [[False] * C for _ in range(R)]

	# BFS
	q = collections.deque()
	start = (0, 0)
	q.append(start)
	visit[start[0]][start[1]] = True
	while len(q) > 0:
		curr = q.popleft()

		for i in range(4):
			next = (curr[0] + dr[i], curr[1] + dc[i])

			# 범위 벗어났거나
			if next[0] < 0 or next[0] >= R or next[1] < 0 or next[1] >= C:
				continue
			# 이미 방문했거나
			if visit[next[0]][next[1]] is True:
				continue
			# 벽이거나
			if maps[next[0]][next[1]] == 0:
				continue
			visit[next[0]][next[1]] = True
			if maps[next[0]][next[1]] != 1:
				maps[next[0]][next[1]] = min(maps[next[0]][next[1]], maps[curr[0]][curr[1]] + 1)
			else:
				maps[next[0]][next[1]] = maps[curr[0]][curr[1]] + 1

			q.append(next)

	return maps[R - 1][C - 1] if maps[R - 1][C - 1] != 1 else -1


if __name__ == '__main__':
	maps = [[1, 0, 1, 1, 1],
			[1, 0, 1, 0, 1],
			[1, 0, 1, 1, 1],
			[1, 1, 1, 0, 1],
			[0, 0, 0, 0, 1]]
	print(solution(maps))
