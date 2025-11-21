#bin/bash
g++ -std=c++20 $1.cpp -o xjs
./xjs < $2.in > $1.txt
cat $1.txt
diff -w $1.txt $2.ans