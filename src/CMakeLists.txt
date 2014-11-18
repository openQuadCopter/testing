SET( testingCode_SRCS 
	${testing_SOURCE_DIR}/src/i2cCom.cpp
	${testing_SOURCE_DIR}/src/main.cpp	
)

SET( testingCode_HDRS 
	${testing_SOURCE_DIR}/include/i2cCom.h
)

ADD_EXECUTABLE(test ${testingCode_SRCS} )
TARGET_LINK_LIBRARIES(test m)

INSTALL( TARGETS test DESTINATION bin)
INSTALL( FILES ${testingCode_HDRS} DESTINATION include)
