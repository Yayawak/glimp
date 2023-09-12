appName = myOpenGLApplication
buildDir = ./bin
# cppFiles = ./src/*.cpp
# cppFiles = ./src/**/*.cpp

appDefines:=
# appIncludes:= -I./src/vendors/GLFW -framework Cocoa -framework OpenGL -framework IOKit
appIncludes:= -I./src/vendors/GLFW -framework Cocoa -framework OpenGL -framework IOKit
# appLinkers:= -L./src/vendors/GLFW/lib -lglfw3 -L./src/vendors/libs -lSOIL
# NOTE : don't include SOIL becuase we use <stb/image....h> which already included SOIL
appLinkers:= -L./src/vendors/GLFW/lib -lglfw3
# incPaths = ./src/inc/*.hpp
exsPaths = ./src/exs/*.cpp ./src/exs/**/*.cpp

# structureFiles = ./src/structure/*.cpp /usr/local/include/common/shader.cpp
structureFiles = ./src/structure/*.cpp src/structure/**/*.cpp
# structureFiles = ./src/structure/*.cpp 
# structureHeaders = ./src/structure/headers/*.hpp
runFlags = -std=c++11

# * ------------------ SNAKE GAME ---------------------------
snakeGameName = snake-game
# snakeMainSrc = `find applications/snakegame -name "mainsnake.cpp"`
snakeMainSrc = applications/snakegame/mainsnake.cpp
# snakeAllSrc = application/snakegame/*.cpp application/snakegame/**/.cpp
# snakeAllSrc = ${find applications/snakegame -name "*.cpp" ! -name "mainsnake.cpp"}
snakeAllSrc = `find applications/snakegame -name "*.cpp" ! -name "mainsnake.cpp"`
# snakeAllSrc = find applications/snakegame -name "*.cpp" ! -name "mainsnake.cpp"

all: snake
# all:
# 	echo $(snakeAllSrc)

test: build run

build:
# g++ $(incPaths) $(exsPaths) src/main.cpp $(appIncludes) $(appLinkers)
# g++ $(exsPaths) src/main.cpp $(appIncludes) $(appLinkers)
# g++ $(incPaths) $(exsPaths) src/main.cpp $(appIncludes) $(appLinkers)
# g++ $(incPaths) $(exsPaths) src/main.cpp -o $(buildDir)/$(appName) $(appIncludes) $(appLinkers)
# g++ $(exsPaths) src/main.cpp -o $(buildDir)/$(appName) $(appIncludes) $(appLinkers)
# ? For Develope modern gl structure application
	g++ ${runFlags} $(structureFiles) $(exsPaths) src/main.cpp -o $(buildDir)/$(appName) $(appIncludes) $(appLinkers)
# g++ $(structureFiles) $(exsPaths) src/main.cpp -o $(buildDir)/$(appName) $(appIncludes) $(appLinkers)
# g++ $(structureFiles) src/main.cpp -o $(buildDir)/$(appName) $(appIncludes) $(appLinkers)
# g++ src/structure/shaderClass.cpp src/main.cpp -o $(buildDir)/$(appName) $(appIncludes) $(appLinkers)
# g++  $(cppFiles) -o $(buildDir)/$(appName) $(appIncludes) $(appLinkers)
# g++ -Wc++11-extensions $(cppFiles) -o $(buildDir)/$(appName) $(appIncludes) $(appLinkers)
# clang $(cppFiles) -o $(buildDir)/$(appName) $(appIncludes) $(appLinkers)

run:
	./bin/$(appName)


snake: buildsnake
	./bin/$(snakeGameName)
buildsnake:
# g++ ${runFlags} $(structureFiles) $(exsPaths) src/main.cpp -o $(buildDir)/$(snakeGameName) $(appIncludes) $(appLinkers)
# g++ ${runFlags} $(structureFiles) $(exsPaths) -o $(buildDir)/$(snakeGameName) $(appIncludes) $(appLinkers)
# echo ${snakeAllSrc} 
# g++ ${runFlags} ${structureFiles} ${snakeAllSrc} ${snakeMainSrc} 
# g++ ${runFlags} ${structureFiles} ${snakeAllSrc} ${snakeMainSrc} -o ${buildDir}/$(snakeGameName) $(appLinkers)
# g++ ${runFlags} ${structureFiles} ${snakeAllSrc} ${snakeMainSrc} -o ${buildDir}/$(snakeGameName) $( appIncludes )
	g++ -pthread ${runFlags} $(structureFiles) $(snakeAllSrc) $(snakeMainSrc) -o $(buildDir)/$(snakeGameName) $(appIncludes) $(appLinkers)