
send_message(){
    curl -X POST -H "Content-type: application/json" --data @slack_result.json  https://hooks.slack.com/services/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
}


if [ -f slack_result.json ]
then
    send_message
else
    color="#ff0000"
    commit_info=`git log -1 --pretty=format:"*%cn* : _%s_ <https://github.com/NotYet-Hexa/PLD-Comp/commit/%h|#%h>" 2>/dev/null`
    title="Build Failed !"
    text=`make 2>&1 | tail`
    json='{'
    json+='"text": "'$commit_info'",'
    json+='"attachments": ['
    json+='    {'
    json+='        "color": "'$color'",'
    json+='        "title": "'$title'",'
    json+='        "text": "'$text'"'
    json+='    }'
    json+=']'
    json+='}'

    echo "$json" > slack_result.json

    send_message
fi