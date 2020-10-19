#!/usr/bin/env bash
FILE="$1"
declare -A WORDS

if [ ! -f "$FILE" ] ; then
        echo "Nem letezik a megadott file!"
        exit 1
fi

for WORD in $(cat "$FILE") ; do
        LENGTH=$(echo -n "$WORD" | wc -m )
        WORDS[$LENGTH]=$((WORDS[$LENGTH]+1))
done

KEYS=$(echo -n "${!WORDS[@]}"|tr " " "\n"|sort -n)
for LENGTH in $KEYS
do
    echo "$LENGTH - ${WORDS[$LENGTH]}"
done

