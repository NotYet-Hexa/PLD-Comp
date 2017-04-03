
send_message(){
    curl -X POST -H "Content-type: application/json" --data @slack_result.json  https://hooks.slack.com/services/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
}

branch=`git branch`

if [[ $branch != *"master"* ]]
then
    exit 0
fi


if [ -e slack_result.json ]
then
    send_message
else
    color="#ff0000"
    commit_info=`git log -1 --pretty=format:"*%cn* : _%s_ <https://github.com/NotYet-Hexa/PLD-Comp/commit/%h|#%h>" 2>/dev/null`
    title="Build Failed !"
    text_tmp=`make 2>&1 | tail | sed -e 's%"%\x27%g' -e 's%\^%%g' -e 's/^ *//g' | tr -d '\r'`
    text=""

    # make 2>&1 | tail | od -c

    while read line
    do
        if [[ ! -z "$line" || "$line" = " "* ]]
        then
            text+="$line""\\n"
        fi
    done <<< "$text_tmp"

    # echo -ne "$text"

    # echo "$text" | od -c

    json='{'
    json+='"text": "'"$commit_info"'",'
    json+='"attachments": ['
    json+='    {'
    json+='        "color": "'"$color"'",'
    json+='        "title": "'"$title"'",'
    json+='        "text": "'"$text"'"'
    json+='    }'
    json+=']'
    json+='}'

    echo "$json" > slack_result.json

    send_message
fi