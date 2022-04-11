#include <iostream>
#include <functional>
using namespace std;

int main()
{
	cout << less<int>()(10, 20) << endl;
	cout << less<int>()(20, 20) << endl;
	cout << less<int>()(20, 10) << endl;
	cout << "=============" << endl;
	cout << not2(less<int>())(10, 20) << endl;
	// 임시 객체에 less에 not2 어댑터 적용
	cout << not2(less<int>())(20, 20) << endl;
	cout << not2(less<int>())(20, 10) << endl;
	cout << endl;

	less<int> l;
	cout << l(10, 20) << endl; // less 객체 1로 비교
	cout << l(20, 20) << endl;
	cout << l(20, 10) << endl;
	cout << "=============" << endl;

	cout << not2(1)(10, 20) << endl; // less 객체 1에 not2 어댑터 적용
	cout << not2(1)(20, 20) << endl;
	cout << not2(1)(20, 10) << endl;

	return 0;
}
