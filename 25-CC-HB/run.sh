#bin/bash
g++ -std=c++20 $1.cpp -o xjs
./xjs < $2.in > $2.txt
cat $2.txt
diff -w $2.ans $2.txt