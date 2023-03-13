def isUniqueChars(st):

    # String length cannot be more than
    # 256.
    if len(st) > 256:
        return False

    # Initialize occurrences of all characters
    char_set = [False] * 128

    # For every character, check if it exists
    # in char_set
    for i in range(0, len(st)):

        # Find ASCII value and check if it
        # exists in set.
        val = ord(st[i])
        if char_set[val]:
            return False

        char_set[val] = True

    return True


def backtrack_strings(strings, n):
    res = set()
    m = len(strings)

    def backtrack(path):
        if len(path) == n:
            if isUniqueChars(path):
                res.add(''.join(path))
            return

        k = len(path)
        if k >= m:
            return

        for char in strings[k]:
            path.append(char)
            backtrack(path)
            path.pop()

    backtrack([])
    return list(res)


print(backtrack_strings(["abc", "def"], 2))
