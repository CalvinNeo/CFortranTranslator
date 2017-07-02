void sub(const int & a, const int & b, const int & c) {
	int & a_ = const_cast<int &>(a);
	a_ = 2;
	int & b_ = const_cast<int &>(b);
	b_ = 2;
	int & c_ = const_cast<int &>(c);
	c_ = 2;
}


int main() {
	int a = 1;
	const int b = 1;
	sub(a, b, 1);
	cout << a << " " << b << endl;
	system("pause");
	return 0;
}