# Python3 code to demonstrate working of
# Words Frequency in String Shorthands
# Using dictionary comprehension + count() + split()

# Initializing string
test_str = 'Gfg is best . Geeks are good and Geeks like Gfg'

# Printing original string
print("The original string is : " + str(test_str))

# Words Frequency in String Shorthands
# Using dictionary comprehension + count() + split()
res = {key: test_str.count(key) for key in test_str.split()}

# Printing result
print("The words frequency : " + str(res))
