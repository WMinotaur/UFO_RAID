#include <gtest/gtest.h>
#include "Ship.h"

// Assuming Ship class has methods: getName(), getLength(), and getSpeed()

class ShipTest : public ::testing::Test {
protected:
    Ship* ship;

    void SetUp() override {
        ship = new Ship(Color (12,214,132));
    }

    void TearDown() override {
        delete ship;
    }
};




TEST_F(ShipTest, move) {
    GameElementPosition* pos = ship->getPosition();
    ship->move(900.f, 1000.f);
    EXPECT_EQ( ship->getPosition()->x, pos->x );
    EXPECT_EQ(ship->getPosition()->y, pos->y);
}

