#include "Client.h"

#include <boost/asio/connect.hpp>
#include <boost/beast/core/buffers_to_string.hpp>
#include <iostream>

using namespace boost::asio;
using namespace boost::beast;

using bsec = const boost::system::error_code&;

using boost::asio::ip::basic_resolver_iterator;
using boost::asio::ip::tcp;
using std::cout;
using std::endl;

namespace wsc {

Client::Client()
	: m_resolver { m_context }
	, m_stream { m_context }
{
}

void Client::Connect(const std::string& host, const std::string& port)
{
	m_resolver.async_resolve(host, port, [pThis=shared_from_this(), host](bsec ec, tcp::resolver::results_type results)
	{
		async_connect(pThis->m_stream.next_layer(), results.begin(), results.end(),  [pThis=pThis->shared_from_this(), host](bsec ec, const basic_resolver_iterator<tcp>&)
		{
			if (ec)
			{
				cout << "[FAIL]" << ec.message() << endl;
				return;
			}

			pThis->m_stream.async_handshake(host, "/", [pThis=pThis->shared_from_this()](bsec ec)
			{
				if (ec)
				{
					cout << "[FAIL]" << ec.message() << endl;
					return;
				}
			});
		});
	});

	m_context.run();
}

void Client::Write(const std::string& text)
{
	m_context.restart();

	m_stream.async_write(buffer(text), [pThis = this->shared_from_this()](bsec ec, size_t length)
	{
		if (ec)
		{
			cout << "[FAIL]" << ec.message() << endl;
			return;
		}

		pThis->m_stream.async_read(pThis->m_bufferIn, [pThis = pThis->shared_from_this()](bsec ec, size_t length)
		{
			if (ec)
			{
				cout << "[FAIL]" << ec.message() << endl;
				return;
			}

			auto incoming = buffers_to_string(pThis->m_bufferIn.data());
			if (incoming == "MESSAGE_FROM_SERVER")
				cout << "[SUCCESS]" << endl;
			else
				cout << "[FAILURE] Unknown value received: " << incoming << endl;

			pThis->m_bufferIn.consume(length);
		});
	});

	m_context.run();
}

void Client::Close()
{
	m_context.restart();

	m_stream.async_close(websocket::close_code::normal, [](bsec ec)
	{
		if (ec)
		{
			cout << "[FAIL]" << ec.message() << endl;
			return;
		}

		cout << "Connection closed." << endl;
	});

	m_context.run();
}

} // namespace wsc