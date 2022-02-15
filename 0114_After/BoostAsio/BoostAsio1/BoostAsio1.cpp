#include <iostream>
#include <boost/asio.hpp>

using namespace std;

int main(void) {

	boost::asio::io_context io;
	/* asio를 사용하는 모든 프로그램에는 IO_Context 또는 Thread_pool 개체와 같은
	I/O Execution Context가 하나 이상 있어야 한다. I/O Execution Context는 I/O 기능에 대한
	접근을 제공한다. */

	boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));
	/* boost::asio::steady_timer 유형의 개체를 선언.
	I/O 기능(또는 이 경우 타이머 기능)을 제공하는 핵심 Asio 클래스의 생성자는 IO_Context를
	첫번째 인수로 사용함. 생성자에 대한 두 번째 인수는 타이머가 5초후에 만료되도록 설정.
	*/

	t.wait();
	/* steady_timer::wait()에 대한 호출은 타이머가 생성된(즉, 대기가 시작된 시점이 아닌) 후 5초가
	지나 만료될 때까지 반환되지 않는다.

	타이머는 항상 Expired(만료됨) 또는 Not Expired(만료되지 않음) 두 가지 status이다.
	steady_timer::wait() 함수가 만료된 타이머에서 호출되면, 즉시 반환될 것이다. */

	std::cout << "Hello, World!" << std::endl;

	return 0;
}

/*
링커->일반->추가 라이브러리 디렉토리
C:\boost_1_78_0\boost_1_78_0\stage\lib

VC++ 디렉토리 포함 디렉토리
C:\boost_1_78_0\boost_1_78_0\
*/