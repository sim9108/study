// / execution - charset:UTF - 8

import std;
using namespace std;

// format-spec:
//   std-format-spec(*)
//   range-format-spec(*)
//   tuple-format-spec(*)
//   path-format-spec/thread-id-format-spec/stacktrace-entry-format-spec
//   chrono-format-spec
//   user-defined formatter specializations

auto main() -> int {
    using namespace filesystem;
    path f = absolute(path("."));
    println("{}", f.string<char>());            // println("{}",    f);
    println("{:?}", f.string<char>());          // println("{:?}",  f);
    println("{}", f.generic_string<char>());    // println("{:g}",  f); 
    println("{:?}", f.generic_string<char>());  // println("{:?g}", f);

    // path-format-spec:
    //      [[fill]align][width][?][g]
    // 
    // UTF-8 literal encoding과 wchar_t => UTF-8 <-> wchart_t 가역성 보장
    //  최종 char 출력을 요구하더라도 UTF-8 code page 기반으로 출력(println처럼)
    //  가역 변환 실패시 유니코드 U+FFFD 대체 문자 사용
    // 
    // [?]:
    //      escaped string
    // 
    // [g]: for p:path
    //      g 옵션: p.generic_string<filesystem::path::value_type>()
    //      otherwise: p.native()
    // 
    // [[fill]align]:
    //      채움문자(single Unicode scalar value: utf-8 code unit:1~4),field width 1계산
    //          올수 없는 문자 { }
    //      정렬(< ^ >)
    //      가능한 포맷 타입
    // 
    // [width]: 
    //      minimum field width
    //      dynamic width
    //      가능한 포맷 타입    

    println("thread id:|{:10}|", this_thread::get_id());
    // thread-id-format-spec:
    //      [[fill]align][width]
    // 
    // [[fill]align] : >
    //      채움문자(single Unicode scalar value: utf-8 code unit:1~4),field width 1계산
    //          올수 없는 문자 { } 
    // [width]: 
    //      minimum field width
    //      dynamic width
    //      가능한 포맷 타입 

    auto&& trace = stacktrace::current();
    println("stacktrace🤡");
    println("{}", trace); // stacktrace-format-spec:

    println("stacktrace-entry🤡");
    for (const stacktrace_entry& entry : trace) { //stacktrace-entry-format-spec
        println("{:*<150}", entry);
    }

    // stacktrace-format-spec:
    //      empty
    // stacktrace-entry-format-spec: to_string(se) for stacktrace_entry se;
    //      [[fill]align][width]
    // [[fill]align] :
    //      채움문자(single Unicode scalar value: utf-8 code unit:1~4),field width 1계산
    //          올수 없는 문자 { } 
    // [width]: 
    //      minimum field width
    //      dynamic width
    //      가능한 포맷 타입 
    return 0;
}