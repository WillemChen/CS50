import sys
from cs50 import get_string

if len(sys.argv) != 2:
    print("Usage: ./vigenere k")
    exit(1)

# get cipher word
key = sys.argv[1]
base = ""

# transfer cipher word to the base
for i in range(len(key)):
    if key[i].isupper():
        base = base + chr(ord(key[i]) - 64)
    elif key[i].islower():
        base = base + chr(ord(key[i]) - 96)
    else:
        print("Usage: ./vigenere k")
        exit(1)

p_str = get_string("plaintext: ")
cipher_text = ""
# A:65 Z:90 a:97 z:122
counter = 0
for j in range(len(p_str)):
    if p_str[j].isupper():
        tmp = chr((ord(p_str[j]) - 65 + ord(base[counter % len(key)]) - 1) % 26 + 65)
    elif p_str[j].islower():
        tmp = chr((ord(p_str[j]) - 97 + ord(base[counter % len(key)]) - 1) % 26 + 97)
    else:
        tmp = p_str[j]
        counter = counter - 1
    cipher_text = cipher_text + tmp
    counter = counter + 1
print(f"ciphertext: {cipher_text}")