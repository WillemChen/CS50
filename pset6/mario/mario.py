from cs50 import get_int

# promt and validate user input
while True:
    height = get_int("Height: ")
    if height > 0 and height < 23:
        break

# draw the pyramid
for i in range(height):

    # draw left spaces
    print(" " * (height - i), end="")

    # draw left #
    print("#" * (i + 1), end="")

    # draw mid space
    print("  ", end="")

    # draw right space
    print("#" * (i + 1), end="")

    # draw new line
    print()
