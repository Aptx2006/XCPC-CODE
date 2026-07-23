g++ -std=c++17 -O2 $1.cpp -o xjs
./xjs < $2.in > out.txt
diff -w $2.ans out.txt
cat out.txt
