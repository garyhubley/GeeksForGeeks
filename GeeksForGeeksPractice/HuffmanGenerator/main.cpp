
#include "node.h"
#include <set>
#include <iostream>
#include "HuffmanTree.h"

using namespace std;

HuffmanNode build_huffman_tree( multiset<HuffmanNode>& nodes );
HuffmanNode *extract_min( multiset<HuffmanNode>& nodes );
int main() {
  multiset< HuffmanNode > letters;
  letters.insert( HuffmanNode( "a11", 0.01 ) );
  letters.insert( HuffmanNode( "a12", 0.02 ) );
  letters.insert( HuffmanNode( "a13", 0.03 ) );
  letters.insert( HuffmanNode( "a14", 0.04 ) );
  letters.insert( HuffmanNode( "a21", 0.02 ) );
  letters.insert( HuffmanNode( "a22", 0.04 ) );
  letters.insert( HuffmanNode( "a23", 0.06 ) );
  letters.insert( HuffmanNode( "a24", 0.08 ) );
  letters.insert( HuffmanNode( "a31", 0.03 ) );
  letters.insert( HuffmanNode( "a32", 0.06 ) );
  letters.insert( HuffmanNode( "a33", 0.09 ) );
  letters.insert( HuffmanNode( "a34", 0.12 ) );
  letters.insert( HuffmanNode( "a41", 0.04 ) );
  letters.insert( HuffmanNode( "a42", 0.08 ) );
  letters.insert( HuffmanNode( "a43", 0.12 ) );
  letters.insert( HuffmanNode( "a44", 0.16 ) );
  
  HuffmanTree tree( letters );

  tree.print_codes( cout );
  
  getchar();
}











