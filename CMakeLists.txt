cmake_minimum_required(VERSION 3.15)
project(nmap++ VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Avertissements stricts.
add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(nmappp
    src/main.cpp
)

# Linux nécessite de linker pthread pour std::thread.
find_package(Threads REQUIRED)
target_link_libraries(nmappp PRIVATE Threads::Threads)
