# Secure TLS Chat

A simple cross-platform chat application demonstrating secure communication between a Python-based server and a C-based client using SSL/TLS.

## Project Structure

- **server_core.py**: The main entry point for the Python server. It handles socket binding, SSL wrapping, and listening for incoming connections.
- **message_handler.py**: Contains the logic for processing messages received by the server.
- **config.py**: Configuration constants for the server and client (HOST, PORT, BUFFER_SIZE).
- **network.c / .h**: C implementation of the network connection logic using OpenSSL.
- **chat_io.c / .h**: Implementation of sending and receiving messages in C.
- **test.c**: A simple C client implementation to test connectivity and message exchange.

## Prerequisites

### Python Server
- Python 3.x
- SSL certificates (`server.crt` and `server.key`) in the root directory.

### C Client
- A C compiler (e.g., GCC or Clang)
- OpenSSL development libraries

## Building and Running

### 1. Generate SSL Certificates
The server requires a certificate and a private key to establish secure connections. You can generate self-signed certificates for testing:

```bash
openssl req -x509 -newkey rsa:4096 -keyout server.key -out server.crt -days 365 -nodes
```

### 2. Start the Python Server
Run the server core script:

```bash
python3 server_core.py
```

### 3. Build and Run the C Client
Compile the client using GCC, ensuring you link the OpenSSL libraries:

```bash
gcc -o client network.c chat_io.c test.c -lssl -lcrypto
./client
```

## How It Works

1. The **Server** initializes an SSL context and binds to the configured host and port.
2. The **Client** connects to the server and performs an SSL handshake.
3. The **Client** sends a message ("Hello from C!").
4. The **Server** receives the message, prints it, and sends back a confirmation ("I got your message! - Python").
5. Both parties close the secure connection gracefully.
