/*
    CS3 
    Deck of Cards

*/
#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "CardHand.h"
#include "PokerScore.h"
#include "CardHandScorer.h"

int main()
{
    PokerScore pokerScore;

    ////TEST SPECIFIC COMBINATIONS
    //Deck* deck = new Deck;
    //deck->shuffleDeck();

    //CardHand* ch = new CardHand;
    //Card c1 = { "Spades", "Ace" };
    //ch->addCard(c1);
    //Card c2 = { "Diamonds", "Ace" };
    //ch->addCard(c2);
    //Card c3 = { "Clubs", "Ten" };
    //ch->addCard(c3);
    //Card c4 = { "Hearts", "Ten" };
    //ch->addCard(c4);
    //Card c5 = { "Hearts", "Ace" };
    //ch->addCard(c5);

    //ch->printHand();
    //CardHandScorer chs;
    //chs.scoreHand(*ch);
    //pokerScore += chs.scoreMap;

    //delete deck;
    //delete ch;

    
    //TEST MULTIPLE HANDS
    for (int i = 0; i < 10000; i++) {

        Deck * deck = new Deck;
        deck->shuffleDeck();

        CardHand * ch = new CardHand;

        for (int i = 0; i < 5; i++) {
            ch->addCard(deck->nextCard());
        }

        //ch->printHand();

        CardHandScorer chs;
        chs.scoreHand(*ch);

        pokerScore += chs.scoreMap;

        delete deck;
        delete ch;
    }

    pokerScore.printScores();
}

