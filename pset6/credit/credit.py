from cs50 import get_int

# prompt for user input
while True:
    credit_num = get_int("number: ")
    if credit_num > 0:
        break

# multipy every other digit
digit = credit_num
check_sum = 0
while True:
    # add odd digit
    check_sum = check_sum + (digit % 10)
    digit = digit // 10
    # add even digit times two
    tmp = (digit % 10) * 2
    check_sum = check_sum + (tmp % 10) + (tmp // 10) * 1
    digit = digit // 10
    if digit == 0:
        break

# validate check sum
digit = 0
if (check_sum % 10) == 0:
    while credit_num > 100:
        # compute the digit number of credit
        credit_num = credit_num // 10
        digit = digit + 1
    digit = digit + 2

    if digit == 13:
        if credit_num // 10 == 4:
            print("VISA")
    elif digit == 15:
        if credit_num == 34 or credit_num == 37:
            print("AMEX")
    elif digit == 16:
        if credit_num // 10 == 4:
            print("VISA")
        elif credit_num % 10 < 6 and credit_num % 10 > 0:
            print("MASTERCARD")
    else:
        print("INVALID")
else:
    print("INVALID")