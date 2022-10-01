#!/bin/bash

grn=$'\e[1;32m'
red=$'\e[1;31m'
yel=$'\e[0;33m'
white=$'\033[37m'

test=("first_word" "fizzbuzz" "ft_putstr" "ft_strcpy" "ft_strlen" "ft_swap" "repeat_alpha" "rev_print" "rot_13" "rotone" "search_and_replace" "ulstr")
f_w=("FOR PONY" "this        ...    is sparta, then again, maybe    not" "   " "  lorem,ipsum  ")

for str in ${test[@]}; do
	echo ${white}"-------	"$str" -------"
	if test -f "$(pwd)/.rendu/$str.c"; then
		cc $(pwd)/.expected/$str.c -o $str
		cc $(pwd)/.rendu/$str.c -o student$str
		if [ $str == "first_word" ]; then
			for test in ${f_w[@]}; do
				if ! diff --brief <(./$str $test) <(./student$str $test); then
					echo -ne "${red}KO "
				else
					echo -ne "${grn}OK "
				fi
			done
		else
			if ! diff --brief <(./$str) <(./student$str); then
				echo -ne "${red}1. KO${yel}"
			else
				echo -ne "${grn}1. OK${yel}"
			fi
		fi
		rm -r *$str
	else
		echo ${red}"File not found skipping"
	fi
	echo ""
done

# myfirstword=$(pwd)/.expected/1.c
# myfizzbuzz=$(pwd)/.expected/2.c

# fizzbuzz=$(pwd)/.rendu/fizzbuzz.c
# first_word=$(pwd)/.rendu/first_word.c

# echo ${white}"--------------- First_Word --------------"
# if test -f "$first_word"; then
# 	cc $myfirstword -o myfizzbuzz
# 	cc $first_word -o notmyfizzbuzz
# 	myfizzbuzztest=$(pwd)/./myfizzbuzz
# 	notmyfizzbuzztest=$(pwd)/./notmyfizzbuzz
# 	if ! diff --brief <("$myfizzbuzztest") <("$notmyfizzbuzztest"); then # The output is different
# 		echo -n "${red}$i. KO${yel}"
# 	else
# 		echo -n "${grn}$i. OK${yel}"
# 	fi
# else
# 	echo ${red}"File not found skipping test"
# fi
# echo ""
# echo ${white}"--------------- FizzBuzz --------------"
# if test -f "$fizzbuzz"; then
# 	cc $myfizzbuzz -o myfizzbuzz
# 	cc $fizzbuzz -o notmyfizzbuzz
# 	myfizzbuzztest=$(pwd)/./myfizzbuzz
# 	notmyfizzbuzztest=$(pwd)/./notmyfizzbuzz
# 	if ! diff --brief <("$myfizzbuzztest") <("$notmyfizzbuzztest"); then # The output is different
# 		echo -ne "${red}$i. KO${yel}"
# 	else
# 		echo -ne "${grn}$i. OK${yel}"
# 	fi
# 	rm -r $myfizzbuzztest
# 	rm -r $notmyfizzbuzztest
# else
# 	echo ${red}"File not found skipping test"
# fi
