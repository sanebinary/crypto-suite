from Crypto.Cipher import AES
import base64
def main():
    key = "YELLOW SUBMARINE"
    with open('7.txt') as input_file:
        ciphertext = base64.b64decode(input_file.read())
    plaintext = aes_ecb_decrypt(ciphertext, key)
    print(plaintext)

def aes_ecb_decrypt(ciphertext, key):
    obj = AES.new(key, AES.MODE_ECB)
    plaintext = obj.decrypt(ciphertext)
    return plaintext

if __name__ == '__main__':
    main()