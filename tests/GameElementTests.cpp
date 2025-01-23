#include <gtest/gtest.h>
#include "GameElement.h"

// Assuming GameElement class has methods: getName(), getPosition(), setPosition(), and update()

class GameElementTest : public ::testing::Test {
protected:
    GameElement element;

    void SetUp() override {
        // Initialize the GameElement object
        element = GameElement("TestElement", 0, 0);
    }
};

TEST_F(GameElementTest, GetName) {
    EXPECT_EQ(element.getName(), "TestElement");
}

TEST_F(GameElementTest, GetPosition) {
    auto position = element.getPosition();
    EXPECT_EQ(position.first, 0);
    EXPECT_EQ(position.second, 0);
}

TEST_F(GameElementTest, SetPosition) {
    element.setPosition(10, 20);
    auto position = element.getPosition();
    EXPECT_EQ(position.first, 10);
    EXPECT_EQ(position.second, 20);
}

TEST_F(GameElementTest, Update) {
    element.update();
    // Assuming update method changes the position in some way
    auto position = element.getPosition();
    // Check the expected new position after update
    EXPECT_NE(position.first, 0);
    EXPECT_NE(position.second, 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
