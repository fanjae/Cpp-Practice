#include <iostream>
#include <boost/asio.hpp>

void print(const boost::system::error_code& /*e*/)
{
	std::cout << "Hello, World!" << std::endl;
}

int main()
{
	/*
	ASIO의 비동기 기능을 사용한다는 것은 비동기 작업을 완료 후 호출되는 콜백 함수를 갖는다는 것을 의미한다.
	이 프로그램에서는 비동기 대기가 끝나면 호출되는 print라는 함수를 정의한다. */
	boost::asio::io_context io;

	boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));

	t.async_wait(&print);

	/*
	블록 대기를 수행하는 대신, 비동기 대기를 수행하기 위해
	steady_timer::async_wait() 함수를 호출한다. 이 함수를 호출할 때,
	print Callback Handler를 인수로 전달한다.
	*/

	io.run();

	/* 마지막으로 io_context개체에서 io_context::run() 함수를 호출한다.
	asio 라이브러리는 현재 io_context::run()을 호출한 스레드에서만 콜백 핸들러가 호출되도록 보장한다.
	따라서 io_context::run() 함수는 비동기 대기 완료를 위한 콜백이 호출되지 않는 한 결코 호출되지 않는다.

	
	return 0;
	
}