import std;
using namespace std;

auto main() -> int {
	println("Hello World C++23");

	//{[arg-id]:[fill-and-align][sign][#][0][width][.precision][L][type]}
	//[arg-id]
	println("{2} {1} {0}", "one", "two", "three");	//"three two one"

	//:[fill-and-align][width]
	//? — escaped 출력
	println("{:>10}", "hi");	//"        hi"
	println("{:<10}", "hi");	//"hi        "
	println("{:^10}", "hi");	//"    hi    "
	println("{:*^10}", "hi");	//"****hi****"
	println("{:?}", "hi");	    //""hi""
	println("{}", format("{:?}", "hello\nworld"));  // "\"hello\\nworld\""
	println("{:?}", '\t');           // "'\\t'"

	//[L]
	println("{}", format(locale("ko_KR"), "{:L}", 1000000));  // "1,000,000"
	return 0;
}