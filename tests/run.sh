#!/bin/bash

nbArgs=`wc -w <<< "${*:2}"`
message=""
fail=0
RED='\033[1;31m'
NC='\033[0m'

nb_success_test=0
nb_fail_test=0
assembl_success=0
assembl_fail=0

if [ $# -eq 0 ]
then
    echo "Please pass the executable as first parameter"
    exit 1
fi

exe="$1"

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
    path=`echo "$1" | sed -n "s/^\(.*\).test$/\1/p"`
    resultname="$path"".res"
    echo $resultname
}

assembl_from_test()
{
    name="$1"
    path=`echo "$1" | sed -n "s/^\(.*\).test$/\1/p"`
    resultname="$path"".s"
    echo $resultname
}


run_test() {
    result=`bash -c "$exe < $1"  2>&1`

    diff=`diff -u -w $2 <(echo -e "$result")`


    if [ "$diff" == "" ]
    then
        echo -e "→ `basename $1 | sed -n "s/^\(.*\).test$/\1/p"` \xE2\x9C\x93"
        message+=":small_blue_diamond: `basename $1 | sed -n "s/^\(.*\).test$/\1/p"` :heavy_check_mark: \n"
        nb_success_test=`expr $nb_success_test + 1`
    else
        printf "$RED"
        echo -e "$1 \xE2\x9C\x96"
        echo "$diff" | sed -e 's/^/\t/g'
        printf "$NC"

        message+=":small_blue_diamond: `basename $1 | sed -n "s/^\(.*\).test$/\1/p"` :x: \n"
        fail=1
        nb_fail_test=`expr $nb_fail_test + 1`
    fi

    assembleur=$(assembl_from_test "$1")

    main_ass="main.s"

    if [ -f $assembleur ]
    then
        if [ ! -f $main_ass ]
        then
            if [ -f "../$main_ass" ]
            then
                main_ass="../$main_ass"
            else
                echo "main.s not found $assembleur ignored"
                return
            fi
        fi

        assembl_diff=`diff -u -w $assembleur $main_ass`
        if [ "$assembl_diff" == "" ]
        then
            echo -e "\t → `basename $1 | sed -n "s/^\(.*\).test$/\1/p"` assembl \xE2\x9C\x93"
            message+="\t `basename $1 | sed -n "s/^\(.*\).test$/\1/p"` assembl :heavy_check_mark: \n"
            assembl_success=`expr $assembl_success + 1`
        else
            printf "$RED"
            echo -e "$1 assembl \xE2\x9C\x96"
            echo "$assembl_diff" | sed -e 's/^/\t/g'
            printf "$NC"

            message+="\t `basename $1 | sed -n "s/^\(.*\).test$/\1/p"` assembl :x: \n"
            assembl_fail=`expr $assembl_fail + 1`
        fi
        
    else
        echo -e "test assembleur ignored → $assembleur \t missing"
    fi
}

format_message() {
    color="#36a64f"
    title="$nb_success_test tests succeeded !"
    titlelink="https://travis-ci.org/NotYet-Hexa/PLD-Comp"
    text="$message"
    commit_info=`git log -1 --pretty=format:"*%cn* : _ %s _ <https://github.com/NotYet-Hexa/PLD-Comp/commit/%h|#%h>" 2>/dev/null`
    # text=`echo "$message" | sed 's%\\\x%\\\\\\\x%g'`
    if [ $fail -eq 1 ]
    then
        color="#ff0000"
        title="$nb_fail_test test(s) failed $nb_success_test succeeded"
    fi

    json='{'
    json+='"text": "'$commit_info'",'
    json+='"attachments": ['
    json+='    {'
    json+='        "color": "'$color'",'
    json+='        "title": "'$title'",'
    json+='        "title_link": "'$titlelink'",'
    json+='        "text": "'$text'"'
    json+='    }'
    json+=']'
    json+='}'

    echo "$json"
}

if [ $nbArgs -gt 0 ]
then
    for param in ${*:2}
    do
        if [ -f $param ]
        then
            resultname=$(result_from_test "$param")
            if [ -f $resultname ]
            then
                run_test "$param" "$resultname"
            else
                echo -e "$param \t was ignored → $resultname \t missing"
            fi
        elif [ -f "./tests/$param" ]
        then
            param="./tests/$param"
            resultname=$(result_from_test "$param")
            if [ -f "$resultname" ]
            then
                run_test "$param" "$resultname"
            else
                echo -e "$param \t was ignored → $resultname \t missing"
            fi
        else
            echo "Aucun fichier $param, chemin essayé :"
            echo -e "\t → $param"
            echo -e "\t → ./tests/$param"
            exit 1
        fi
    done
    format_message > slack_result.json
    if [ $fail -eq 1 ]
    then
        false
    fi
else
    tests=`find ./tests/ -type f -name '*.test'`
    nbtest=`wc -w <<< "$tests"`
    if [ $nbtest -eq 0 ]
    then
        tests=`find . -type f -name '*.test'`
    fi
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

    if [ $assembl_fail -eq 0 ]
    then
        echo -e "\033[32;1m$assembl_success test(s) assembleurs réussis ! \033[0m"
    else
        echo -e "\033[1;31m$assembl_success test(s) assembleurs réussis, $assembl_fail test(s) assembleurs échoués\033[0m"
    fi

    format_message > slack_result.json
    if [ $fail -eq 1 ]
    then
        false
    fi
fi