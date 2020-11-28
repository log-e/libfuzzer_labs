test1: test1.cpp
	clang++ -g -O0 -fsanitize=address,fuzzer -o test1 test1.cpp

test2: test2.cpp
	clang++ -g -O2 -fsanitize=address,fuzzer -I./include -o test2 test2.cpp

test_role: test_role.cpp
	clang++ -g -O2 -o test_role -I/usr/local/include -L/usr/local/lib -lprotobuf test_role.cpp role.pb.cc

fuzz_role: fuzz_role.cpp
	clang++ -O2 -fsanitize=address,fuzzer -g -o fuzz_role -I/usr/local/include -I/usr/local/include/libprotobuf-mutator -L/usr/local/lib -lprotobuf -lprotobuf-mutator-libfuzzer -lprotobuf-mutator fuzz_role.cpp role.pb.cc

clean:
	rm test1 test2 test_role fuzz_role