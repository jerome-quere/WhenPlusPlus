#include "../src/When.h"

#include <iostream>




int main()
{
    When::Deferred<int> defer = When::deferred<int>();
    When::Promise<int> p = defer.promise();

    When::Promise<std::string> p2 = p.then ([] (int a) -> std::string {
	    std::cout << "Defered was resolved with [" << a << "]" << std::endl;
	    return "Success";
	});

    p.otherwise([] (const std::string& error) -> void {
	    std::cout << "Defer was rejected with [" << error << "]" << std::endl;
	});


    p2.then([] (const std::string& result) -> void {
	    std::cout << "2nd Defer was resolved with [" << result << "]" << std::endl;
	});

    p2.otherwise([] (const std::string& error) -> void {
	    std::cout << "2nd Defer was rejected with [" << error << "]" << std::endl;
	});

    //
    //defer.resolve(42);
    //
    // OR
    //
    defer.reject("There was an error");
    //
}
