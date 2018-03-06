#!/usr/bin/env node

const WebSocket = require('ws');

const client = new WebSocket('ws://localhost:5000/');
client.onmessage = function (event) {
	if (event.data === 'MESSAGE_FROM_SERVER')
		console.log('[SUCCESS]');
	else
		console.error(`[FAILURE] Unknown value received: [${event.data}]`);
};

client.send('FROM_CLIENT');