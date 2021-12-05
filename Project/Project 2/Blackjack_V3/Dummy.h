/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dummy.h
 * Author: UtotingPuwet
 *
 * Created on December 3, 2021, 4:59 PM
 */

#ifndef DUMMY_H
#define DUMMY_H



///Doesn't do anything in game.
///Dummy class only has wins losses and pushes. This is meant for the user to play with operator overloading + templates.
template <class T>
class Dummy {
private:
    T wins,
      losses,
      pushes;
public:
    
    T getWin() {return wins;}
    T getLoss() {return losses;}
    T getPush() {return pushes;}
    
    ///Default constructor
    ///Sets everything to 0
    Dummy() {
        wins = 0;
        losses = 0;
        pushes = 0;
    }
    
    ///Overload operator ++
    /// Adds 1 to wins/losses/pushes
    /// \param n doesn't matter but is needed to make it work.
    /// \return Dummy
    Dummy& operator++(int n) {
        wins++;
        losses++;
        pushes++;
        return *this;
    }
    ///Overload operator --
    /// Subtracts 1 to wins/losses/pushes
    /// \param n doesn't matter but is needed to make it work.
    /// \return Dummy
    Dummy& operator--(int n) {
        wins--;
        losses--;
        pushes--;
        return *this;
    }
    ///Overload operator +
    /// Lets user add two dummies together.
    /// \param p2 is the other Dummy.
    /// \return Dummy
    Dummy& operator+(const Dummy& p2) {
        wins = this->wins + p2.wins;
        losses = this->losses + p2.losses;
        pushes = this->pushes +  p2.pushes;
        return *this;
    }
    ///Overload operator -
    /// Lets use subtract to dummies together.
    /// \param p2 is the other Dummy.
    /// \return Dummy.
    Dummy& operator-(const Dummy& p2) {
        wins = this->wins - p2.wins;
        losses = this->losses - p2.losses;
        pushes = this->pushes - p2.pushes;
      return *this;
    }
};


#endif /* DUMMY_H */

