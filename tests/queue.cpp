#include <catch.hpp>
#include <sstream>
#include "queue_t.cpp"

TEST_CASE("pop/push")
{
    queue_t<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    
   
    std::ostringstream ostream;
    ostream<<q.pop();
    q.pop();
    q.pop();
    
    REQUIRE_THROWS(q.pop()); 
    
    REQUIRE( "1" == ostream.str() );
}
TEST_CASE("copy")
{
    queue_t<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    
    std::ostringstream ostream;
    queue_t<int> q1=q;
    
    ostream<<q1.pop();
    
    REQUIRE( "1" == ostream.str() );
}
