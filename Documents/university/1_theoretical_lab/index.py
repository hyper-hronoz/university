import string 


def convert_base(number, to_base=10, from_base=10):
    if isinstance(number, str):
        number = int(number, from_base)
    else:
        number = int(number)

    alphabet = "".join(map(str, range(0, 10))) + string.ascii_uppercase

    if number < to_base:
        return alphabet[number]

    return convert_base(number // to_base, to_base) + alphabet[number % to_base]


def read_binary_numbers():
    with open("bin.txt", "r") as file:
        binary_numbers = list(map(lambda x: convert_base(x, 10, 2), file.readline().split()))
        print(binary_numbers)


def read_hex_numbers():
    with open("hex.txt", "r") as file:
        hex_numbers = list(map(lambda x: convert_base(x, 10, 16), file.readline().split()))
        print(hex_numbers)


read_binary_numbers()
read_hex_numbers()
