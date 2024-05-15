def decode_string(s, i):
    result = []

    while i < len(s) and s[i] != ']':
        if not s[i].isdigit():
            result.append(s[i])
            i += 1
        else:
            count = 0
            while i < len(s) and s[i].isdigit():
                count = count * 10 + int(s[i])
                i += 1

            # Skip '['
            i += 1
            decoded_string, i = decode_string(s, i)

            # Skip ']'
            i += 1

            result.append(decoded_string * count)

    return ''.join(result), i

def decode_string_main(s):
    result, _ = decode_string(s, 0)
    return result

if __name__ == "__main__":
    s = "3[a]2[bc]"
    print(decode_string_main(s))

    s = "3[a2[c]]"
    print(decode_string_main(s))

    s = "2[abc]3[cd]ef"
    print(decode_string_main(s))
