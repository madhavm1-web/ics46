    // Tests for Introduction Lab (C++) mirroring the provided Java autograder
    
    #include <gtest/gtest.h>
    
    // Access Bag::contents for deterministic setup like the Java tests
    #define private public
    #include "Bag.hpp"
    #undef private
    #include "Token.hpp"
    
    #include <string>
    #include <vector>
    
    namespace {
    
    // Helper to set up a Bag with deterministic contents and compute expectations
    struct BagSetupResult {
        int sum{};
        int num_high{};
        int first_green{-1};
    };
    
    BagSetupResult setupBagWithKnownContents(Bag& bag) {
        static const int NUM_TOKENS = 16;
        static const std::vector<std::string> colors = {
            "Red", "Yellow", "Green", "Cyan", "Green",
            "Blue", "Violet", "Green"
        };
    
        BagSetupResult r;
        // The bag was constructed with NUM_TOKENS size; fill deterministically
        for (int i = 0; i < NUM_TOKENS; ++i) {
            int value = i % Token::MAX_VALUE; // MAX_VALUE is 10
            const std::string& color = colors[static_cast<size_t>(i) % colors.size()];
    
            bag.contents[static_cast<size_t>(i)].setValue(value);
            bag.contents[static_cast<size_t>(i)].setColor(color);
    
            r.sum += value;
            if (value > Token::MAX_VALUE / 2)
                r.num_high++;
            if (color == "Green" && r.first_green < 0)
                r.first_green = i;
        }
        return r;
    }
    
    } // namespace
    
    // --- Token tests ---
    
    TEST(TokenTests, GetValueReturnsAsConstructed) {
        Token t1{"None", 1};
        Token t10{"None", 10};
        EXPECT_EQ(1, t1.getValue());
        EXPECT_EQ(10, t10.getValue());
    }
    
    TEST(TokenTests, SetValueChangesValue) {
        Token t{"None", 1};
        t.setValue(6);
        EXPECT_EQ(6, t.getValue());
    }
    
    // TODO: Add additional tests for the Token class
    //Wirte tests for the token class as follows 
    TEST(TokenTests, IsMaxCorrectlyIdentified)
    {
        Token tLow{"Red", 5};
        Token tMax{"Red", 10};
        EXPECT_FALSE(tLow.isMax());
        EXPECT_TRUE(tMax.isMax());
    }
    
    TEST(TokenTests, IsHighValueCorrectlyIdentified)
    {
        Token t5 {"Blue", 5};
        Token t6 {"Blue", 6};
        EXPECT_FALSE(t5.isHighValue());
        EXPECT_TRUE(t6.isHighValue()); //Fixed is true value
    }
    
    
    TEST(TokenTests, ToStringFormatIsCorrect)
    {
        Token t {"Green", 7};
        std::string expected = "Token's color is Green and has value 7";
        EXPECT_EQ(expected, t.toString()); //Added semicolon
    }
    
    // --- Bag tests ---
    // TODO: Add your own tests for the Bag class
    
    TEST(BagTests, AddTokensReturnsCorrectSum)
    {
        Bag bag(16); 
        //Added BagSetupResult and I passed the object Bag into the function
        BagSetupResult r = setupBagWithKnownContents(bag);
    
        EXPECT_EQ(r.sum, bag.addTokens());
    
    }
    
    //We then make the following
    TEST(BagTests, HighValueTokensReturnsCorrectCount)
    {
        Bag bag(16); 
        BagSetupResult r = setupBagWithKnownContents(bag);// Fill  the bag with known contents
        EXPECT_EQ(r.num_high, bag.highValueTokens());   
    }

//We write the tests as follows 
TEST(BagTests, FirstGreenIndexFound)
{
    Bag bag(16); 
    BagSetupResult r = setupBagWithKnownContents(bag);

    EXPECT_EQ(r.first_green, bag.firstGreen());
}
     
TEST(BagTests, FirstGreenReturnsNegativeOneIfNone)
{
        Bag bag(5); 
        for(int i = 0; i<5; i++)
            {
                bag.contents[i].setColor("Red");
            }
    EXPECT_EQ(-1, bag.firstGreen()); //Added
}
    


