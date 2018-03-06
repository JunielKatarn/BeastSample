#!/usr/bin/env node

const WebSocket = require('ws');

const server = new WebSocket.Server({ port: 5000 });

console.log("Listening on port 5000...");

server.on('connection', (ws) => {
	ws.on('message', (text) => {
		console.log(`Message from client: [${text}]`);
		//ws.send(`Message from server: [${Date.now()}]`); // Uncomment once fixed.
		ws.send(`MESSAGE_FROM_SERVER`);
	});

	// This polutes the initial client read when using boost::beast!
	ws.send('Connected! :D');
});
