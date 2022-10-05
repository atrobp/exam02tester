#!/bin/bash

grn=$'\e[1;32m'
red=$'\e[1;31m'
yel=$'\e[0;33m'
white=$'\033[37m'
grnbgrd=$'\e[1;33m'
black=$'\e[1;40m'

lvl0=("first_word" "fizzbuzz" "ft_putstr" "ft_strcpy" "ft_strlen" "ft_swap" "repeat_alpha" "rev_print" "rot_13" "rotone" "search_and_replace" "ulstr")
lvl1=("alpha_mirror" "camel_to_snake" "do_op" "ft_atoi" "ft_strcmp" "ft_strcspn" "ft_strdup" "ft_strpbrk" "ft_strrev" "ft_strspn" "inter" "is_power_of_2" "last_word" "max" "print_bits" "reverse_bits" "snake_to_camel" "swap_bits" "union" "wdmatch")
lvl2=("add_prime_sum" "epur_str" "expand_str" "ft_atoi_base" "ft_list_size" "ft_range" "ft_rrange" "hidenp" "lcm" "paramsum" "pgcd" "print_hex" "rstr_capitalizer" "str_capitalizer" "tab_mult")
lvl3=("flood_fil" "fprime" "ft_itoa" "ft_list_foreach" "ft_list_remove_if" "ft_split" "rev_wstr" "rotstring" "sort_int_tab" "sort_list")
# declare -a str=("   test" "42")
# str=("abc" "FOR PONY" "this        ...    is sparta, then again, maybe    not" "   " "  lorem,ipsum  " "" "		this is a very very very very v..ve..very long string or is it?")
str=("abc" "FOR PONY" "this	 is	 sparta 	" "	  	loremm,ipsum	 	 " "42   			")
lvl1test=("abc" "My horse is Amazing" "Hello World" "	 42		 ")

