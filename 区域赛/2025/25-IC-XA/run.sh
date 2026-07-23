#bin/bash
g++ -std=c++20 -O2 $1.cpp -o xjs
./xjs < $2.in > out.txt
cat out.txt
diff -w out.txt $2.ans
