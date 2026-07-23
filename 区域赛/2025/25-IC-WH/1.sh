#bin/bash
g++ -Wall -std=c++20 -O2 $1.cpp -o run
./run < $2.in > $1.txt
cat $1.txt
diff -w $1.txt $2.ans