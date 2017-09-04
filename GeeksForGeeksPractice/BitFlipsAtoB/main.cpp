//Count number of bits to be flipped to convert A to B
//Given two numbers �a� and b�. Write a program to count number of bits needed to be flipped to convert �a� to �b�.
//
//Example :
//
//Input : a = 10, b = 20
//  Output : 4
//  Binary representation of a is 00001010
//  Binary representation of b is 00010100
//  We need to flip highlighted four bits in a
//  to make it b.
//
//  Input : a = 7, b = 10
//  Output : 3
//  Binary representation of a is 00000111
//  Binary representation of b is 00001010
//  We need to flip highlighted three bits in a
//  to make it b.

#include <bitset>
#include <iostream>
using namespace std;

int main()
{
  int a = 7;
  int b = 10;
  bitset<64> bits = a ^ b;
    
  cout << bits.count() << endl;

  getchar();
}