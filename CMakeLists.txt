cmake_minimum_required(VERSION 3.5)
project( BitSet VERSION 0.1.1 )

add_library(BitSet STATIC src/BitSet.c)

target_include_directories( BitSet PUBLIC ${PROJECT_SOURCE_DIR}/include )
target_sources( BitSet PRIVATE ${PROJECT_SOURCE_DIR}/src/BitSet )
target_sources( BitSet PUBLIC ${PROJECT_SOURCE_DIR}/include/BitSet )

set_target_properties(BitSet
	PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib"
	LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib"
	RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin"
)
