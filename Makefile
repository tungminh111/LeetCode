CXX=clang++
CXXFLAGS=-g -std=c++11 -Wall -pedantic
BIN=prog

run %: %
	chmod +x $<
	$<

%: %.o
	$(CXX) $< -o $@

%.o: %.c
	$(CXX) $< -c $@
