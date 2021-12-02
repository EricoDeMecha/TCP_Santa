#ifndef TCP_SANTA_H
#define TCP_SANTA_H

#include <iostream>
#include <boost/asio.hpp>
#include <boost/range/algorithm.hpp>
#include <functional>
#include <string>

struct  TCP_Santa{
    TCP_Santa(std::string& raw_ip_address, unsigned short& port_num):
    socket(ios,ep.protocol()),
    ep(boost::asio::ip::address::from_string(raw_ip_address), port_num){
        try {
            socket.connect(ep);
            std::cout << "Connection successful" << '\n';
        }catch(boost::system::system_error& e){
            throw boost::system::system_error(e.code());
        }
    }
    ~TCP_Santa(){
        socket.close();
    };
    std::string readMessage(boost::system::error_code& ec){
        std::string r_message;
        std::stringstream message_stream;
        boost::asio::streambuf  buffer;
        size_t len = boost::asio::read_until(socket, buffer, '\n', ec);
        if(len){
            message_stream.write(boost::asio::buffer_cast<const char*>(buffer.data()), len);
            r_message = message_stream.str();
        }
        return r_message;
    }
    static size_t countFloors(const std::string& floor_count){
        size_t count_up = boost::range::count(floor_count, '(');
        size_t count_down = boost::range::count(floor_count, ')');
        return count_up - count_down;
    }
    void writeFloors(std::basic_string<char> message, boost::system::error_code& ec){
        socket.write_some(boost::asio::buffer(message.data(), message.size()), ec);
    }
private:
    boost::asio::ip::tcp::endpoint ep;
    boost::asio::io_service ios;
    boost::asio::ip::tcp::socket socket;
};

#endif