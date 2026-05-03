cmake_minimum_required(VERSION 3.20)
project({{CT_PROJECT_NAME}}
	VERSION 0.1
	LANGUAGES C
)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(EXTERNAL_LIBS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external)
set({{CT_PROJECT_NAME}UPPER}_CFLAGS 
	-Wall
	-Wextra
	-Wpedantic
	-Werror
	-g3
	# -fsanitize=address
	# -fsanitize=undefined
)

add_executable({{CT_PROJECT_NAME}})

target_compile_definitions({{CT_PROJECT_NAME}} PRIVATE LOGFILE={{CT_PROJECT_NAME}}.log)

target_include_directories({{CT_PROJECT_NAME}} PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_sources({{CT_PROJECT_NAME}} PRIVATE
	src/main.c

	src/parser/parse_cli.c

	src/utils/debug.c
	src/utils/misc.c
)


target_compile_options({{CT_PROJECT_NAME}} PRIVATE 
	${{{CT_PROJECT_NAME}UPPER}_CFLAGS}
)

target_link_options({{CT_PROJECT_NAME}} PRIVATE
	${{{CT_PROJECT_NAME}UPPER}_CFLAGS}
)

#[[
add_library(cjson STATIC
	${EXTERNAL_LIBS_DIR}/cjson/cjson.c
)

target_include_directories(cjson PUBLIC
	${EXTERNAL_LIBS_DIR}/cjson
)

target_link_libraries(a PRIVATE cjson)
]]
