#!/bin/bash

c_purple="\033[0;35m"
c_red="\033[0;31m"
c_green="\033[0;32m"
c_blue="\033[0;34m"
c_yellow="\033[0;33m"
c_cyan="\033[0;36m"
c_reset="\033[0m"

echo ""
echo -e "${c_cyan}Map Tester 2000${c_purple}  ${1} till ${2}"
echo "===================="

start=$1
end=$2
out=$3

make san
echo -e "${c_cyan}sanitize"

sleep 1
for (( i=start; i<=end; i++ ))
do
   echo -e "${c_green}Map: ${c_yellow}m$i.cub${c_red}"
   sleep 0.5
   if [ $# -ge 3 ]; then
   	   echo "file: ${out}"
   	  ./a.out m$i.cub >> ${out}
   else
      ./a.out m$i.cub
   fi

   echo ""
   sleep 0.5
done



make
echo -e "${c_cyan}leaks"

sleep 1
for (( i=start; i<=end; i++ ))
do
   echo -e "LEAKS ${c_green}Map: ${c_yellow}m$i.cub${c_red}"
   sleep 0.5
   if [ $# -ge 3 ]; then
   	   echo "file: ${out}"
       leaks -atExit -- ./a.out m$i.cub >> ${out}
   else
       leaks -atExit -- ./a.out m$i.cub
   fi
   echo ""
   sleep 0.5
done

# make san
# echo -e "${c_cyan}sanitize"

# map=map
# echo -e "${c_green}Map: ${c_yellow}$map${c_red}"
# ./a.out $map
# echo ""
# sleep 1

# map=prog.out
# echo -e "${c_green}Map: ${c_yellow}$map${c_red}"
# ./a.out $map
# echo ""
# sleep 1

# map=prog.cup
# echo -e "${c_green}Map: ${c_yellow}$map${c_red}"
# ./a.out $map
# echo ""
# sleep 1

# map=.
# echo -e "${c_green}Map: ${c_yellow}$map${c_red}"
# ./a.out $map
# echo ""
# sleep 1

# map=./
# echo -e "${c_green}Map: ${c_yellow}$map${c_red}"
# ./a.out $map
# echo ""
# sleep 1

# map=./test
# echo -e "${c_green}Map: ${c_yellow}$map${c_red}"
# ./a.out $map
# echo ""
# sleep 1

# map=./test/
# echo -e "${c_green}Map: ${c_yellow}$map${c_red}"
# ./a.out $map
# echo ""
# sleep 1



# make
# echo -e "${c_cyan}leaks"

# map=map
# echo -e "${c_green}Map: ${c_yellow}$map${c_red}"
# ./a.out $map
# echo ""
# sleep 1

# map=prog.out
# echo -e "${c_green}Map: ${c_yellow}$map${c_red}"
# ./a.out $map
# echo ""
# sleep 1

# map=prog.cup
# echo -e "${c_green}Map: ${c_yellow}$map${c_red}"
# ./a.out $map
# echo ""
# sleep 1

# map=.
# echo -e "${c_green}Map: ${c_yellow}$map${c_red}"
# ./a.out $map
# echo ""
# sleep 1

# map=./
# echo -e "${c_green}Map: ${c_yellow}$map${c_red}"
# ./a.out $map
# echo ""
# sleep 1

# map=./test
# echo -e "${c_green}Map: ${c_yellow}$map${c_red}"
# ./a.out $map
# echo ""
# sleep 1

# map=./test/
# echo -e "${c_green}Map: ${c_yellow}$map${c_red}"
# ./a.out $map
# echo ""
# sleep 1