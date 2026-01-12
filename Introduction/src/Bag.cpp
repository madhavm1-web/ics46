#include "Bag.hpp"
#include <iostream>
#include <iomanip> 

/**
 * A Bag is a collection of Tokens (chips) that supports
 * functions that work by enumerating the contents.
 *
 * @author: Madhav Malhotra
 */

Bag::Bag(int numTokens) : contents(numTokens) {}

void Bag::firstToken() const {
    if (!contents.empty())
        std::cout << contents[0].toString() << std::endl;
}

void Bag::allTokens() const {
    for (const auto& token : contents) {
        // TODO: print out the currently chosen Token
        std::cout<<token.toString()<<std::endl;     
    }
}

void Bag::allTokensWhile() const {
    size_t i = 0;
    // TODO: turn this into a while loop that enumerates and
    // prints all of the tokens in the bag
    while (i<contents.size()) 
    {
         std::cout<<contents[i].toString()<<std::endl;
        i++;
    }
}

int Bag::addTokens() const {
    // TODO: write a loop that enumerates the entire bag
	// and sums the total of all of the Token values
    int sumOfTokens = 0, valueOfToken = 0;  
    for(int count1 = 0; count1< contents.size(); count1++) //Since the count starts at 0
    {
    
        sumOfTokens += contents[count1].getValue();
    }
    return sumOfTokens;
}

int Bag::highValueTokens() const {
    // TODO: write a loop that enumerates the entire bag
    // and returns the number of high value Tokens
    int counter = 0; 
    for(int count = 0; count< contents.size(); count++)
    {
        if(contents[count].isHighValue())
        {
            counter++; //Only increment the count 
        }
    }
    
    return counter;	
}

int Bag::firstGreen() const {
    // TODO: search bag for a green Token, if found, return its index

    for(int count2 = 0; count2< contents.size(); count2++)
        {
            if(contents[count2].getColor() == "Green")
            {
                return count2; 
            }
        }
    return -1;
}