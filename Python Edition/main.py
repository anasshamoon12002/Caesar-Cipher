
def encrypt():
    encrypted_msg = []

    message = input("\nEnter a sentence: ", )

    while True:

        key = int(input("Enter the key: ", ))

        if key < 1 or key > 25:
            print("\nPlease enter a valid key...!!!")

        else:
            break

    print("\nENCRYPTION PASS...\n")

    for i in range(len(message)):

        if ord(message[i]) >= ord('A') and ord(message[i]) <= ord('Z'):

            temp = chr(ord(message[i]) + key)

            if ord(temp) > ord('Z'):
                temp = chr(ord(temp) - 26)

            encrypted_msg.append(temp)

        elif ord(message[i]) >= ord('a') and ord(message[i]) <= ord('z'):

            temp = chr(ord(message[i]) + key)

            if ord(temp) > ord('z'):
                temp = chr(ord(temp) - 26)

            encrypted_msg.append(temp)

        else:

            encrypted_msg.append(message[i])

    print("".join(encrypted_msg))


def decrypt():

    encrypted_msg = input("\nEnter the string to be decrypted: ")

    while True:

        key = int(input("Enter the key: ", ))

        if key < 1 or key > 25:
            print("\nPlease enter a valid key...!!!\n")

        else:
            break

    print("\nDECRYPTION PASS...\n")

    decrypted_msg = []

    for i in range(len(encrypted_msg)):

        if ord(encrypted_msg[i]) >= ord('A') and ord(encrypted_msg[i]) <= ord('Z'):

            temp = chr(ord(encrypted_msg[i]) - key)

            if ord(temp) < ord('A'):
                temp = chr(ord(temp) + 26)

            decrypted_msg.append(temp)

        elif ord(encrypted_msg[i]) >= ord('a') and ord(encrypted_msg[i]) <= ord('z'):

            temp = chr(ord(encrypted_msg[i]) - key)

            if ord(temp) < ord('a'):
                temp = chr(ord(temp) + 26)

            decrypted_msg.append(temp)

        else:

            decrypted_msg.append(encrypted_msg[i])

    print("".join(decrypted_msg))


# Main Runner Program Ahead #


print("Ceasar Cipher\n")

while (True):

    print("\nSelect an option from the following.")

    print("1. Encrypt    2. Decrypt    3. Exit")

    choice = int(input())

    if choice < 1 or choice > 3:
        print("Select a valid option...!!!")

    elif choice == 1:
      encrypt()

    elif choice == 2:
        decrypt()

    else:
        break
