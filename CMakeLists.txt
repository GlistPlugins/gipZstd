cmake_minimum_required (VERSION 3.10.2)

##### PLUGIN NAME #####
set(pluginname gipZstd)


##### PLUGIN PATHS #####
set(PLUGIN_DIR ${PLUGINS_DIR}/${pluginname})
set(VENDOR_DIR ${PLUGIN_DIR}/vendor)


##### PLUGIN SOURCES #####
list(APPEND PLUGIN_SRCS
			${PLUGIN_DIR}/src/gipZstd.cpp
)


##### PLUGIN HEADERS #####
list(APPEND PLUGIN_INCLUDES
			${PLUGIN_DIR}/src
)

add_subdirectory(${VENDOR_DIR}/zstd/build/cmake zstd)
target_include_directories(zstd PUBLIC ${VENDOR_DIR}/zstd/lib/)

list(APPEND PLUGIN_LINKLIBS
		libzstd_static
)