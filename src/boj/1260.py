import collections
import sys

input = sys.stdin.readline


def dfs(curr):
	print(curr + 1, end=' ')
	visited[curr] = True
	for n in range(N):
		if visited[n] is False and graph[curr][n] is True:
			dfs(n)


def bfs(curr):
	queue = collections.deque()
	queue.append(curr)
	visited[curr] = True
	while queue:
		curr = queue.popleft()
		print(curr + 1, end=' ')
		for n in range(N):
			if visited[n] is False and graph[curr][n] is True:
				queue.append(n)
				visited[n] = True


N, M, V = map(int, input().split())
V -= 1
graph = [[False] * N for _ in range(N)]
visited = [False] * N

for _ in range(M):
	frm, to = map(int, input().split())
	frm -= 1
	to -= 1
	graph[frm][to] = graph[to][frm] = True

dfs(V)
visited = [False] * N
print()
bfs(V)
