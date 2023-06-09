#!/bin/bash

if [[ "$1" == "-h" || "$1" == "--help" ]]; then
    echo "Welcome in sanitize.sh help !"
    echo -e "\tThis script aims to ease sanitizer usage."
    echo -ne "\tIt configures it to make the binary continue after "
    echo "any non-critical error (all except segfaults for instance)."
    echo -e "\n\"$0 <binary> <arguments>\""
    echo -e "\t<binary> : binary name (either 'asm' or 'corewar' here)"
    echo -e "\t<arguments> : arguments that are given to the binary."
    echo -e "\n\"$(basename $0) a b c\" ==> \"./binary a b c\""
    echo  "The binary name is automatically read from the Makefile using this command :"
    echo -e "\"cat Makefile | grep NAME | head -1 | awk '{ print $NF }'\""
    echo "If no binary in Makefile, the fallback is ./a.out"
    exit 0
fi

binary=$(cat Makefile | grep NAME | head -1 | awk '{ print $NF }')
if [[ "$binary" == "" ]]; then
    binary="./a.out"
fi

export ASAN_OPTIONS=halt_on_error=0
make --no-print-directory resanitize
./$binary ${@:1}
