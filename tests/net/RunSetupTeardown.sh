#!/bin/sh

for i in {1..100}
do
    ../../net -s 2221 &
    ../../net -c 2221 127.0.0.1
    sleep 1
done