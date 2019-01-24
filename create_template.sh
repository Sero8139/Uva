#! /bin/bash
if [ "$1" == "" ];
then
	echo "input problem number as first parameter"
	exit -1
fi

mkdir -p $1
if [ ! -f $1/Uva-$1.cpp ]; then
    echo "create template cpp file"
    cp template/template.cpp $1/Uva-$1.cpp
fi

if [ ! -f $1/Readme.md ]; then
    echo "create template Readme file"
    cp template/template.md $1/Readme.md
fi

PROBLEM_GROUP=`expr $1 / 100`
PROBLEM_NUM=$1

sed -i 's/@PROBLEM_GROUP/'"${PROBLEM_GROUP}"'/g' $1/Readme.md
sed -i 's/@PROBLEM_NUM/'"${PROBLEM_NUM}"'/g' $1/Readme.md

