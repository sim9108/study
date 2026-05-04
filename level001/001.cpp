import std;
using namespace std;

auto main() -> int {
	println("Hello World C++23");

	//{[arg-id]:[[fill]align][sign][#][0][width][.precision][L][type]}
	//[arg-id]
	println("{2} {1} {0}", "one", "two", "three");	//"three two one"

	//:[[fill]align][width][type]
	//[type]: a/A b/B c d e/E f/F g/G o p/P s x/X ?
	println("{:>10}", "hi");	//"        hi"
	println("{:<10}", "hi");	//"hi        "
	println("{:^10}", "hi");	//"    hi    "
	println("{:*^10}", "hi");	//"****hi****"
	//println("{:*10}", "hi");	//Runtime Error fill만 올수는 없음
	println("{:?}", "hi");	    //""hi""
	println("{}", format("{:?}", "hello\nworld"));  // "\"hello\\nworld\""
	println("{:?}", R"(test         
)");                                 // "test\n"
	println("{:?}", '\t');           // "'\\t'"

	//[L]
	println("{}", format(locale("ko_KR"), "{:L}", 1000000));  // "1,000,000"
	
	
    // std-format-spec: 
    //   [[fill]align][sign][#][0][width][.precision][L][type]
    // 표준 포맷 타입:(available) type
    //      charT*, const charT*, charT[N], string, string_view
    //      포인터(void*, const void*, nullptr_t)
    //      부동소수점(inf,NaN)
    //      정수형
    //      charT
    //      bool
    // arithmetic type = floating-point type(inf,NaN) + integral type(bool,charT포함)
    // 
    // presentation type vs (available) type
    // type: a/A b/B c d e/E f/F g/G o p/P s x/X ?
    // presentation type        : (available) type
    //   s ?                    : charT*, const charT*, charT[N], string,string_view (s)
    //   p/P                    : 포인터(void*, const void*, nullptr_t)
    //   a/A e/E f/F g/G        : 부동소수점(inf,NaN), g
    //   b/B d o x/X c          : 정수형(d)
    //   b/B d o x/X c ?        : charT(c)
    //   b/B d o x/X s          : bool(s)    
    // 
    // [[fill]align]: 
    //      패딩채움문자(single Unicode scalar value: utf-8 code unit:1~4),field width 1계산
    //      정렬
    //      표준 포맷 타입
    // [width]: 
    //      minimum field width
    //      dynamic width
    //      표준 포맷 타입    
    // [sign]: 
    //      부호 문자: + - space
    //      charT bool 타입이 아닌 arithmetic presentation type
    // 
    // [#]: 
    //      base 또는 decimal-pointer 표시 여부
    //      charT bool 타입이 아닌 arithmetic presentation type
    // 
    // [0]:
    //      선행제로(leading zero)
    //      charT bool 타입이 아닌 arithmetic presentation type, pointer type
    // 
    // [L]
    //      그룹 구분자, 소수점 구분자
    //      charT 타입이 아닌 arithmetic presentation type
    //   
    // [.precision]: 
    //      정밀도, 최대 표시 문자열(field width)
    //      floating-point,string 타입
    //      dynamic precision
	return 0;
}