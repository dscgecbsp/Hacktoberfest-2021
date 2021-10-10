import json

# creating a dictionary to inform user of type of words to be entered as numbers(keys) correspond in stories
type_of_words = {
    "1": "adjective",
    "2": "noun",
    "3": "verb",
    "4": "relative's name",
    "5": "part of the body",
    "6": "plural noun",
    "7": "verb ending in 'ing'",
    "8": "room in a house",
    "9": "type of bird"
}

input_words = []

# saving the stories and related information in a separate variable
f = open("MadLibs-Generator/stories.json", "r")
data = json.loads(f.read())
f.close()

# asking user's choice of story
story_num = input("Pick a story from 1 to 5: ")

story = (data["stories"])[story_num]

# loop over the story to take user input for words
for i in story:
    if i.isdigit():
        input_words.append(input("Enter a " + type_of_words[i] + ": "))

# introducing count variable to access words from "input_words" list
count = 0
# loop to print the story in the console
for i in story:
    if i.isdigit():
        print(input_words[count], end='')
        count += 1
        continue
    print(i, end='')
