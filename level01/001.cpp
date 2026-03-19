import std;
using namespace std;

auto main() -> int {
	println("Hello World C++23");

	//{[arg-id]:[[fill]align][sign][#][0][width][.precision][L][type]}
	//[arg-id]
	println("{2} {1} {0}", "one", "two", "three");	//"three two one"

	//:[[fill]align][width][type]
	//[type]: d b/B o x/X f/F e/E g/G a/A c s p ? #
	println("{:>10}", "hi");	//"        hi"
	println("{:<10}", "hi");	//"hi        "
	println("{:^10}", "hi");	//"    hi    "
	println("{:*^10}", "hi");	//"****hi****"
	//println("{:*10}", "hi");	//Runtime Error fill만 올수는 없음
	println("{:?}", "hi");	    //""hi""
	println("{}", format("{:?}", "hello\nworld"));  // "\"hello\\nworld\""
	println("{:?}", '\t');           // "'\\t'"

	//[L]
	println("{}", format(locale("ko_KR"), "{:L}", 1000000));  // "1,000,000"
	return 0;
}