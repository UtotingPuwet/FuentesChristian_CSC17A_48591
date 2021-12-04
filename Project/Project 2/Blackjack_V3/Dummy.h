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
    
    Dummy() {
        wins = 0;
        losses = 0;
        pushes = 0;
    }
  Dummy& operator++(int n) {
      wins++;
      losses++;
      pushes++;
      return *this;
  }  
  Dummy& operator--(int n) {
      wins--;
      losses--;
      pushes--;
      return *this;
  }
  Dummy& operator+(const Dummy& p2) {
      wins = this->wins + p2.wins;
      losses = this->losses + p2.losses;
      pushes = this->pushes +  p2.pushes;
      return *this;
  }
  Dummy& operator-(const Dummy& p2) {
      wins = this->wins - p2.wins;
      losses = this->losses - p2.losses;
      pushes = this->pushes - p2.pushes;
      return *this;
  }
};


#endif /* DUMMY_H */

