# TCP_Santa
TCP Santa  project connects to a server via TCP protocol and reads a compressed string, parses the string while interpretting it based on the instructions given. It finally uploads the result to the server and waits for a response.
## Dependencies
* C++ Boost - *Version specified in ```conanfile.txt```*

## Setup
This project's packages are managed using conan. 

```bash
pip install --user conan
```

The project also uses cmake and ninja generators.
```bash
sudo apt install build-essential cmake ninja-build 
```

## Usage

There an assistive build script to build the project.
```bash
    chmod +a build.sh  && ./build.sh 
```




