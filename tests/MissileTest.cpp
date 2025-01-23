#include <gtest/gtest.h>
#include "Missile.h"

// Assuming Missile class has the following methods:
// - void launch()
// - void setTarget(const std::string& target)
// - std::string getTarget() const
// - bool isLaunched() const

class MissileTest : public ::testing::Test {
protected:
    Missile missile;

    void SetUp() override {
        // Code here will be called immediately after the constructor (right before each test).
    }

    void TearDown() override {
        // Code here will be called immediately after each test (right before the destructor).
    }
};

TEST_F(MissileTest, LaunchTest) {
    missile.launch();
    EXPECT_TRUE(missile.isLaunched());
}

TEST_F(MissileTest, SetTargetTest) {
    std::string target = "Target1";
    missile.setTarget(target);
    EXPECT_EQ(missile.getTarget(), target);
}

TEST_F(MissileTest, GetTargetTest) {
    std::string target = "Target2";
    missile.setTarget(target);
    EXPECT_EQ(missile.getTarget(), target);
}

TEST_F(MissileTest, IsLaunchedTest) {
    EXPECT_FALSE(missile.isLaunched());
    missile.launch();
    EXPECT_TRUE(missile.isLaunched());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
