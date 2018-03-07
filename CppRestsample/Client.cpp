//#undef U
//
//#include "Client.h"
//
//using namespace web::websockets::client;
//
//using std::cout;
//using std::endl;
//using std::string;

//void Client::Connect(const string& url)
//{
//	m_client.connect(U("")).then([]()
//	{
//
//	});
//}
//
//void Client::Write(const string& text)
//{
//	websocket_outgoing_message msg;
//	msg.set_utf8_message(text);
//	m_client.send(msg).then([this]()
//	{
//		this->m_client.receive().then([](websocket_incoming_message msg)
//		{
//			return msg.extract_string();
//		}).then([](string body)
//		{
//			if (body == "MESSAGE_FROM_SERVER")
//				cout << "[SUCCESS]" << endl;
//			else
//				cout << "[FAILURE] Unknown value received: " << body << endl;
//		});
//	});
//}
//
//void Client::Close()
//{
//	m_client.close().then([]()
//	{
//
//	});
//}
