//! @file
//! @brief Unit tests for Hello World
//!
//! @author Clement Jeannesson
//! @date   April 2021

// using BOOST.TEST
#define BOOST_TEST_MODULE HELLO-WORLD
#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

// what we need for implementing the tests
#include <string>   // std::string
#include <iostream> // std::cout
#include <sstream>  // std::stringstream


// what we're going to test
#include "0hello-world.h"


//! @test Test print
BOOST_AUTO_TEST_CASE( TestHelloWorld)
{

  std::stringstream buffer; 

  // Redirect std::cout to buffer
  std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

  //get the content of PrintHelloWorld() in buffer
  PrintHelloWorld();

  // Restore original buffer before exiting
  std::cout.rdbuf(prevcoutbuf);

  // evaluate the string content
  BOOST_CHECK_EQUAL(buffer.str() , "Hello World !\n" );
}

