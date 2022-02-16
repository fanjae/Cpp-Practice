#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>

void print(const boost::system::error_code & /*e*/, boost::asio::steady_timer *t, int * count)
{
	if (*count < 5)
	{
		std::cout << *count << std::endl;
		++(*count);
	}
	t->expires_at(t->expiry() + boost::asio::chrono::seconds(1));
}

int main(void)
{

}