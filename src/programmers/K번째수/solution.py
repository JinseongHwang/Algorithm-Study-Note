def solution(array, commands):
	answer = []

	for command in commands:
		L, R, K = command
		temp_array = sorted(array[L - 1:R])
		answer.append(temp_array[K - 1])

	return answer
