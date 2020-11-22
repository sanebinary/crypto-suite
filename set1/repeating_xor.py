def key_xor(input_bytes, key):
    output_bytes = b""
    key_index = 0
    for byte in input_bytes:
        if key_index < len(key):
            output_bytes += bytes([byte ^ key[key_index]])
            key_index += 1
        else:
            key_index = 0
    return output_bytes

def main():
    messages = open("crypto5_repeat.txt").read()
    messages = bytes(messages, 'utf-8')
    key = b"ICE"
    print(key_xor(messages, key).hex())

if __name__ == '__main__':
    main()