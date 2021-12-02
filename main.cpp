#include "tcp_santa.hpp"

int main(){
    std::string raw_ip_address = "20.108.244.219";
    unsigned int short port = 9990;
    try{
        // connect and read the floor message
        TCP_Santa santa(raw_ip_address, port);
        boost::system::error_code ec;
        std::string response = santa.readMessage(ec);
        std::cout << response << '\n';
        // process the floor message
        size_t f_c = TCP_Santa::countFloors(response);
        std::cout << f_c << '\n';
        // send the response to server
        santa.writeFloors(std::to_string(f_c), ec);
        // read the response
        std::string f_message = santa.readMessage(ec);
        std::cout << f_message << '\n';
    }catch(boost::system::system_error& e){
        std::cerr << "Error! Error code: " << e.code() << \
                        " Message: " << e.what();
    }
    return 0;
}