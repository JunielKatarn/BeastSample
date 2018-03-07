#pragma once

#include <cpprest/ws_client.h>

class Client
{
	web::websockets::client::websocket_client m_client;

public:
	Client();
	void Connect(const std::string& url);
	void Write(const std::string& text);
	void Close();
};