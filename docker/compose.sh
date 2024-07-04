#!/bin/bash

export U_GID="$(id -g $USER)"
export U_UID="$(id -u $USER)"

cd $(dirname "$0")

if [ "$1" == run ]; then
    docker compose run --rm ab_dev
elif [ ! $(-z "$1") ]; then
    docker compose "$1"
else
    cat <<EOF
    Usege:
    compose.sh [command]
    up, down, run, build
EOF
fi
