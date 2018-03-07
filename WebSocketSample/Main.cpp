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
	auto client = NewClient();
	client->Connect("localhost", "5000");
	client->Write("FROM_CLIENT");
	client->Close();
}
