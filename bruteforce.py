'''
THIS CODE BRUTEFORCES WORD FROM GIVEN CHARACTERS LIST.
IT WORKS IN A WAY SIMILAR TO HOW A MECHANICAL COUNTER DOES
'''


lPossibleChars = ("a", "b", "c", "d", "e", "f")
sWord = ""
sFileName = "words.txt"
lGenWords = []
dWordsForSave = 100

def bruteforce(index):
    global sWord, lPossibleChars

    #generates only if the index to change is less than currrent word length
    if index < len(sWord):
        for i in range(len(lPossibleChars)):

            #makes the word a list
            lWord = list(sWord)
            #changes the index
            lWord[index] = lPossibleChars[i]
            #makes the list back a word
            sWord = ''.join(lWord)

            print(sWord)
            #adds to the list
            lGenWords.append(sWord)

            #goes on for the next index
            bruteforce(index + 1)


while True:
    #saves word on file (append mode) and cleares the list
    if len(lGenWords) >= dWordsForSave:
        f = open(sFileName, "a")

        for s in lGenWords:
            f.write(s + "\n")

        lGenWords[:] = []
        f.close()

    #starts bruteforcing the word and adds a new character when ended
    if len(sWord) > 0:
        bruteforce(0)
    sWord += lPossibleChars[0]
