import std;
using namespace std;

auto main() -> int {
	//{[arg-id]:[[fill]align][sign][#][0][width][.precision][L][type]}
	//:[sign]
	println("{:_>+10}", 42);	      // "_______+42"
	println("{:_>-10}", 42);	      // "________42" (default)
	println("{:_> 10}", 42);		  // "_______ 42"

	println("{:?}", R"(test
)");                                 // "test\n"
	//[sign][#][0][width][.precision][type]
	//[type]: a/A b/B c d e/E f/F g/G o p/P s x/X ?
	println("{0:#b} {0:#d} {0:#o} {0:#x}", 42);  // "0b101010 42 052 0x2a"

	println("{:#}", 123.0);           // "123."
	println("{}", 123.0);             // "123"
	println("{:+#10X}", 'x');         // "     +0X78"
	println("{:+#010X}", 'x');        // "+0X0000078"
	println("{:_>+#10X}", 'x');       // "_____+0X78"
	println("{:#010x}", 255);		  // "0x000000ff"		
	println("{:010.5f}", 3.14);		  // "0003.14000"
	println("{:02}", 1234);	          // "1234"
	println("{:*<6}", "12345678");    // "12345678"
	println("{:_<6.3}", "123hello");  // "123___"
	println("{:<.5}...", "안녕하세");  // "안녕..."
	println("{:{}.{}}", 3.14, 8, 3);  // "    3.14" 동적 [width][.precision]
	return 0;
}