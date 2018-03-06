#include "Client.h"

using namespace wsc;

std::shared_ptr<Client> NewClient()
{
	return std::make_shared<Client>();
}

int main()
{
	// Implicitly sends message 'FROM_CLIENT' to the server.
	// Expects message 'FROM_SERVER' and prints it.
	NewClient()->Start("localhost", "5000");
}
