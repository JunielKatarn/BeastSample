#pragma once

#include <boost/beast/websocket.hpp>
#include <memory>

namespace wsc {

class Client : public std::enable_shared_from_this<Client>
{
	boost::asio::io_context m_context;
	boost::asio::ip::tcp::resolver m_resolver;
	boost::beast::websocket::stream<boost::asio::ip::tcp::socket> m_stream;
	boost::beast::multi_buffer m_bufferIn;

public:
	Client();
	void Connect(const std::string& host, const std::string& port);
	void Write(const std::string& text);
	void Close();
};

}