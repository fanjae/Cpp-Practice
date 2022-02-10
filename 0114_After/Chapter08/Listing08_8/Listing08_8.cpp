#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void file_it(ostream &os, double fo, const double fe[], int n);
const int LIMIT = 5;
int main()
{
	ofstream fout;
	const char *fn = "ep-data.txt";
	fout.open(fn);
	if (!fout.is_open())
	{
		cout << fn << " 파일을 열 수 없습니다. 끝. \n";
		exit(EXIT_FAILURE);
	}
	double objective;
	cout << "대물렌즈 초점거리를 "
		"mm 단위로 입력하십시오 : ";
	cin >> objective;

	double eps[LIMIT];
	cout << LIMIT << "기지 대안렌즈의 초점거리를 " "mm 단위로 입력하십시오: \n";

	for (int i = 0; i < LIMIT; i++)
	{
		cout << "대안렌즈 #" << i + 1 << ": ";
		cin >> eps[i];
	}
	file_it(fout, objective, eps, LIMIT);
	file_it(cout, objective, eps, LIMIT);
	// ostream &형인 os 매개변수가 cout과 같은 ostream 객체와 fout과 같은 ofstream 객체를 참조할 수 있다.
	// setf() 메서드는 다양한 포맷팅 상태를 설정한다.
	// 메서드 호출 setf(ios_base::fixed)는 고정 소수점 표기를 사용하는 모드에 객체를 놓는다.


	cout << "종료\n";
	return 0;
}

void file_it(ostream &os, double fo, const double fe[], int n)
{
	ios_base::fmtflags initial;
	initial = os.setf(ios_base::fixed);		// 초기 포맷팅 상태 저장
	os.precision(0);
	os << "대물렌즈의 초점거리 : " << fo << " mm\n";
	os.setf(ios::showpoint);
	os.precision(1);
	os.width(17);
	os << "대안렌즈 초점거리";
	os.width(15);
	os << "확대배율" << endl;
	for (int i = 0; i < n; i++)
	{
		os.width(17);
		os << fe[i];
		os.width(15);
		os << int(fo / fe[i] + 0.5) << endl;
	}
	os.setf(initial);						// 초기 포맷팅 상태 복원

	// setf() 메서드는 호출을 하기 전에 유효한 모든 포맷팅 설정들의 복사본을 리턴한다.
	// ios_base::fmtflags는 이 정보를 저장하는 데 필요한 데이터형의 장식적 이름이다.
	// initial에 대입하는 것은 file_it() 함수가 호출되기 전의 유효한 설정들을 저장한다.
	// initial 변수를 setf()에 매개변수로 사용하여 모든 포맷팅 설정들을 원래 값으로 리셋할 수 있다.

}