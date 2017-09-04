//Stickler is a thief and wants to loot money from a society of n houses placed in a line.
//He is a weird person and follows a rule while looting the houses and according to the rule he 
//will never loot two consecutive houses.At the same time, he wants to maximize the amount he 
//loots.The thief knows which house has what amount of money but is unable to find the maximum 
//amount he can end up with.He asks for your help to find the maximum money he can get if he 
//strictly follows the rule.Each house has a[i] amount of money present in it.
//
//Input:
//The first line of input contains an integer T denoting the number of test cases.Each test case 
//contains an integer n which denotes the number of elements in the array a[].Next line contains 
//space separated n elements in the array a[].
//
//Output:
//	Print an integer which denotes the maximum amount he can take home.
//
//		Constraints :
//		1 <= T <= 100
//		1 <= n <= 1000
//		1 <= a[i] <= 10000
//
//		Example :
//		Input :
//		2
//		6
//		5 5 10 100 10 5
//		3
//		1 2 3
//
//		Output :
//		110
//		4
//
//  URL: http://practice.geeksforgeeks.org/problems/stickler-theif/0

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int compute_max( const vector<int>& society ) {
  switch( society.size() ) {
  case 1:
  case 2:
    return society.at( 0 );
  case 3:
    return society.at( 0 ) + compute_max( vector<int>( society.begin() + 2, society.end() ) );
  default:
    int m0 = compute_max( vector<int>( society.begin() + 2, society.end() ) );
    int m1 = compute_max( vector<int>( society.begin() + 3, society.end() ) );
    return society.at( 0 ) + ( m0 > m1 ? m0 : m1 );
  }
}

int main() {
  ifstream input_file;
  string input_filename;
  vector< vector< int > > cases;
  int num_cases, num_houses;

  cout << "Input filename: " << endl;
  cin >> input_filename;

  input_file.open( input_filename );

  if( !input_file.is_open() ) {
    cout << "Error opening file." << endl;
    return -1;
  }

  input_file >> num_cases;

  for( int case_num = 0; case_num < num_cases; case_num++ ) {
    input_file >> num_houses;
    cases.push_back( vector<int>() );
    for( int house_num = 0; house_num < num_houses; house_num++ ) {
      int money;
      input_file >> money;
      cases[ case_num ].push_back( money );
    }
  }

  for( auto& c : cases )
    cout << compute_max( c ) << endl;

  getchar(); 
  getchar();
}
