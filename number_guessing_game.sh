#!/bin/bash

#this was the passing version of my number_guessing_game assignment

answer=5
#answer=$(( RANDOM % 10 + 1 ))
#answer=$((1 + $RANDOM % 10))
attempts=1
#echo "$answer"
echo "Welcome to the Number Guessing Game!"
#read -p "Guess the number (1-10) or enter '0' to quit: " guess
#echo -n "Guess the number (1-10) or enter '0' to quit: " guess

while true; do
    #echo -n "Guess the number (1-10) or enter '0' to quit: "
    read -p "Guess the number (1-10) or enter '0' to quit: " guess
    #read guess

        if [[ "$guess" -eq "0" ]]; then
            echo "Thanks for playing. Goodbye!"
            exit 0
        fi

        if [[ "$guess" -lt "$answer" ]]; then
            echo "Too low! Try again."
            #attempts=$((attempts + 1))
            ((attempts++))
        elif [[ "$guess" -gt "$answer" ]]; then
            echo "Too high! Try again."
            ((attempts++))
        elif [[ "$guess" -eq "$answer" ]]; then
                echo "Congratulations! You guessed the correct number in $attempts attempts."
                break
    fi
done