for i in {0..3}; do
	echo "${grnbgrd}-------- LEVEL | $i --------"${white}
	# echo ${white} "${grn}----------${white}LEVEL | $i ${red}---------"
	if test -d "./rendu/level$i"; then
		if [ $i == 0 ]; then
			for exo in ${lvl0[@]}; do
				echo "${white}$exo"
				if test -f "./rendu/level$i/$exo.c"; then
					if [ $exo == "first_word" ]; then
						cc ./expected/lvl0/$exo.c -o $exo
						cc ./rendu/level0/$exo.c -o student$exo
						if ! diff -q <(./$exo) <(./student$exo) >> output.txt; then
								echo -ne "${red}KO "
							else
								echo -ne "${grn}OK "
							fi
						for test in "${str[@]}"; do
							if ! diff -q <(./$exo "$test") <(./student$exo "$test") >> output.txt; then
								echo -ne "${red}KO "
							else
								echo -ne "${grn}OK "
							fi
						done
					elif [ $exo == "fizzbuzz" ]; then
						cc ./expected/lvl0/$exo.c -o $exo
						cc ./rendu/level0/$exo.c -o student$exo
						if ! diff <(./$exo ) <(./student$exo) >> output.txt; then
							echo -ne "${red}KO "
						else
							echo -ne "${grn}OK "
						fi
					elif [ $exo == "ft_putstr" ] || [ $exo == "ft_strcpy" ] || [ $exo == "ft_strlen" ] || [ $exo == "ft_swap" ]; then
						cc ./expected/lvl0/main.c ./expected/lvl0/$exo.c $(find ./expected/lvl0 -type f -name "ft_*.c" ! -name $exo.c) -o $exo
						cc ./expected/lvl0/main.c ./rendu/level0/$exo.c $(find ./expected/lvl0 -type f -name "ft_*.c" ! -name $exo.c) -o student$exo
						if [ $exo == "ft_swap" ]; then
							for test in {0..4}; do
							a=$RANDOM
							b=$RANDOM
							if ! diff -q <(./$exo "$exo" "$a" "$b") <(./student$exo "$exo" "$a" "$b" ) >> output.txt; then
									echo -ne "${red}KO "
								else
									echo -ne "${grn}OK "
								fi
						done
						else
							for test in "${str[@]}"; do
									if ! diff -q <(./$exo "$exo" "$test") <(./student$exo "$exo" "$test") >> output.txt; then
										echo -ne "${red}KO "
									else
										echo -ne "${grn}OK "
									fi
							done
						fi
					else
						cc ./expected/lvl0/$exo.c -o $exo
						cc ./rendu/level0/$exo.c -o student$exo
						if ! diff -q <(./$exo) <(./student$exo) >> output.txt; then
							echo -ne "${red}KO "
						else
							echo -ne "${grn}OK "
						fi
						if [ $exo == "search_and_replace" ]; then
							if ! diff -q <(./$exo "change meee not" "e" "ii") <(./student$exo "change meee not" "e" "ii") >> output.txt; then
								echo -ne "${red}KO "
							else
								echo -ne "${grn}OK "
							fi
							for test in "octopus" "programmeur42" "woo00oow" "looks good 2 me"; do
								achar=$(( $RANDOM % 100 + 33 ))
								if ! diff -q <(./$exo "$test" "o" "$achar") <(./student$exo "$test" "o" "$achar") >> output.txt; then
									echo -ne "${red}KO "
								else
									echo -ne "${grn}OK "
								fi
							done
						else
							for test in "spartaaa!!" "banane" "42" "I enjoy coding ?" "zA"; do
								if ! diff -q <(./$exo "$test") <(./student$exo "$test") >> output.txt; then
									echo -ne "${red}KO "
								else
									echo -ne "${grn}OK "
								fi
							done
						fi
					fi
					echo ""
					rm -r *$exo
				else
					echo "${red}$exo.c not found"
				fi
			sleep 1
			done
		elif [ $i == 1 ]; then
			for exo in ${lvl1[@]}; do
				echo "${white}$exo"
				if test -f "./rendu/level$i/$exo.c"; then
					if [ $exo == "alpha_mirror" ] || [ $exo == "last_word" ]; then
						cc ./expected/lvl$i/$exo.c -o $exo
						cc ./rendu/level$i/$exo.c -o student$exo
						if ! diff -q <(./$exo) <(./student$exo) >> output.txt; then
								echo -ne "${red}KO "
							else
								echo -ne "${grn}OK "
							fi
						for test in "${str[@]}" "${lvl1test[@]}"; do
							if ! diff -q <(./$exo "$test") <(./student$exo "$test") >> output.txt; then
								echo -ne "${red}KO "
							else
								echo -ne "${grn}OK "
							fi
						done
					elif [ $exo == "inter" ] || [ $exo == "union" ] || [ $exo == "wdmatch" ]; then
						cc ./expected/lvl$i/$exo.c -o $exo
						cc ./rendu/level$i/$exo.c -o student$exo
						if ! diff -q <(./$exo) <(./student$exo) >> output.txt; then
								echo -ne "${red}KO "
							else
								echo -ne "${grn}OK "
							fi
						for test in "paqefwtdjetyiytjneytjoeyjnejeyj" "gtwthgdwthdwfteewhrtag6h4ffdhsd" "cette phrase ne cache rien"; do
							if ! diff -q <(./$exo "padinton" "$test") <(./student$exo "padinton" "$test") >> output.txt; then
								echo -ne "${red}KO "
							else
								echo -ne "${grn}OK "
							fi
							if ! diff -q <(./$exo "ddf6vewg64f" "$test") <(./student$exo "ddf6vewg64f" "$test") >> output.txt; then
								echo -ne "${red}KO "
							else
								echo -ne "${grn}OK "
							fi
							if ! diff -q <(./$exo "rien" "$test") <(./student$exo "rien" "$test") >> output.txt; then
								echo -ne "${red}KO "
							else
								echo -ne "${grn}OK "
							fi
						done
					elif [ $exo == "max" ]; then
						cc ./expected/lvl1/main.c ./expected/lvl1/$exo.c -o $exo
						cc ./expected/lvl1/main.c ./rendu/level1/$exo.c -o student$exo
						if ! diff -q <(./$exo "NULL") <(./student$exo "NULL") >> output.txt; then
								echo -ne "${red}KO "
							else
								echo -ne "${grn}OK "
							fi
						if ! diff -q <(./$exo "5" "1" "0" "42") <(./student$exo "5" "1" "0" "42") >> output.txt; then
								echo -ne "${red}KO "
							else
								echo -ne "${grn}OK "
							fi
					fi
					echo ""
					rm -r *$exo
				else
					echo "${red}$exo.c not found"
				fi
				sleep 1
			done
		elif [ $i == 2 ]; then
			for exo in ${lvl2[@]}; do
				echo "$exo"
			done
		elif [ $i == 3 ]; then
			for exo in ${lvl3[@]}; do
				echo "$exo"
			done
		else
			for exo in ${lvl3[@]}; do
				echo "$exo"
			done
		fi
	else
		echo "${red}path of rendu/level$i not found"
	fi
	if test -f "./output.txt"; then
		rm -r ./output.txt
	fi
	sleep 0.4
done

# for lvl in {0..4};do
# 	echo ${white} "${grn}-----		${white}LEVEL|$lvl ${red}		-----"
# 	for str in ${test[@]}; do
# 		echo ${white}"-------	"$str" -------"
# 		if test -f "./rendu/$str.c"; then
# 			if [ $str == "first_word" ]; then
# 				cc $(pwd)/expected/$str.c -o $str
# 				cc $(pwd)/rendu/$str.c -o student$str
# 					for test in ${f_w[@]}; do
# 						if ! diff -q <(./$str $test) <(./student$str $test) >> output.txt; then
# 							echo -ne "${red}KO "
# 						else
# 							echo -ne "${grn}OK "
# 						fi
# 					done
# 			fi
# 			if [ $str == "fizzbuzz" ]; then
# 				cc $(pwd)/expected/$str.c -o $str
# 				cc $(pwd)/rendu/$str.c -o student$str
# 				if ! diff -q <(./$str) <(./student$str) >> output.txt; then
# 					echo -ne "${red}KO "
# 				else
# 					echo -ne "${grn}OK "
# 				fi
# 			else
# 				man=$(find ./expected -type f -name "*.c" ! -name $str.c)
# 				# cc ./main.c ./expected/$str.c $man -o $str
# 				# cc ./main.c ./rendu/$str.c $man -o student$str
# 					for test in ${f_w[@]}; do
# 						if ! diff -q <(./$str $str $test) <(./student$str $str $test) >> output; then
# 							echo -ne "${red}KO "
# 						else
# 							echo -ne "${grn}OK "
# 						fi
# 					done
# 			fi
# 			rm -r *$str
# 		else
# 			echo ${red}"File not found skipping"
# 		fi
# 		echo ""
# 		sleep 1
# 	done
# done

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
