//Runtime: 4 ms, faster than 73.84% of Bash online submissions for Valid Phone Numbers.
//Memory Usage: 3.1 MB, less than 45.44% of Bash online submissions for Valid Phone Numbers.

# Read from the file file.txt and output all valid phone numbers to stdout.
egrep '^(([[:digit:]]{3}-)|(\([[:digit:]]{3}\)\ ))[[:digit:]]{3}-[[:digit:]]{4}$' file.txt
