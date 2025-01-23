#include <gtest/gtest.h>
#include "Missile.h"

// Assuming Missile class has the following methods:
// - void launch()
// - void setTarget(const std::string& target)
// - std::string getTarget() const
// - bool isLaunched() const

class MissileTest : public ::testing::Test {
protected:
    Missile* missile;
    

    void SetUp() override {
        missile = (Missile*)MissileFactory(enemy, 0, 0);// Code here will be called immediately after the constructor (right before each test).
    }
    
    void TearDown() override {
        delete missile;// Code here will be called immediately after each test (right before the destructor).
    }
};

TEST_F(MissileTest, toBeDeleted) {
    missile->Delete();
    EXPECT_TRUE(missile->toBeDeleted());
}

TEST_F(MissileTest, detectOutOfScreen) {
    float height{ 0.0f };
    missile->detectOutOfScreen(height);
    EXPECT_TRUE(missile->toBeDeleted());
}




