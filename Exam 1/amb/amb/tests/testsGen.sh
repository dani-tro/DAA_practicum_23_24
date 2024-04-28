#!/bin/bash

author="author"
task_name="amb"

g++ -o author author.cpp

files=$(find . -name "${task_name}.??.in")

echo $files

for input_file in $files; do
    echo $input_file
    file_number=$(basename "$input_file" | sed -e "s/${task_name}\.\(.*\)\.in/\1/")
    solution_file="${task_name}.${file_number}.out"
    ./author < "$input_file" > "$solution_file"
    echo "Created solution file: $solution_file"
done
