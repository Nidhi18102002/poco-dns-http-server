# POCO DNS & HTTP Server Project

## Developer
Nidhi C N

## Overview
This project demonstrates a DNS Resolver and HTTP Server built using POCO C++ Libraries.  
It supports DNS lookups, HTTP request handling, caching, and route-based responses.

## Development Timeline
| Day | Task |
|-----|------|
| 1 | Setup environment and learned DNS basics |
| 2 | Implemented DNS/HTTP query handling |
| 3 | Added persistent POCO server |
| 4 | Added recursive routing and dynamic pages |
| 5 | Testing, optimization, and documentation |

## Tech Stack
- Language: C++17  
- Libraries: POCO (Net, Util, Foundation)  
- Build System: CMake  
- OS: Linux  

## How to Run
mkdir build && cd build  
cmake ..  
make  
./poco_server  

Then open your browser and visit:  
http://127.0.0.1:9090/

## Routes
| Route | Description |
|--------|--------------|
| `/` | Welcome page |
| `/about` | About the project |
| `/hello` | Greeting message |
| `/time` | Displays current server time |
| `/xyz` | 404 page |

## License
This project is open-source and available under the MIT License.
