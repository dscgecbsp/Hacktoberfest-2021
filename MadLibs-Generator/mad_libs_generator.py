import json

wrds = []

type_libs = {
    "1" : "adjective",
    "2" : "noun",
    "3" : "verb",
    "4" : "relative's name",
    "5" : "part of the body",
    "6" : "plural noun",
    "7" : "verb ending in 'ing'",
    "8" : "room in a house",
    "9" : "type of bird"
}

with open("stories.json",) as f:
    data = json.load(f)

story_num = input("Pick a story from 1 to 10")

story = (data["stories"])[story_num]
num_libs = (data["num_libs"])[story_num]

for i in story:
    if i.isdigit():
        wrds.append(input("Enter a " + type_libs[i]))


print(wrds)
