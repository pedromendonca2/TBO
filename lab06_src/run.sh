#!/bin/bash

sizes="100000 1000000 10000000"

echo "RANDOM NUMBERS"
for size in $sizes; do
    echo $size
    ./a.out $size < in/unif_rand/$size.txt | diff in/sorted/$size.txt -
done

echo "SORTED"
# size=100000
# echo $size
# ./a.out $size < in/sorted/$size.txt | diff in/sorted/$size.txt -
for size in $sizes; do
    echo $size
    ./a.out $size < in/sorted/$size.txt | diff in/sorted/$size.txt -
done

echo "REVERSE SORTED"
# size=100000
# echo $size
# ./a.out $size < in/reverse_sorted/$size.txt | diff in/sorted/$size.txt -
for size in $sizes; do
    echo $size
    ./a.out $size < in/reverse_sorted/$size.txt | diff in/sorted/$size.txt -
done

echo "NEARLY SORTED"
# size=100000
# echo $size
# ./a.out $size < in/nearly_sorted/$size.txt | diff in/sorted/$size.txt -
for size in $sizes; do
    echo $size
    ./a.out $size < in/nearly_sorted/$size.txt | diff in/sorted/$size.txt -
done
