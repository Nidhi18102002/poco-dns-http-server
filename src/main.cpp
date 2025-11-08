#include <iostream>
#include <Poco/Net/DNS.h>
#include <Poco/Net/HostEntry.h>
#include <Poco/Net/IPAddress.h>
#include <Poco/Exception.h>

int main(int argc, char** argv) {
    std::string host = (argc > 1) ? argv[1] : "example.com";

    try {
        Poco::Net::HostEntry entry = Poco::Net::DNS::hostByName(host);
        std::cout << "Host: " << entry.name() << std::endl;

        for (const auto& addr : entry.addresses())
            std::cout << "  - " << addr.toString() << std::endl;
    }
    catch (const Poco::Exception& ex) {
        std::cerr << "POCO Exception: " << ex.displayText() << std::endl;
        return 1;
    }
}
