cmake_minimum_required(VERSION 3.15)
project(Mage)

set(CMAKE_CXX_STANDARD 17)

add_executable(Mage main.cpp sources/GameScene.cpp headers/GameScene.h headers/Scene.h headers/Player.h headers/GameObject.h sources/Player.cpp sources/Enemy.cpp headers/Enemy.h headers/Utils.h headers/ColliderObject.h sources/ColliderObject.cpp)

include_directories(headers /usr/include D:/SFML/include)
set(SFML_ROOT D:/SFML)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Mage ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Copy dlls to build

if (WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/mingw64/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif ()
