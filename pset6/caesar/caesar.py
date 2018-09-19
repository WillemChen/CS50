from cs50 import get_string
import sys

if len(sys.argv) != 2:
    print("Usage: ./caesar k")
    exit(1)

# get the key
key = int(sys.argv[1])

# get the plain_text
plain_str = get_string("plain text: ")
cipher_str = ""

# encipher the text
for j in range(len(plain_str)):
    if plain_str[j].isalpha():
        if plain_str[j].isupper():
            aphi = int(ord(plain_str[j])) - 65
            aphi = (aphi + key) % 26 + 65
        if plain_str[j].islower():
            aphi = int(ord(plain_str[j])) - 97
            aphi = (aphi + key) % 26 + 97
        cipher_str = cipher_str + chr(aphi)
    else:
        cipher_str = cipher_str + plain_str[j]

# print the ciphertext
print(f"ciphertext: {cipher_str}")