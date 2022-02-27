import collections


def solution(progresses, speeds):
	day = 0
	day_result = [0 for _ in range(len(progresses))]
	last_idx = -1
	while day_result[-1] == 0:  # 마지막 작업이 끝날 때까지 반복
		day += 1

		# 오늘의 작업을 진행
		sz = len(progresses)
		for i in range(last_idx + 1, sz):
			progresses[i] += speeds[i]

		# 작업이 완료 됐다면 배포 진행 및 정답 넣기
		for i in range(last_idx + 1, sz):
			if progresses[i] >= 100 and day_result[i] == 0:
				day_result[i] = day
				last_idx = i
			else:
				break

	return [v for k, v in collections.Counter(day_result).items()]


if __name__ == '__main__':
	print(solution([93, 30, 55], [1, 30, 5]))  # [2,1]
	print(solution([95, 90, 99, 99, 80, 99], [1, 1, 1, 1, 1, 1]))  # [1,3,2]
