
#pragma once

#include "node.h"
#include <vector>
#include <set>
#include <bitset>
#include <map>

class HuffmanTree {
  using HuffmanCode = std::multimap< std::string, std::vector< bool > >;
  HuffmanNode _root;
  HuffmanCode _code;

  

public:
  HuffmanTree( const HuffmanNode& node );

  explicit HuffmanTree( std::multiset<HuffmanNode>& nodes );

  ~HuffmanTree(){}
  
  const HuffmanNode& root() const { return _root; }
  static double sum( const std::multiset<HuffmanNode>& nodes );
  static void code( const HuffmanNode& next, std::vector<bool> bits, HuffmanCode& codes );
  static HuffmanNode& build( std::multiset<HuffmanNode>& nodes );
  void print_codes( std::ostream& out );
  
};


