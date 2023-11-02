cmake_minimum_required(VERSION 3.10)
project(SFMLProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the SFML library
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:/SFML-2.6.0/lib/cmake/SFML") 
find_package(SFML 2.6 COMPONENTS system window graphics network audio REQUIRED)

file(GLOB_RECURSE ASTERI_SRC_FILES CONFIGURE_DEPENDS
    "./src/*.cpp"
)

# Add your source files here
add_executable(main ${ASTERI_SRC_FILES})

# Link your executable to SFML
target_link_libraries(main PRIVATE sqlite3 sfml-system sfml-window sfml-graphics sfml-network sfml-audio opengl32)
target_include_directories(main PRIVATE ./headers)

# cmake -S. -Bbuild -G "MinGW Makefiles"
# cmake --build build
# cmake --build build --verbose
# build/main 