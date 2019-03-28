#Bring in the headers
include_directories(include)
 
#To manually add the sources:
#set(SOURCES src/file1.cpp src/file2.cpp)
 
#Or automatically:
file(GLOB SOURCES "*.cpp")
 
add_executable(Inebriator ${SOURCES})
target_link_libraries(Inebriator wiringPi wiringPiDev)
