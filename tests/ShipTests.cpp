#include <gtest/gtest.h>
#include "Ship.h"

// Assuming Ship class has methods: getName(), getLength(), and getSpeed()

class ShipTest : public ::testing::Test {
protected:
    Ship* ship;

    void SetUp() override {
        ship = new Ship("Titanic", 269.1, 23.0);
    }

    void TearDown() override {
        delete ship;
    }
};

TEST_F(ShipTest, GetName) {
    EXPECT_EQ(ship->getName(), "Titanic");
}

TEST_F(ShipTest, GetLength) {
    EXPECT_DOUBLE_EQ(ship->getLength(), 269.1);
}

TEST_F(ShipTest, GetSpeed) {
    EXPECT_DOUBLE_EQ(ship->getSpeed(), 23.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
