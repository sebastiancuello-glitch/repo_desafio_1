cmake_minimum_required(VERSION 3.16)

project(desafio1_tetris LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(desafio1_tetris
    tablero.h
    tablero.cpp
    pieza.h
    pieza.cpp
    juego.h
    juego.cpp
    main.cpp
)

include(GNUInstallDirs)
install(TARGETS desafio1_tetris
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
