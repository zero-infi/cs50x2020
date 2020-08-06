from cs50 import get_int


def main():
    height = check()
    for i in range(0, height):
        for k in range(height-1, i, -1):
            print(" ", end="")  # print empty space
        for j in range(0, i+1):
            print("#", end="")  # print '#'
        for z in range(2):
            print(" ", end="")
        for z in range(0, i+1):
            print("#", end="")

        print()


def check():
    height = get_int("Height : ")  # input height
    if height in range(1, 9):   # correct height
        return height
    else:
        return check()


main()