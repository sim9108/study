import std;
using namespace std;

auto main() -> int {
	//{[arg-id]:[[fill]align][sign][#][0][width][.precision][L][type]}
	//:[sign]
	println("{:_>+10}", 42);	      // "_______+42"
	println("{:_>-10}", 42);	      // "________42" (default)
	println("{:_> 10}", 42);		  // "_______ 42"

	//[sign][#][0][width][.precision][type]
	//[type]: a/A b/B c d e/E f/F g/G o p/P s x/X ?
	//[#]
	println("{0:#b} {0:#d} {0:#o} {0:#x}", 42);  // "0b101010 42 052 0x2a"
	println("{0:#} {0}", 123.0);      // "123. 123"
	//[[fill]align] vs [0]
	println("{:+#10X}", 'x');         // "     +0X78"
	println("{:+#010X}", 'x');        // "+0X0000078"
	println("{:_>+#010X}", 'x');      // "_____+0X78"

	//정밀도
	println("{:010.5f}", 3.14);		  // "0003.14000"
	println("{:_<6.3}", "123hello");  // "123___"
	println("{:<.5}...", "안녕하세");  // "안녕..."
	
	// smaller width than content size
	println("{0:02} {1:*<6}", 1234, "12345678"); // "1234 12345678"

	// 동적 넓이 동적 정밀도
	println("{:{}.{}}", 3.14, 8, 3);  // "    3.14"
	println("{:*^{}}", "hello", 10);  // "**hello***"
	return 0;
}