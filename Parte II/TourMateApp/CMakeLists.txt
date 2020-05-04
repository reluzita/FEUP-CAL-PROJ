cmake_minimum_required(VERSION 3.15)
project(TourMateApp)

set(CMAKE_CXX_STANDARD 14)
# The line below is necessary if you are under Windows only
# Comment the line below if you are under Linux or Mac OS
link_libraries(ws2_32 wsock32)

include_directories(lib)
include_directories(resources)
include_directories(Graph)
add_executable(TourMateApp main.cpp lib/connection.cpp lib/graphviewer.cpp Utils/ReadFiles.cpp Graph/Graph.cpp Graph/Edge.cpp Graph/Vertex.cpp)
