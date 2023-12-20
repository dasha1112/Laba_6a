set(target ${MP3_LIBRARY})

file(GLOB hdrs "*.h*" "${MP3_INCLUDE}/*.h*")
file(GLOB srcs "*.cpp")

add_library(${target} STATIC ${srcs} ${hdrs})
target_link_libraries(${target} ${LIBRARY_DEPS})
