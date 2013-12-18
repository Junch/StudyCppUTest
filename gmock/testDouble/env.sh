#!/bin/bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
echo $DIR
export GMOCK_HOME="$DIR/../../gmock"
export JSONCPP_HOME="$DIR/../../jsoncpp"
