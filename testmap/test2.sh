#!/bin/bash

c_purple="\033[0;35m"
c_red="\033[0;31m"
c_green="\033[0;32m"
c_blue="\033[0;34m"
c_yellow="\033[0;33m"
c_cyan="\033[0;36m"
c_reset="\033[0m"

echo ""
echo -e "${c_cyan}Map Tester 2001${c_purple}  ${1}  ${2}"
echo "============================"

# Check if at least one argument is given
if [ $# -lt 2 ]; then
  echo "Folder: $0 <directory_path>"
  echo "Test >> $1"
  exit 1
else
	echo "First argument has to be the folder of files, 2nd the Test SAN or LEAKS"
fi

# Check if the argument is a directory
if [ ! -d "$1" ]; then
  echo "The provided argument is not a valid directory."
  exit 2
fi

directory=$1
string_to_check=$2

# if [ "$string_to_check" == "SAN" ]; then
# 	make san
# fi

# if [ "$string_to_check" == "LEAKS" ]; then
# 	echo "LEAKS"
# 	make
# fi

# Loop through the files in the directory
for file in "$directory"/*
do
  if [ -f "$file" ]; then
		echo -e "${c_cyan}=====================================${c_reset}"
		if [ "$string_to_check" == "LEAKS" ]; then

    	#echo -e "${c_purple}LEAKS ${c_green}Map: $file${c_reset}"
    	#echo -e "${c_purple}file: $file${c_reset}"
		#sleep 0.2
		echo -e "${c_cyan}=====================================${c_reset}"
		leaks -atExit -- ./testmap_util $file
		echo -e "${c_purple}LEAKS ${c_green}Map: $file${c_reset}"
		echo -e "\n"
		sleep 2
		fi
		
		if [ "$string_to_check" == "LEAKSBONUS" ]; then
		leaks -atExit -- ./testmap_util_bonus $file
		echo -e "${c_purple}LEAKS ${c_red}BONUS ${c_green}Map: $file${c_reset}"
		echo -e "\n"
		sleep 2

		fi

		if [ "$string_to_check" == "SAN" ]; then

    	#echo -e "${c_purple}SAN ${c_green}Map: $file${c_reset}"
    	#echo -e "${c_purple}file: $file${c_reset}"
		#sleep 0.2
		echo -e "${c_cyan}=====================================${c_reset}"
		./testmap_util_san $file
		echo -e "${c_purple}SAN ${c_green}Map: $file${c_reset}"
		echo -e "\n"
		sleep 2
		fi

		if [ "$string_to_check" == "SANBONUS" ]; then
		./testmap_util_sanbonus $file
		echo -e "${c_purple}SAN ${c_red}BONUS ${c_green}Map: $file${c_reset}"
		echo -e "\n"
		sleep 2

		fi
  fi
done
