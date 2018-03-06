# Summary
Sample Windows Desktop application that implements a minima WebSocket client using the `boost::beast` framework.

# Requirements
- Visual Studio 2017
  - VC++ 2017 v141 toolset (x86, x64)
  - Windows 10 sDK (10.0.16299.0) for Desktop C++ [x86 and x64]
- NuGet package manager
- Node.js (includes NPM)

# Instructions
1. Clone this repository.
1. Enter the cloned directory.
1. Restore the NuGet dependencies.<br/>
   `NuGet.exe restore`
1. Restore NPM dependencies.<br/>
   `npm.exe install`
1. Build the project.<br/>
   `MSBuild.exe`
1. Start the server.<br/>
   `node WebSocketSample\Server.js`
1. Run the client.<br/>
   `x64\Debug\WebSocketSample.exe`

# Bug
The client should print the message `FROM_SERVER`.
Intead, it prints a message sent when the client connects to the server, which should be discarded.