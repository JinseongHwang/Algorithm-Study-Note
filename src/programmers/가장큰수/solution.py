def solution(numbers):
	numbers = list(map(lambda number: str(number) * 3, numbers))
	# 333 303030 343434 555 999
	numbers.sort(reverse=True)
	# 999 555 343434 333 303030
	numbers = list(map(lambda number: number[:len(number) // 3], numbers))
	# 9 5 34 3 30
	return ''.join(numbers) if sum(map(int, numbers)) != 0 else '0'


if __name__ == '__main__':
	print(solution([6, 10, 2]))
	print(solution([3, 30, 34, 5, 9]))
	print(solution([1, 23, 456]))
	print(solution([0, 0, 0]))
	print(solution([12345]))
	print(solution([0, 1]))
	print(solution([0, 1, 2, 3, 4, 5, 6, 7, 8, 9]))
	print(solution([12, 6, 7834, 890, 90, 236, 78, 9]))
	print(solution([9, 990, 989]))
	print(solution([989, 98]))  # 989 98
	print(solution([980, 98]))  # 98 980
	print(solution([110, 11]))  # 11 110
	print(solution([119, 11]))  # 119 11
	print(solution([189, 18]))  # 189 18
	print(solution([989, 9]))  # 9 989
