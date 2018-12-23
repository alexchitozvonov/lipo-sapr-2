#!/bin/bash
cat /dev/stdin | grep -i -o -E '\s?((\w|\d|_|-)*\.c)(\s|$)' | sed 's/ //' | sort | uniq