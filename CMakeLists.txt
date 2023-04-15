cmake_minimum_required(VERSION 3.21)
project(Vigenere_Cipher)

set(CMAKE_CXX_STANDARD 14)

add_executable(Vigenere_Cipher main.cpp lib/read_file.cpp lib/read_file.h lib/Index_of_Coincidence.cpp lib/Index_of_Coincidence.h lib/CipherLib.cpp lib/CipherLib.h lib/Vigenere_Lib.cpp lib/Vigenere_Lib.h)

add_subdirectory(Google_tests)