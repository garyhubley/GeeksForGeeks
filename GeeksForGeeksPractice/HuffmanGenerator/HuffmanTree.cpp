#include "HuffmanTree.h"
#include <numeric>
#include <iostream>


HuffmanTree::HuffmanTree( const HuffmanNode& node )
  : _root( node ) {
  code( _root, std::vector<bool>(), _code );
}

HuffmanTree::HuffmanTree( std::multiset<HuffmanNode>& nodes ) { 
  _root = build( nodes );
  code( _root, std::vector<bool>(), _code );
}


double HuffmanTree::sum( const std::multiset<HuffmanNode>& nodes ) {
  double sum = 0.0;
  for( auto node : nodes )
    sum += node.probability();
  
  return sum;
}

std::vector<bool> operator+( std::vector<bool> vec, bool tmp ){
  vec.push_back( tmp );
  return vec;
}

void HuffmanTree::code( const HuffmanNode& next, std::vector<bool> bits, HuffmanCode& codes ) {
  
  if( next.is_leaf() ) {
    codes.emplace( next.name(), bits );
  } else {
    if( next.has_left_child() ) 
      code( *next.left(), bits + false, codes );
    
    if( next.has_right_child() )
      code( *next.right(), bits + true, codes );
  }
}

static HuffmanNode* extract_min( std::multiset<HuffmanNode>& nodes ) {
  auto temp_iter = nodes.begin();
  HuffmanNode *result = new HuffmanNode( *temp_iter );
  nodes.erase( temp_iter );
  return result;
}

HuffmanNode& HuffmanTree::build( std::multiset<HuffmanNode>& nodes ) {
  if( sum( nodes ) != 1 )
    throw std::domain_error( "Node probabilities must sum to 1" );

  while( nodes.size() > 1 ) 
    nodes.emplace( HuffmanNode( extract_min( nodes ), extract_min( nodes ) ) );
    
  return *extract_min( nodes );
}

std::ostream& operator<<( std::ostream& out, const std::vector<bool>& bits ) {
  for( auto bit : bits )
    out << bit;
  return out;
}

void HuffmanTree::print_codes( std::ostream& out ) {
  for( auto c : _code )
    out << c.first << ": " << c.second << std::endl;
}


