#include "NetworkingCommonUnitTestsPch.hpp"
#include "Conversion/HostToNetworkTests.hpp"
#include "NetworkingCommon.hpp"


UTEST(Add, WhenAddingTwoIntsResultIsCorrect) {
    // Arrange
    int x = 2;
    int y = 5;
    // Act
    int result = Bender::Add(x, y);
    // Assert
    ASSERT_EQ(7, result);
}

UTEST_MAIN()