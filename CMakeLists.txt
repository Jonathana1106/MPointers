cmake_minimum_required(VERSION 3.12)
project(MPointers)

set(CMAKE_CXX_STANDARD 14)

add_executable(MPointers main.cpp MPointer/MPointerGC.h Structures/Simple_list.h MPointer/MPointer.cpp MPointer/MPointer.h Sort/Swap.h Sort/PrintSort.h Sort/Partition.h Sort/BubbleSort.h Sort/QuickSort.h Sort/InsertionSort.h Structures/Simple_list.cpp MPointer/MPointerGC.cpp)


target_link_libraries(MPointers pthread)