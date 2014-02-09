#include "../src/When.h"

#include <iostream>


using namespace When;

int main()
{
    Deferred<int> defer = deferred<int>();
    Promise<int> p = defer.promise();

    Promise<std::string> p2 = p.then ([] (int a) -> std::string {
	    std::cout << "Defered was resolved with [" << a << "]" << std::endl;
	    return "Success";
	});

    p.otherwise([] (const std::string& error) -> void {
	    std::cout << "Defer was rejected with [" << error << "]" << std::endl;
	});


    auto p3 = p2.then([] (const std::string& result) -> void {
	    std::cout << "2nd Defer was resolved with [" << result << "]" << std::endl;
	});

    p2.otherwise([] ( const std::string& err) {
	    std::cout << "2nd Defer was rejected with [" << err << "]" << std::endl;
	});


    p3.then ([] (const bool& b) { 
	    std::cout << "3rd defer resolved with [" << b << "]" << std::endl;
	});


    //
    defer.resolve(42);
    //
    // OR
    //
    // defer.reject("There was an error");
    //
}
