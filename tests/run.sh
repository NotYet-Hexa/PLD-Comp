#!/bin/bash

exe="build/exe"
if ! [ -f "$exe" ]
then
    if [ -f "../$exe" ]
    then
        exe="../$exe"
    else
        echo "Can't find executable"
        echo "We are here : `pwd`"
        echo "Path used : $exe & ../$exe"
        exit 1
    fi
fi

run_test() {
    expression=`sed '1!d' $1`
    resulthope=`sed '2!d' $1 | tr -d '\r' | tr -d '\n'`

    if [ -z "$resulthope" ]
    then
        echo "Missing new line in $1"
        exit 1
    fi

    result=`$exe <<< "$expression"`

    result=`echo "$result" | tr -d '\r' | tr -d '\n'`

    if [ "$result" = "$resulthope" ]
    then
        echo "`basename $1` OK"
    else
        echo -e "$1 fail \n\t→ expected : '$resulthope' - actual : '$result'"
        exit 1
    fi
}

if [ $# -gt 0 ]
then
    for param in $*
    do
        if [ -f $param ]
        then
            run_test $param
        elif [ -f "./tests/$param" ]
        then
            run_test "./tests/$param"
        else
            echo "Aucun fichier $param"
            exit 1
        fi
    done
else
    tests=`find . -type f -name 'test*'`
    for test in $tests
    do
        run_test $test
    done
fi