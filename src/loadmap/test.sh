#!/bin/bash

c_purple="\033[0;35m"
c_red="\033[0;31m"
c_green="\033[0;32m"
c_blue="\033[0;34m"
c_yellow="\033[0;33m"
c_cyan="\033[0;36m"
c_reset="\033[0m"

echo ""
echo -e "${c_cyan}Map Tester 2000${c_purple}"
echo "===================="

#make san 
#sleep 3
# for i in {1..25}
# do
#    echo -e "${c_green}Map: ${c_yellow}m$i.cub${c_red}"
#    ./a.out m$i.cub
#    echo ""
#    sleep 0.1
# done

# make
# sleep 3

for i in {1..2}
do
   echo -e "LEAKS ${c_green}Map: ${c_yellow}m$i.cub${c_red}"
   leaks -atExit -- ./a.out m$i.cub
   echo ""
   sleep 2
done