#!/bin/sh

head -c 2147483648 </dev/urandom >2g
head -c 3221225472 </dev/urandom >3g
head -c 4294967296 </dev/urandom >4g
head -c 5368709120 </dev/urandom >5g
head -c 6442450944 </dev/urandom >6g
head -c 7516192768 </dev/urandom >7g
head -c 8589934592 </dev/urandom >8g