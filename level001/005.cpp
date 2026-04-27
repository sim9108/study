// /source-charset:UTF-8
// /execution-charset:UTF-8
// /UTF-8

// console code page
// literal encoding(source-charset/execution-charset)

import std;
using namespace std;
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

auto main() -> int {
    SetConsoleOutputCP(CP_UTF8);

    println("console code page:{}", GetConsoleOutputCP());
    println("execution literal encoding:{}", _MSVC_EXECUTION_CHARACTER_SET);
      

    string str1{ "안녕하세요" }, str2{ "👍🏽👍🏽" };

  println("{:-^20}", "println");
    println("{:*>20}\n{:*>20}", str1, str2);

    println("{:-^20}", "format");
    cout << format("{:*>20}\n{:*>20}\n", str1, str2);

    println("{:-^20}", "printf");
    printf("%0*s\n", 20, str1.data()); 
    printf("%0*s\n", 20, str2.data());

   println("{:-^20}", "cout");
   cout << setfill('*') << right << setw(20) << str1 << endl;
   cout << setfill('*') << right << setw(20) << str2 << endl;

   // SetConsoleOutputCP(CP_UTF8);
    // 글리프(Glyph)는 '문자' 
    // 글리프(Glyph) id를 code point로 부여
    //  문자:가 (U+AC00)
    //  UTF-8 Code Units: EA B0 80
    // 
    //  문자: á (a + 결합용 악센트)
    //  구성: a(U+0061) + ◌́ (U+0301)
    //  UTF - 8 Code Units : 61 + CC 81
    // 
    //  문자: 😀 (U+1F600)
    //  UTF-8 Code Units: F0 9F 98 80
    //  
    //  문자: 👍🏽 U+1F44D (👍) + U+1F3FD (🏽)
    //  UTF - 8 Code Units :F0 9F 91 8D + F0 9F 8F BD

    // 그래핀 클러스터(Grapheme Cluster)는 문자 문양에 대한 최소 단위
    //  👨‍👩‍👧:  
    //  👨(아빠) + ZWJ + 👩(엄마) + ZWJ + 👧(딸)

    //  각: NFD
    //   ㄱ (U+1100) + ㅏ (U+1161) + ㄱ (U+11A8)
    //  완성형(NFC)인 U+AC01

    // This document requires that identifiers be in Normalization Form C and 
    // therefore identifiers that compare the same under NFC are equivalent.
    // This is described in 5.11.(NFC)
    // The program is ill-formed if an identifier does not conform to
    // Normalization Form C as specified in the Unicode Standard.

    // std::setw는 code unit으로 폭 계산.
    // print: 포맷되는 가독성을 고려한 그래핌 클러스터(Grapheme Cluster) 폭: field width

    return 0;
}