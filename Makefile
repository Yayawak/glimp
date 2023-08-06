appName = myOpenGLApplication
buildDir = ./bin
# cppFiles = ./src/*.cpp
# cppFiles = ./src/**/*.cpp

appDefines:=
appIncludes:= -I./src/vendors/GLFW -framework Cocoa -framework OpenGL -framework IOKit
# appLinkers:= -L./src/vendors/GLFW/lib -lglfw3 -L./src/vendors/libs -lSOIL
# NOTE : don't include SOIL becuase we use <stb/image....h> which already included SOIL
appLinkers:= -L./src/vendors/GLFW/lib -lglfw3
# incPaths = ./src/inc/*.hpp
exsPaths = ./src/exs/*.cpp 

structureFiles = ./src/structure/*.cpp
# structureHeaders = ./src/structure/headers/*.hpp

test: build run

build:
# g++ $(incPaths) $(exsPaths) src/main.cpp $(appIncludes) $(appLinkers)
# g++ $(exsPaths) src/main.cpp $(appIncludes) $(appLinkers)
# g++ $(incPaths) $(exsPaths) src/main.cpp $(appIncludes) $(appLinkers)
# g++ $(incPaths) $(exsPaths) src/main.cpp -o $(buildDir)/$(appName) $(appIncludes) $(appLinkers)
# g++ $(exsPaths) src/main.cpp -o $(buildDir)/$(appName) $(appIncludes) $(appLinkers)
# ? For Develope modern gl structure application
	g++ $(structureFiles) $(exsPaths) src/main.cpp -o $(buildDir)/$(appName) $(appIncludes) $(appLinkers)
# g++ $(structureFiles) $(exsPaths) src/main.cpp -o $(buildDir)/$(appName) $(appIncludes) $(appLinkers)
# g++ $(structureFiles) src/main.cpp -o $(buildDir)/$(appName) $(appIncludes) $(appLinkers)
# g++ src/structure/shaderClass.cpp src/main.cpp -o $(buildDir)/$(appName) $(appIncludes) $(appLinkers)
# g++  $(cppFiles) -o $(buildDir)/$(appName) $(appIncludes) $(appLinkers)
# g++ -Wc++11-extensions $(cppFiles) -o $(buildDir)/$(appName) $(appIncludes) $(appLinkers)
# clang $(cppFiles) -o $(buildDir)/$(appName) $(appIncludes) $(appLinkers)

run:
	./bin/$(appName)

