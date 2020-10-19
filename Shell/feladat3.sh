#!/usr/bin/env bash
file="$1"
szo="$2"
grep -e "^${szo}" "$file"|grep -e "${szo}$" "$file"| wc -l