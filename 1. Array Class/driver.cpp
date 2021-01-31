#include "Array.h"
#include <iostream>

void print_array(Array ericks_child)
{
  std::cout << '[';

  for (int i = 0; i < ericks_child.size(); i++)
  {
    std::cout << ericks_child[i];

    if (i < ericks_child.size()-1)
      std::cout << ',';
  }
  std::cout << "] \n";
}


int main (int argc, char * argv [])
{
  //function
  Array test_array(10, 'e');
  //Array::find(c, 1);
  print_array(test_array);
}

//readded