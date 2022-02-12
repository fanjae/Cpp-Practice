#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace std;

int main(void) {
	boost::asio::io_service io;
	boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
	t.wait();

	cout << "hello world\n";
	return 0;
}

/*
링커->일반->추가 라이브러리 디렉토리
C:\boost_1_78_0\boost_1_78_0\stage\lib

VC++ 디렉토리 포함 디렉토리
C:\boost_1_78_0\boost_1_78_0\
*/