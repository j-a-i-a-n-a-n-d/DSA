def print_json(s):
    indent = 0
    curr_line = ''
    for char in s:
        if char == ',':
            print(' '*indent + curr_line + char)
            curr_line = ''
        elif char == '[' or char == '{':
            if curr_line != '':
                print(indent*' ' + curr_line)
                curr_line = ''
            print(indent*' ' + char)
            indent += 4
        elif char == ']' or char == '}':
            if curr_line != '':
                print(indent*' ' + curr_line)
                curr_line = ''
            indent -= 4
            print(indent*' ' + char)
        else:
            curr_line += char


s = input()
print_json(s)
