#pragma once
#include <string>

class HuffmanNode {
private:

  std::string _name;
  double _prob;
  const HuffmanNode *_left_child;
  const HuffmanNode *_right_child;

public:

  HuffmanNode( std::string letter = std::string(), double prob = 0.0, HuffmanNode *left = nullptr, HuffmanNode *right = nullptr )
    : _name( letter ), _prob( prob ), _left_child( left ), _right_child( right ) {}
  
  HuffmanNode( const HuffmanNode& node ) 
    : _name( node.name() ), _prob( node.probability() ), _left_child( node.left() ), _right_child( node.right() ) {}
  
  HuffmanNode( const HuffmanNode&& node ) noexcept
    : _name( node.name() ), _prob( node.probability() ), _left_child( node.left() ), _right_child( node.right() ) {}
  
  HuffmanNode( const HuffmanNode* node1, const HuffmanNode* node2 );
  ~HuffmanNode();

  std::string name() const { return _name; }
  double probability() const { return _prob; }
  const HuffmanNode *left() const { return _left_child; }
  const HuffmanNode *right() const { return _right_child; }

  void name( const std::string& l ) { _name = l; }
  void probability( const double p ) { _prob = p; }
  void left( HuffmanNode *child ) { _left_child = child; }
  void right( HuffmanNode *child ) { _right_child = child; }

  bool is_leaf() const { return !_left_child && !_right_child; }
  bool has_left_child() const { return _left_child; }
  bool has_right_child() const { return _right_child; }

  bool operator>( const HuffmanNode& rhs ) const { return _prob > rhs.probability(); }
  bool operator<( const HuffmanNode& rhs ) const { return _prob < rhs.probability(); }
  double operator+( double rhs ) const;
  HuffmanNode& operator=( const HuffmanNode& rhs );
  

};

std::ostream& operator<<( std::ostream& out, const HuffmanNode& node );
