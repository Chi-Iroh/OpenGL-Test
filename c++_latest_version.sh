#!/bin/bash
if [[ "$1" == "-h" || "$1" == "--help" || "$1" == "" ]]; then
    echo "c++_latest_version.sh [-h || --help] displays this help text."
    echo "c++_latest_version.sh compiler [NO_WIP_STANDARD] :"
    echo "This script looks for the latest supported C++ standard by a given compiler"
    echo "If NO_WIP_STANDARD flag is given, ignores the working in the standards in progress :"
    echo -e "\tC++0x (2011)"
    echo -e "\tC++1y (2014)"
    echo -e "\tC++1z (2017)"
    echo -e "\tC++2a (2020)"
    echo -e "\tC++2b (2023)"
    echo "Only g++ and clang++ are supported."
    echo "On succes, writes the compiler flag to use that standard directly in command-line."
    echo "On failure, writes an error message to stderr."
    echo "Note :"
    echo -e "\tFailure can only happen if the script can't write in /tmp, or your compiler doesn't even support C++98 (that shouldn't be possible, right ??)."
    exit 0
fi
if [[ "$1" != "g++" && "$1" != "clang++" ]]; then
    echo Only g++ and clang++ are supported ! >&2
    echo "See --help for further information" >&2
    exit 1
fi
if [[ "$2" != "" && "$2" != "NO_WIP_STANDARD" ]]; then
    echo "Only NO_WIP_STANDARD is a valid option." >&2
    echo "See --help for further information" >&2
    exit 1
fi
echo "int main(){}" > /tmp/g++_version.cpp
if (( $? != 0 )); then
    echo "Cannot create temporary file in /tmp directory." >&2
    exit 2
fi
if [[ "$2" == "NO_WIP_STANDARD" ]]; then
    cpp_versions=(23 20 17 14 11 03 98)
else
    cpp_versions=(23 2b 20 2a 17 1z 14 1y 11 0x 03 98)
fi
for cpp_version in ${cpp_versions[@]}; do
    version_flag="-std=c++$cpp_version"
    "$1" $version_flag /tmp/g++_version.cpp -o /tmp/g++_version.out &> /dev/null
    if (( $? == 0 )); then
        echo "-std=c++$cpp_version"
        exit 0
    fi
done
echo "How in the fucking hell your compiler can't even run c++98 code ?" >&2
exit 3
