#include "../src/When.h"

#include <iostream>


int main()
{
    When::Deferred<int> defer = When::defer<int>();
    When::Promise<int> p = defer.promise();

    When::Promise<int> p2 = p.then ([] (int a) -> When::Promise<int> {
	    When::Deferred<int> d = When::defer<int>();
	    std::cout << "Defered was resolved with [" << a << "]" << std::endl;
	    d.resolve(84);
	    return d.promise();
	});

    p.otherwise([] (const std::string& error) -> void {
	    std::cout << "Defer was rejected with [" << error << "]" << std::endl;
	});


    p2.then([] (int result) -> void {
	    std::cout << "2nd Defer was resolved with [" << result << "]" << std::endl;
	});

    p2.otherwise([] (const std::string& error) -> void {
	    std::cout << "2nd Defer was rejected with [" << error << "]" << std::endl;
	});

    //
    defer.resolve(42);
    //
    // OR
    //
    // defer.reject("There was an error");
    //
}
