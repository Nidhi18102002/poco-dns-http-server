#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/StreamCopier.h>
#include <Poco/URI.h>
#include <iostream>
#include <sstream>

using namespace Poco::Net;
using namespace Poco;
using namespace std;

int main(int argc, char** argv)
{
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <url>" << endl;
        return 1;
    }

    string url = argv[1];
    try {
        URI uri(url);
        string path(uri.getPathAndQuery());
        if (path.empty()) path = "/";

        HTTPClientSession session(uri.getHost(), uri.getPort());
        HTTPRequest request(HTTPRequest::HTTP_GET, path, HTTPMessage::HTTP_1_1);
        session.sendRequest(request);

        HTTPResponse response;
        istream& responseStream = session.receiveResponse(response);
        cout << "Response: " << response.getStatus() << " " << response.getReason() << endl;

        stringstream ss;
        StreamCopier::copyStream(responseStream, ss);
        cout << "\n--- Response Body (first 500 chars) ---\n";
        cout << ss.str().substr(0, 500) << endl;
    }
    catch (Exception& ex) {
        cerr << "Error: " << ex.displayText() << endl;
    }

    return 0;
}
