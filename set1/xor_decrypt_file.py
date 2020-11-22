def get_english_score(input_bytes):
    """Compares each input byte to a character frequency 
    chart and returns the score of a message based on the
    relative frequency the characters occur in the English
    language.
    """

    # From https://en.wikipedia.org/wiki/Letter_frequency
    # with the exception of ' ', which I estimated.
    character_frequencies = {
        'a': .08167, 'b': .01492, 'c': .02782, 'd': .04253,
        'e': .12702, 'f': .02228, 'g': .02015, 'h': .06094,
        'i': .06094, 'j': .00153, 'k': .00772, 'l': .04025,
        'm': .02406, 'n': .06749, 'o': .07507, 'p': .01929,
        'q': .00095, 'r': .05987, 's': .06327, 't': .09056,
        'u': .02758, 'v': .00978, 'w': .02360, 'x': .00150,
        'y': .01974, 'z': .00074, ' ': .13000
    }
    return sum([character_frequencies.get(chr(byte), 0) for byte in input_bytes.lower()])


def single_char_xor(input_bytes, char_value):
    """Returns the result of each byte being XOR'd with a single value.
    """
    output_bytes = b''
    for byte in input_bytes:
        output_bytes += bytes([byte ^ char_value])
    return output_bytes


def bruteforce_single_char_xor(ciphertext):
    """Performs a singlechar xor for each possible value(0,255), and
    assigns a score based on character frequency. Returns the result
    with the highest score.
    """
    potential_messages = []
    for key_value in range(256):
        message = single_char_xor(ciphertext, key_value)
        potential_messages.append(message)
    return potential_messages


def main():
    ciphers = open('crypto4.txt').read().splitlines()
    f = open("crypto4sol.txt", "a")
    potential_plaintext = []
    for hexstring in ciphers:
        ciphertext = bytes.fromhex(hexstring)
        potential_plaintext.append(bruteforce_single_char_xor(ciphertext))
    for plaintexts in potential_plaintext:
        for plaintext in plaintexts:
            f.write(str(plaintext) + "\n")
    f.close()

if __name__ == '__main__':
    main()