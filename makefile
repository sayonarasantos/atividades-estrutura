init:
	mkdir output

clear:
	rm output/*

l1q1:
	g++ list1/q1.cpp -o output/l1q1
	./output/l1q1

l1q2:
	g++ list1/q2.cpp -o output/l1q2
	./output/l1q2

l1q3:
	g++ list1/q3.cpp -o output/l1q3
	./output/l1q3

l1q4:
	g++ list1/q4.cpp -o output/l1q4
	./output/l1q4

l1q5:
	g++ list1/q5.cpp -o output/l1q5
	./output/l1q5

l3:
	g++ list3/* -o output/l3
	./output/l3

l4:
	g++ list4/* -o output/l4
	./output/l4

l5:
	g++ list5/* -o output/l5
	./output/l5