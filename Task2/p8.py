# 8)	Write a code in Python to create a Morse code translator. You can take a string with alphanumeric cacters in lower or upper case. The string can also have any special cacters as a part of the Morse code. Special cacters can include commas, colons, apostrophes, exclamation marks, periods, and question marks. The code should return the Morse code that is equivalent to the string.

def morse(s):
    code = {
        'A': '.-', 'B': '-...', 'C': '-.-.', 'D': '-..', 'E': '.', 'F': '..-.', 'G': '--.', 'H': '....', 'I': '..', 'J': '.---',
        'K': '-.-', 'L': '.-..', 'M': '--', 'N': '-.', 'O': '---', 'P': '.--.', 'Q': '--.-', 'R': '.-.', 'S': '...', 'T': '-',
        'U': '..-', 'V': '...-', 'W': '.--', 'X': '-..-', 'Y': '-.--', 'Z': '--..',
        '0': '-----', '1': '.----', '2': '..---', '3': '...--', '4': '....-', '5': '.....',
        '6': '-....', '7': '--...', '8': '---..', '9': '----.',
        '.': '.-.-.-', ',': '--..--', ':': '---...', "'": '.----.', '!': '-.-.--', '?': '..--..'
    }
    
    res = ''
    for c in s:
        if c.upper() in code:
            res += code [c.upper()] + ' '
        else:
            res += c + ' '

    return res.strip()

str=input("Enter the string:")
morse_code = morse(str)
print(f"The Morse code for '{str}' is:")
print(morse_code)
