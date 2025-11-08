#include "Poco/Net/HTTPServer.h"
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Util/ServerApplication.h"
#include <iostream>
#include <ctime>

using namespace Poco::Net;
using namespace Poco::Util;
using namespace std;

// ---------- Request Handler ----------
class MyRequestHandler : public HTTPRequestHandler {
public:
    void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response) override {
        string path = request.getURI();
        cout << "Incoming request: " << path << endl;

        response.setStatus(HTTPResponse::HTTP_OK);
        response.setContentType("text/html");
        ostream& out = response.send();

        if (path == "/") {
            out << "<html><body><h1>Welcome!</h1>"
                << "<p>This is the root page of your POCO Server.</p>"
                << "<ul>"
                << "<li><a href='/about'>About</a></li>"
                << "<li><a href='/hello'>Hello</a></li>"
                << "<li><a href='/time'>Time</a></li>"
                << "</ul></body></html>";
        } else if (path == "/about") {
            out << "<html><body><h1>About Page</h1>"
                << "<p>This server is built using POCO C++ libraries.</p></body></html>";
        } else if (path == "/hello") {
            out << "<html><body><h1>Hello,from Nidhi. Have a nice day!</h1>"
                << "<p>This is a custom route response.</p></body></html>";
        } else if (path == "/time") {
            time_t now = time(0);
            out << "<html><body><h1>Current Server Time</h1><p>"
                << ctime(&now) << "</p></body></html>";
        } else {
            response.setStatus(HTTPResponse::HTTP_NOT_FOUND);
            out << "<html><body><h1>404 - Not Found</h1>"
                << "<p>The page you requested (" << path << ") does not exist.</p>"
                << "<a href='/'>Go Home</a></body></html>";
        }

        out.flush();
    }
};

// ---------- Handler Factory ----------
class MyRequestHandlerFactory : public HTTPRequestHandlerFactory {
public:
    HTTPRequestHandler* createRequestHandler(const HTTPServerRequest&) override {
        return new MyRequestHandler;
    }
};

// ---------- Server Application ----------
class MyServerApp : public ServerApplication {
protected:
    int main(const std::vector<std::string>& args) override {
        HTTPServer server(new MyRequestHandlerFactory, ServerSocket(9090), new HTTPServerParams);
        server.start();
        cout << "✅ Server running at http://127.0.0.1:9090" << endl;
        cout << "🖱  Try visiting /about, /hello, /time, or a random path!" << endl;
        waitForTerminationRequest();  // Wait for Ctrl+C
        server.stop();
        return Application::EXIT_OK;
    }
};

POCO_SERVER_MAIN(MyServerApp)

