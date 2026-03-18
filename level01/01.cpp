import std;
using namespace std;

auto main() -> int {
	println("Hello World C++23");

	//{[arg-id]:[fill-and-align][sign][#][0][width][.precision][L][type]}
	//:[fill-and-align][width]
	println("{:>10}", "hi");
	println("{:<10}", "hi");
	println("{:^10}", "hi");
	println("{:*^10}", "hi");

	//:[sign]
	println("{:+}", 42); // 항상 부호
	println("{: }", 42); // 양수는 공백
	println("{:-}", 42); // 음수만 부호 (기본값)

	//[#]
	println("{:#x}", 255);   // "0xff"
	println("{:#o}", 8);     // "010"
	println("{:#b}", 5);     // "0b101

	//[width][.precision]
	println("{:10}", 42);     // "        42"
	println("{:.5f}", 3.14);  // "3.14000"
	println("{:{}.{}}", 3.14, 8, 3);  // 동적 width/precision

	//[sign][0][width]
	println("{:08}", 42);   // "00000042"
	println("{:+08}", 42);  // "+0000042"

	//[L]
	std::cout << format(locale("ko_KR"), "{:L}", 1000000) << endl;  // "1,000,000"

	//? — escaped 출력
	println("{:?}", "hello\nworld");  // "\"hello\\nworld\""
	println("{:?}", '\t');           // "'\\t'"

	return 0;
}