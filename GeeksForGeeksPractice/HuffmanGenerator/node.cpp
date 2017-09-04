

#include "node.h"
#include <iostream>

using namespace std;


HuffmanNode::HuffmanNode( const HuffmanNode* node1, const HuffmanNode* node2 )
  :_name( "&" ), _prob( node1->probability() + node2->probability() ) {
  
  if( *node1 < *node2 ) {
    _left_child = node1;
    _right_child = node2;
  } else {
    _left_child = node2;
    _right_child = node1;
  }

}

HuffmanNode::~HuffmanNode() {}

double HuffmanNode::operator+( double rhs ) const {
  return rhs + _prob;
}

HuffmanNode& HuffmanNode::operator=( const HuffmanNode& rhs ) {
  _name = rhs.name();
  _prob = rhs.probability();
  _left_child = rhs.left();
  _right_child = rhs.right();
  return *this;
}

ostream& operator<<( ostream& out, const HuffmanNode& node ) {
  return out << node.name() << ": " << node.probability();
}
