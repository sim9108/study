import std;
using namespace std;

auto main() -> int {
    do {
        ofstream file("output.txt");

        if (!file) {
            println("output.txt 파일생성 실패");
            break;
        }

        println(file, "=== 포맷팅 테스트 ===");
        println(file, "숫자: {}", 42);
        println(file, "실수: {:.3f}", 3.141592);
        println(file, "정렬: {:_>10} | {:<10}", 123, "hello");
        println(file, "16진수: {:#x} {:#X}", 255, 255);
        println(file, "동적 너비: {:{}}", "hello", 15);

        // 문자열 자르기 예제
        println(file, "긴 문자열: {:.8}...", "안녕하세요 반갑습니다");
        println(file, "\n파일 출력 완료!");

        println("output.txt 파일 생성 성공");
    } while (false);

    return 0;
}