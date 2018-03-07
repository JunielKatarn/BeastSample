#include "Client.h"

using std::string;

int main()
{
	const string host = "localhost";
	const string port = "5000";
	const string text = "FROM_CLIENT";

	// The io_context is required for all I/O
	boost::asio::io_context ioc;

	// Launch the asynchronous operation
	std::make_shared<session>(ioc)->run(host, port, text);

	// Run the I/O service. The call will return when
	// the get operation is complete.
	ioc.run();

	return EXIT_SUCCESS;
}
