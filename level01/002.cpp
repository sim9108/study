import std;
using namespace std;

auto main() -> int {
	//{[arg-id]:[fill-and-align][sign][#][0][width][.precision][L][type]}
	//:[sign]
	println("{:+}", 42);		// 항상 부호
	println("{: }", 42);		// 양수는 공백
	println("{:-}", 42);		// 음수만 부호 (기본값)

	//[sign][#][0][width][.precision]
	println("{:#x}", 255);			  // "0xff"
	println("{:#o}", 8);			  // "010"
	println("{:#b}", 5);			  // "0b101	
	println("{:010}", 42);			  // "0000000042"
	println("{:+10}", 42);			  // "       +42"
	println("{:010.5f}", 3.14);		  // "0003.14000"
	println("{:{}.{}}", 3.14, 8, 3);  // 동적 width/precision
	return 0;
}