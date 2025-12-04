#bin/bash
g++ -std=c++17 -O2 $1.cpp -o xjs
./xjs < $2.in > out.txt
diff -w out.txt $2.ans
cat out.txt
