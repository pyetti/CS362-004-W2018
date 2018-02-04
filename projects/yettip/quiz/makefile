CFLAGS = -Wall 
.DEFAULT_GOAL := runTest

testFileName = test
randomTesting: testme.c
	gcc -o $(testFileName) testme.c $(FLAGS)

runTest: randomTesting
	./$(testFileName)

clean:
	rm -i $(testFileName)
