//File: a0.cpp
#include<iostream>
#include<string>

int main(){
  //set your name
  std::string name = "Aniruddha Nandi";

  //set to true if code was tested
  bool has_tested = true;

  //set number of tests
  int num_tests = 10;

  std::cout << name;

  if(has_tested) {
    std::cout << " performed " << num_tests << " test(s)" << std::endl;
  } else  {
    std::cout << " was lazy" << std::endl;
  }

  return 0;
} //main
