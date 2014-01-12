#include "../src/When.h"

#include <iostream>




int main()
{
When::Defered<int, float> defer = When::defer<int, float>();
When::Promise<int, float> p = defer.promise();

 When::Promise<std::string> p2 = p.then ([] (int a, float b) -> std::string {
	std::cout << "Defered was resolved with [" << a << ", " << b << "]" << std::endl;
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
// defer.resolve(42, 4.2);
//
// OR
//
// defer.reject("There was an error");
//
}
