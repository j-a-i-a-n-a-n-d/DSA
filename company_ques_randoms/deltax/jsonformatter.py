'''

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

'''


def pretty_print(json):
    if not json:
        return ''

    result = []
    multiplier = 0
    i = 0

    while i < len(json):
        if json[i] in ['{', '[']:
            result.append('**' * multiplier + json[i])
            multiplier += 1
            i += 1
        elif json[i] in ['}', ']']:
            multiplier -= 1
            result.append('**' * multiplier + json[i])
            i += 1
        elif json[i] == ',':
            result[-1] += ','
            i += 1
        else:
            start = i
            while i < len(json) and json[i] not in ['{', '}', ',', '[', ']']:
                i += 1
            curr_s = json[start:i]
            result.append('**' * multiplier + curr_s)

    for r in result:
        print(r)


input = '{"id": "0001","type": "donut","name": "Cake","ppu": 0.55,"batters":{"batter":[{ "id": "1001", "type": "Regular" },{ "id": "1002", "type": "Chocolate" }]},"topping":[{ "id": "5001", "type": "None" },{ "id": "5002", "type": "Glazed" }]}'

pretty_print(input)
