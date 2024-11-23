### Docker Hub:
The image is available at the link: [nadiya1010/my-http-server](https://hub.docker.com/r/nadiya1010/my-http-server)

# HTTP Server in Docker

## Description
This project implements an HTTP server that calculates trigonometric functions, sorts an array, and returns the elapsed time of these operations. The server runs inside a Docker container and handles GET requests.

---

## Usage Instructions

To build and run the project, follow these steps:

1. **Build the Project:**
   mkdir build && cd build && cmake .. && make
2. **Build the Docker Image**:
docker build -t nadiya1010/my-http-server .

3. **Run the Docker Container**:
 docker run -p 8080:80 nadiya1010/my-http-server
4. **Verify the Server: Open your browser or run**:
   curl http://localhost:8080
5.**Test the Server: Ensure the container is running**:
  docker ps
6.**Send a request to the server**:
curl http://localhost:8080
You should receive a response with the elapsed time of operations and the sorted array.

**Docker Hub**
**The Docker image is available at**:
https://hub.docker.com/r/nadiya1010/my-http-server

**You can pull the image using the command**:
docker pull nadiya1010/my-http-server






