cmake_minimum_required(VERSION 2.8)

# Set Policies
if(POLICY CMP0048)
  cmake_policy(SET CMP0048 NEW)
endif()

if(POLICY CMP0023)
  cmake_policy(SET CMP0023 NEW)
endif()

if(POLICY CMP0079)
  cmake_policy(SET CMP0079 NEW)
endif()

add_compile_options(-std=c++11)


##########################################################

# https://stackoverflow.com/questions/43862273/cmake-c-include-relative-to-base-directory
project(Railroad VERSION 1.0)

add_subdirectory(pokemon_testing)
add_subdirectory(graph_testing)
