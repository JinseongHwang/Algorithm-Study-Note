def solution(phone_book):
	phone_book.sort()
	for i in range(0, len(phone_book) - 1):
		curr = phone_book[i]
		next = phone_book[i + 1]
		if next.startswith(curr):
			return False

	return True


if __name__ == '__main__':
	print(solution(["119", "97674223", "1195524421"]))  # false
	print(solution(["123", "456", "789"]))  # true
	print(solution(["12", "123", "1235", "567", "88"]))  # false
	print(solution(["1", "2", "3"]))  # true
	print(solution(["1", "12", "234", "123"]))  # false
	print(solution(["123", "345"]))  # true
	print(solution(["1", "2", "3", "34567890"]))  # false
	print(solution(["12345678901234567890", "12345678901234567891"]))  # true
	print(solution(["12345", "2345", "345", "45", "5"]))  # true
	print(solution(["12345", "1234", "123", "1", "12"]))  # false
	print(solution(["1"]))  # true
