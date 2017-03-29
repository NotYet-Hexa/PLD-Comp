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

result_from_test() {
    name="$1"
    resultnumber=`echo "$1" | sed -n "s/.*test\(.*\)$/\1/p"`
    path=`echo "$1" | sed -n "s/^\(.*\)\/test.*$/\1/p"`
    resultname="$path""/result""$resultnumber"
    echo $resultname
}


run_test() {

    result=`$exe < "$1"`

    diff=`diff $2 <(echo $1)`

    if [ "$diff" == "" ]
    then
        echo "`basename $1` OK"
    else
        echo "$1 fail"
        echo "$diff"
        exit 1
    fi
}

if [ $# -gt 0 ]
then
    for param in $*
    do
        resultname=$(result_from_test "$test")
        if [[ -f $param  && -f $resultname ]]
        then
            run_test $param $resultname
        elif [[ -f "./tests/$param" && -f "./tests/$resultname" ]]
        then
            run_test "./tests/$param" "./tests/$resultname"
        else
            echo "Aucun fichier $param"
            exit 1
        fi
    done
else
    tests=`find . -type f -name 'test*'`
    for test in $tests
    do
        resultname=$(result_from_test "$test")
        if [ -f $resultname ]
        then
            run_test $test $resultname
        else
            echo -e "$test \t was ignored → $resultname \t missing"
        fi
    done
fi