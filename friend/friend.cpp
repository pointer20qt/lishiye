#include <iostream>
using namespace std;

class A {
public:
	A(int val) :a(val) {}
	void fun() {
		cout << a << endl;  //10
		cout << this->a << endl;  //10£¬µÈ¼ÛÓÚcout << a << endl;
	}
private:
	int a;
	friend void fun1(const A& res);
};

void fun1(const A& res) {
	cout << res.a << endl;  //10
}

int main(int argc, char* argv[]) {
	A res(10);
	res.fun();
	fun1(res);
	getchar();
	return 0;
}
