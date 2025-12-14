#bin/bash
g++ -std=c++20 $1.cpp -o xjs
./xjs < $2.in > $1.out
cat $1.out
diff -w $1.out $2.ans
