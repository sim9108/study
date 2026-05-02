import std;
using namespace std;


auto main() -> int {
    vector<pair<int, int>> m1{ {1, 2}, { 3, 4 } }; // queue, stack
    set<pair<int, int>>    m2{ {1, 2}, { 3, 4 } };
    map<int, int>          m3{ {1, 2}, { 3, 4 } };
    println("vector:{}", m1);
    println("set:{}", m2);
    println("map:{}", m3);

    vector<int> v = { 1, 2, 3, 4, 5, 6 };
    auto m4 = v | views::filter([](int n) { return n % 2 == 0; })
        | views::transform([](int n) { return n * n; });
    println("input range:{}", m4);

    println("vector:{:n}", m1);
    println("set:{:n}", m2);
    println("map:{:n}", m3);

    vector<char>                a1{ 'a','\t','c','d' };
    map<string, pair<int, int>> a2{ {"one", {1,2}}, {"two",{2,4}} };
    println("{:s}", a1);
    println("{:?s}", a1);
    println("{:m}", a2);

    vector<vector<string>> subdata{ {"one","two"},{"tree","four"} };
    println("{}", subdata);
    println("{::*^20}", subdata);
    println("{:::🤡^6}", subdata);
    // range-format-spec:
    //      [[range-fill]align][width][n][range-type][range-underlying-spec]
    // 
    // [n]:
    //      no bracket
    //      range-type인 s, ?s가 아닐 경우만 가능
    // [range-type]     : [ , ]
    //      m           : tuple_size_v<T>==2인 타입. "{", "}", ", "
    //      s           : charT 기반 range, string처럼 포맷
    //      ?s          : charT 기반 range, escaped string으로 포맷
    //
    // [[range-fill]align] : [[fill]align]와 동일
    //      채움문자(single Unicode scalar value: utf-8 code unit:1~4),field width 1계산
    //          올수 없는 문자 { } :
    //      정렬(< ^ >)
    //      가능한 포맷 타입
    // 
    // [width]: 
    //      minimum field width
    //      dynamic width
    //      가능한 포맷 타입    
    // range-underlying-spec: 
    //      : format-spec
    //          range-type인 s, ?s가 아닐 경우만 가능
    // 
    // format-spec:
    //      as specified by the formatter specialization for the argument type; 
    //          cannot start with }

    pair<int, int>  p1{ 1,2 };
    println("pair:{}", p1);
    println("pair:{:m}", p1);
    println("pair:{:n}", p1);


    // tuple-format-spec:
    //      [[tuple-fill]align][width][tuple-type]
    // 
    // [[tuple-fill]align]: [[fill]align]와 동일
    //      채움문자(single Unicode scalar value: utf-8 code unit:1~4),field width 1계산
    //          올수 없는 문자 { } :
    //      정렬(< ^ >)
    //      가능한 포맷 타입
    // 
    // [tuple-type]     : ( , )
    //      m           : ": ", no bracket
    //      n           : no bracket

    return 0;
}