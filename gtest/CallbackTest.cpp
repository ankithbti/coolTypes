#include <gtest/gtest.h>
#include <Callback.hpp>
#include <iostream>

class MyClass {
public:
    int myFunct(int a, std::string s){
        std::cout << " MyClass::myFunct() " << s << std::endl;
        return (int)a;
    }
};

class YourClass {
public:
    std::string yourFunct() {
        std::cout << " YourClass::yourFunct() " << std::endl;
        return "SUCCESS";
    }
};

TEST(CallbackTest, Test_1){
    MyClass myClass;
    coolTypes::Callback<MyClass, int, int, std::string> myCallback(myClass, &MyClass::myFunct);
    EXPECT_EQ(myCallback(1, "TEST"), 1);
}

//TEST(CallbackTest, Test_2){
//    MyClass myClass;
//    coolTypes::Callback<MyClass, int, int> myCallback(myClass, &MyClass::myFunct);
//    EXPECT_NE(myCallback(2), 2);
//}

TEST(CallbackTest, Test_3){
    YourClass yourClass;
    coolTypes::Callback<YourClass, std::string> yourCallback(yourClass, &YourClass::yourFunct);
    EXPECT_STREQ(yourCallback().c_str(), "SUCCESS");
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
