### Docker Hub:
Образ доступний за посиланням: [nadiya1010/my-http-server](https://hub.docker.com/r/nadiya1010/my-http-server)

How to Build the Project
1. Clone the repository:
git clone https://github.com/NadiaBatrynchuk/debian-package-project.git
cd debian-package-project
git checkout branchHTTPServer
2. Build the project: Ensure you have g++ installed. Use the provided Makefile to build the project:
   make
This will generate the server executable.
How to Run the Docker Container
1. Pull the Docker image from Docker Hub:
   docker pull nadiya1010/my-http-server
2. Run the Docker container:
   docker run -p 8080:80 nadiya1010/my-http-server
If port 8080 is already in use, use another port:
docker run -p 8081:80 nadiya1010/my-http-server
Access the server in your browser or using tools like curl:
http://localhost:8080
How to Test the Server
Unit Tests: Run the tests locally:
make test
Manual Testing: Send a GET request using curl
curl http://localhost:8080



