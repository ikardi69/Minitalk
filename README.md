<h1 align="center">🛰️ Minitalk</h1>


A minimalist client-server communication program using UNIX signals. This project was developed as part of the 42 curriculum and was evaluated as outstanding, including bonus features such as Unicode support and server acknowledgments.

📖 Table of Contents
About the Project

Features

Getting Started

Usage

Bonus Features

Technical Details

Author

<p align="center">
  <h1>📌 About the Project</h1>
</p>

Minitalk is a low-level messaging application built in C that facilitates communication between a client and a server process via UNIX signals (SIGUSR1, SIGUSR2). The server receives a string message sent by the client and displays it upon completion.

This project was an exercise in understanding process control, signals, and low-level system programming on Unix-like systems.

<p align="center">
  <h1>✨ Features</h1>
</p>

Server prints its PID on startup.

Client sends a string message to the server using only signals.

Server reconstructs and displays the received message.

Handles multiple consecutive messages without restarting the server.

Clean, memory-safe implementation conforming to 42's Norm.

<p align="center">
  <h1>🚀 Getting Started</h1>
</p>

Prerequisites
GCC or any compliant C compiler

Unix-based environment (Linux/macOS)

Installation & Build
bash
Copy
Edit
git clone https://github.com/yourusername/minitalk.git
cd minitalk
make
This will compile two executables:

server

client

<p align="center">
  <h1>🛠️ Usage</h1>
</p>

Start the server:

bash
Copy
Edit
./server
It will display its PID (e.g., Server PID: 12345).

Send a message using the client:

bash
Copy
Edit
./client 12345 "Hello, world!"
The server will output:

Copy
Edit
Hello, world!

<p align="center">
  <h1>🎁 Bonus Features</h1>
</p>

✅ Server sends acknowledgment signals back to the client after message reception.

✅ Supports Unicode characters, allowing transmission of multi-byte characters (e.g., emojis, accented letters).

These features enhance robustness and character encoding capabilities — especially useful when working with internationalized input or validating reliable delivery.

<p align="center">
  <h1>⚙️ Technical Details</h1>
</p>
Language: C

System Calls Used:

kill(), getpid()

signal(), sigaction()

pause()

Signal encoding logic for converting characters to binary and transmitting bit-by-bit.

<p align="center">
  <h1>🧩 Architecture Diagram</h1>
</p

Message sent bit-by-bit using UNIX signals
Here’s a visual overview of the signal-based communication:
![image](https://github.com/user-attachments/assets/11ffafba-9037-4f2b-bb8d-56c664128fe4)

<p align="center">
  <h1>👤 Author</h1>
</p>

Mouhssine
1337 Student
