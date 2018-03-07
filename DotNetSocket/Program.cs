using System;

using PureWebSockets;

namespace DotNetSocket
{
	class Client
	{
		PureWebSocket ws;

		void OnMessage(string message)
		{
			if ("MESSAGE_FROM_SERVER" == message)
				Console.WriteLine("[SUCCESS]");
			else
				Console.WriteLine("[FAILURE] Unknown value received: {0}", message);
		}

		void OnSendFailed(string data, Exception ex)
		{
			Console.WriteLine("[FAILURE] Couldn't send {0}.", data);
			Console.WriteLine(ex.Message);
		}

		private void OnError(Exception ex)
		{
			Console.WriteLine("[FAILURE]");
			Console.WriteLine(ex.Message);
		}

		public Client()
		{
		}

		public void Connect(string url)
		{
			ws = new PureWebSocket(url, new ReconnectStrategy(10000, 60000));

			ws.OnMessage += OnMessage;
			ws.OnSendFailed += OnSendFailed;
			ws.OnError += OnError;
			ws.OnClosed += OnClosed;
			ws.OnStateChanged += OnStateChanged;
			ws.OnOpened += Ws_OnOpened;

			ws.Connect();
		}

		private void Ws_OnOpened()
		{
			Console.WriteLine("Opened!");
		}

		private void OnStateChanged(System.Net.WebSockets.WebSocketState newState, System.Net.WebSockets.WebSocketState prevState)
		{
			Console.WriteLine("Status from [{0}] to [{1}].", prevState, newState);
		}

		private void OnClosed(System.Net.WebSockets.WebSocketCloseStatus reason)
		{
			Console.WriteLine("Closed.");
		}

		public void Write(string text)
		{
			ws.Send(text);
		}

		public void Close()
		{
			ws.Disconnect();
		}
	}

	class Program
	{
		static void Main(string[] args)
		{
			var client = new Client();
			client.Connect("ws://localhost:5000/");
			client.Write("FROM_CLIENT");
			client.Close();
		}
	}
}
