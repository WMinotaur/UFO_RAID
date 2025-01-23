#include <gtest/gtest.h>
#include "GameElement.h"

// Assuming GameElement class has methods: getName(), getPosition(), setPosition(), and update()

class GameElementTest : public ::testing::Test {
protected:
    GameElement element;

    void SetUp() override {
        // Initialize the GameElement object
        element = GameElement();
    }
};


TEST_F(GameElementTest, getPosition) {
    GameElementPosition* position = element.getPosition();
    EXPECT_EQ(position->x, 0);
    EXPECT_EQ(position->y, 0);
}
