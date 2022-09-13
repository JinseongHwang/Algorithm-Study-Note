import collections


def solution(input, output):
    users = []
    dups = collections.defaultdict(int)
    n = input.readline().rstrip()
    fname_max_len = 0

    for line in input.readlines():
        line = line.rstrip().split()
        users.append((line[0], line[1], line[2]))
        dups[line[2]] += 1
        fname_max_len = max(fname_max_len, len(line[1]))

    users.sort(key=lambda x: x[0])
    dups_items = dups.items()
    dups_items = list(filter(lambda kv: kv[1] > 1, dups_items))
    dups_items.sort(key=lambda kv: kv[0])

    for user in users:
        output.write(f'{user[0]} {user[1]}{" " * (fname_max_len - len(user[1]))} {user[2]}\n')

    if len(dups_items) > 0:
        output.write('\n')
        for item in dups_items:
            output.write(f'{item[0]} {item[1]}\n')


def application(profile, pnum, pname, test_input=1):
    input_file = None
    output_file = None

    if profile == 'test':
        input_file = open(f'./data/{pnum}/sampleData{pnum}/{test_input}.inp', 'r')
        output_file = open(f'./data/{pnum}/sampleData{pnum}/{pname}.out', 'w')
    elif profile == 'submit':
        input_file = open(f'{pname}.inp', 'r')
        output_file = open(f'{pname}.out', 'w')
    else:
        raise Exception(f'\'{profile}\' is unknown profile. please check again.')

    solution(input_file, output_file)

    input_file.close()
    output_file.close()


if __name__ == '__main__':
    # profile = 'test' || 'submit'
    profile = 'test'
    test_input = 2
    problem_number = 1
    problem_name = 'test'
    application(profile, problem_number, problem_name, test_input)
