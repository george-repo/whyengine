cmake_minimum_required(VERSION 2.6)
project(WHYENGINE)

string(TOLOWER "${CMAKE_CXX_COMPILER_ID}" COMP)
string(TOLOWER "${CMAKE_SYSTEM_NAME}" PLATFORM)
string(TOLOWER "${CMAKE_SYSTEM_PROCESSOR}" ARCH)
message("${COMP}-${PLATFORM}-${ARCH}")

add_definitions(-DSDL_MAIN_HANDLED)

if(MINGW)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s -static")
  add_definitions(-DGLEW_STATIC)
  set(STATIC_LIBS imm32 iconv winmm ole32 gdi32 oleaut32 version)
  set(LIBGLEW glew32)
  set(LIBSDL2 SDL2)
elseif(MSVC)
  add_definitions(-DGLEW_STATIC)
  set(STATIC_LIBS imm32 winmm setupapi version)
  set(LIBGLEW glew32s)
  set(LIBSDL2 SDL2-static)
endif()

include_directories(
	src
	${PROJECT_SOURCE_DIR}/contrib/${COMP}-${PLATFORM}-${ARCH}/include
)

link_directories(
	${PROJECT_SOURCE_DIR}/contrib/${COMP}-${PLATFORM}-${ARCH}/lib
)

add_library(whyengine
	src/whyengine/Core.cpp
 	src/whyengine/Entity.cpp
 	src/whyengine/Component.cpp
 	src/whyengine/Renderer.cpp

	src/whyengine/Exception.cpp
	src/whyengine/Exception.h
	
	src/whyengine/Core.h
 	src/whyengine/Entity.h
 	src/whyengine/Component.h
 	src/whyengine/Renderer.h
)
add_library(rend
  	src/rend/Exception.cpp
  	src/rend/Context.cpp
  	src/rend/Texture.cpp
  	src/rend/RenderTexture.cpp
  	src/rend/Shader.cpp
  	src/rend/Buffer.cpp
  	src/rend/Mesh.cpp
  	src/rend/Util.cpp
)

if(MSVC OR MINGW)
  	target_link_libraries(rend ${LIBGLEW} opengl32)
else()
  	target_link_libraries(rend GLEW GL)
endif()

target_link_libraries(whyengine rend ${LIBSDL2} ${STATIC_LIBS})

add_executable(engine
	src/engine/main.cpp
)
target_link_libraries(engine whyengine)
