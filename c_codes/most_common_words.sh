#!/bin/bash

# Call this script as, e.g., “./mostcommonwords.sh 1000 < file”
# bash ./most_common_words.sh 5 < shakespeare.txt

tr -cs A-Za-z '\n' |
tr A-Z a-z |
sort |
uniq -c |
sort -rn |
head -n $1
