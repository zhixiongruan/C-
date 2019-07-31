cmake_minimum_required(VERSION 3.14)
project(Sorting_Alg)

set(CMAKE_CXX_STANDARD 14)

add_executable(Sorting_Alg SortTestHelper.h SortingAlg.h User.h BinarySearchTree.h UnionFind.h GraphDense.h GraphSparse.h GraphComponent.h mainGraph.cpp GraphPath.h)