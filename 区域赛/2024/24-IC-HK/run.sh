#bin/bash
g++ -std=c++17 -O2 $1.cpp -o htb
./htb < $2.in > $1.txt
cat $1.txt
diff -w $1.txt $2.ans
