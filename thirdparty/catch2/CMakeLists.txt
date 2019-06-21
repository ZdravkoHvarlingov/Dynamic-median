project(Catch2Testing)

# Header only library => INTERFACE
add_library(Catch2 INTERFACE)

# INTERFACE targets have only INTERFACE properties
target_include_directories(Catch2 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(Catch2 INTERFACE cxx_std_11)