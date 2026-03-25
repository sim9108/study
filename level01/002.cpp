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
	println("{:#x}", 255);			  // "0xff"
	println("{:#o}", 8);			  // "010"
	println("{:#b}", 5);			  // "0b101		
	println("{:#}", 123.0);           // "123."
	println("{}", 123.0);             // "123"
	println("{:+#10X}", 'x');         // "     +0X78"
	println("{:+#010X}", 'x');        // "+0X0000078"
	println("{:0>+#10X}", 'x');       // "00000+0X78"
	println("{:#010x}", 255);		  // "0x000000ff"		
	println("{:010.5f}", 3.14);		  // "0003.14000"
	println("{:02}", 1234);	          // "1234"
	println("{:*<6}", "12345678");    // "12345678"
	println("{:_<6.3}", "123hello");  // "123___"
	println("{:{}.{}}", 3.14, 8, 3);  // 동적 width/precision
	return 0;
}