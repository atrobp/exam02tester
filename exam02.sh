#!/bin/bash


#color stuff
grn=$'\e[1;32m'
red=$'\e[1;31m'
yel=$'\e[0;33m'
white=$'\033[37m'
grnbgrd=$'\e[1;33m'
black=$'\e[1;40m'

#exo per rank -- in order?
level0=("first_word" "fizzbuzz" "ft_putstr" "ft_strcpy" "ft_strlen" "ft_swap" "repeat_alpha" "rev_print" "rot_13" "rotone" "search_and_replace" "ulstr")
level1=("alpha_mirror" "camel_to_snake" "do_op" "ft_atoi" "ft_strcmp" "ft_strcspn" "ft_strdup" "ft_strpbrk" "ft_strrev" "ft_strspn" "inter" "is_power_of_2" "last_word" "max" "print_bits" "reverse_bits" "snake_to_camel" "swap_bits" "union" "wdmatch")
level2=("add_prime_sum" "epur_str" "expand_str" "ft_atoi_base" "ft_list_size" "ft_range" "ft_rrange" "hidenp" "lcm" "paramsum" "pgcd" "print_hex" "rstr_capitalizer" "str_capitalizer" "tab_mult")
level3=("flood_fil" "fprime" "ft_itoa" "ft_list_foreach" "ft_list_remove_if" "ft_split" "rev_wstr" "rotstring" "sort_int_tab" "sort_list")


#string to send in exercises
level0str=("abc" "FOR PONY" "this	 is	 sparta 	" "	  	loremm,ipsum	 	 " "	 	42	 	")
level1str=("My horse is Amazing" "Hello World" "banana")
level2str=("hereIsACamelCaseWord" "helloWorld" "meLove42VeryMuch")

#strstr <---> just like the one in ft_lvl#.c
strstr() {
	[ "${1#*$2*}" = "$1" ] && return 1
	return 0
}

#where all it begins
for i in {0..3}; do
	echo "${grnbgrd}-------- LEVEL | $i --------${white}"
	if test -d "./rendu/level$i"; then
		for exo in "${level0[@]}" "${level1[@]}" "${level2[@]}" "${level3[@]}"; do
			if test -f "./rendu/level$i/$exo.c"; then
				echo "$exo"
				# ft*.c files are functions so they require a main for compilation
				if strstr $exo "ft"; then
					if [ $i == 0 ]; then
						mandatory=$(find ./expected/lvl$i -type f -name "ft_*.c" ! -name $exo.c)
					elif [ $i == 1 ]; then
						mandatory=$(find ./expected/lvl$i -type f -name "ft_*.c" -o -type f -name "max.c" -o -type f -name "*bits.c" ! -name $exo.c)
					fi
					expected=$(cc ./expected/lvl$i/$exo.c $mandatory -o $exo)
					student=$(cc ./rendu/level$i/$exo.c $mandatory -o student$exo)
				else
					expected=$(cc ./expected/lvl$i/$exo.c -o $exo)
					student=$(cc ./rendu/level$i/$exo.c -o student$exo)
				fi
				#no/too much argument sent test
				if ! ( strstr $exo "ft" ) || ( strstr $exo "bits" ) || ( strstr $exo "max" ) || ( strstr $exo "2" ); then
					if ! diff -q <(./$exo) <(./student$exo) >> output.txt; then echo -ne "${red}KO "; else echo -ne "${grn}OK "; fi
					if ! diff -q <(./$exo "0" "1" "2" "4" "1") <(./student$exo "0" "1" "2" "4" "1") >> output.txt; then echo -ne "${red}KO "; else echo -ne "${grn}OK "; fi
				fi
				#either 3 or less argc
				if [ $exo != "fizzbuzz" ] || [ $exo != "inter" ] || [ $exo != "union" ] || [ $exo != "wdmatch" ]; then
					for str2send in "${level0str[@]}" "${level1str[@]}" "${level2str[@]}"; do
						a=$(( $RANDOM % 100 + 33 ))
						b=$(( $RANDOM % 100 + 33 ))
						if [ $exo == "search_and_replace" ] || [ $exo == "ft_swap" ]; then
							if ! diff -q <(./$exo "$str2send" "$a" "$b") <(./student$exo "$str2send" "$a" "$b") >> output.txt; then echo -ne "${red}KO "; else echo -ne "${grn}OK "; fi
						else
							if ! diff -q <(./$exo "$str2send") <(./student$exo "$str2send") >> output.txt; then echo -ne "${red}KO "; else echo -ne "${grn}OK "; fi
						fi
						sleep 0.3
					done
				#inter - union - wdmatch
				elif [ $exo == "inter" ] || [ $exo == "union" ] || [ $exo == "wdmatch" ]; then
					for str2send in "paqefwtdjetyiytjneytjoeyjnejeyj" "gtwthgdwthdwfteewhrtag6h4ffdhsd" "cette phrase ne cache rien"; do
						if ! diff -q <(./$exo "padinton" "$str2send") <(./student$exo "padinton" "$str2send") >> output.txt; then echo -ne "${red}KO "; else echo -ne "${grn}OK "; fi
						if ! diff -q <(./$exo "ddf6vewg64f" "$str2send") <(./student$exo "ddf6vewg64f" "$str2send") >> output.txt; then echo -ne "${red}KO "; else echo -ne "${grn}OK "; fi
						if ! diff -q <(./$exo "rien" "$str2send") <(./student$exo "rien" "$str2send") >> output.txt; then echo -ne "${red}KO "; else echo -ne "${grn}OK "; fi
					done
				fi
				echo ${white}
				rm -r *$exo
			fi
			if ([ $exo == "ulstr" ] && [ $i == 0 ]) || ([ $exo == "wdmatch" ] && [ $i == 1 ]) || ([ $exo == "tab_mult" ] && [ $i == 2 ]) || ([ $exo == "sort_list" ] && [ $i == 3 ]) ; then
				break
			fi
			sleep 0.5
		done
	else
		echo "path of rendu/level$i not found"
	fi
	sleep 0.45
done