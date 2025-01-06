# --------------------------------------------------------------------------------------------------
# TinyXML-2
# @see https://github.com/leethomason/tinyxml2
# --------------------------------------------------------------------------------------------------

# Required version
set(TINY_XML_VERSION 10.0.0)

message("TinyXML-2 v${TINY_XML_VERSION}")

# Define where to obtain it from
include(FetchContent)
FetchContent_Declare(
        tinyxml2
        URL https://github.com/leethomason/tinyxml2/archive/refs/tags/${TINY_XML_VERSION}.tar.gz
        FIND_PACKAGE_ARGS ${TINY_XML_VERSION}
)

# Library specific configuration
set(BUILD_TESTING OFF CACHE INTERNAL "")

# Make package available
FetchContent_MakeAvailable(tinyxml2)

# Finally, link to the library
target_link_libraries(${PROJECT_NAME} tinyxml2::tinyxml2)