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

l6:
	g++ list6/* -o output/l6
	./output/l6

l7:
	g++ list7/* -o output/l7
	./output/l7

l8:
	g++ list8/* -o output/l8
	./output/l8

l9:
	g++ list9/* -o output/l9
	./output/l9

l10:
	g++ list10/* -o output/l10
	./output/l10