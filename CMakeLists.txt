cmake_minimum_required (VERSION 3.10.2)

##### PLUGIN NAME #####
set(pluginname gipZstd)


##### PLUGIN PATHS #####
set(PLUGIN_DIR ${PLUGINS_DIR}/${pluginname})
set(PLUGIN_LIBS_DIR ${PLUGIN_DIR}/libs)


##### PLUGIN SOURCES #####
list(APPEND PLUGIN_SRCS
			${PLUGIN_DIR}/src/gipZstd.cpp
)


##### PLUGIN HEADERS #####
list(APPEND PLUGIN_INCLUDES
			${PLUGIN_DIR}/src
)

add_subdirectory(${PLUGIN_LIBS_DIR}/src/zstd/build/cmake zstd)
target_include_directories(zstd PUBLIC ${PLUGIN_LIBS_DIR}/src/zstd/lib/)

list(APPEND PLUGIN_LINKLIBS
		libzstd_static
)