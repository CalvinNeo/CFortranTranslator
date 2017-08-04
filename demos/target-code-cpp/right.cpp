
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>

using namespace std;

struct Cls {
	Cls() {
		puts("Created");
	}
	Cls(Cls && c) {
		puts("Moved");
	}
	Cls(const Cls & c) {
		puts("Copied");
	}
	~Cls() {
		puts("Destroyed");
	}
};

void req_right(Cls && c) {
	puts("In subprogram");
	puts("Out subprogram");
}

void req_left(Cls c) {
	puts("In subprogram");
	puts("Out subprogram");
}

void test_right() {
	puts("In test");
	Cls cls{};
	req_right(std::move(cls));
	puts("Out test");
}

void test_left() {
	puts("In test");
	Cls cls{};
	req_left(std::move(cls));
	puts("Out test");
}

int main() {
	test_right();
	puts("Out main");
	system("pause");
}
