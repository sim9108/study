\# 📚 C++23/C++26 스터디 예제



C++23 및 C++26 표준에서 새롭게 도입된 기능들을 직접 실행해보며 익히기 위한 예제 모음입니다.



\---



\## 📌 목차



\- \[소개](#소개)

\- \[다루는 주제](#다루는-주제)

\- \[빌드 환경](#빌드-환경)

\- \[디렉토리 구조](#디렉토리-구조)

\- \[예제 목록](#예제-목록)

\- \[참고 자료](#참고-자료)



\---



\## 소개



이 저장소는 C++23 및 C++26 표준 라이브러리와 언어 기능을 학습하기 위한 예제 코드를 담고 있습니다.  

각 예제는 표준 문서의 normative 텍스트를 기반으로 작성되었으며, 실제 동작을 확인할 수 있도록 구성되어 있습니다.



\---



\## 다루는 주제



\### C++23

\- `std::expected` — 오류 처리의 새로운 방식

\- `std::flat\_map` / `std::flat\_set` — 연속 메모리 기반 연관 컨테이너

\- `std::mdspan` — 다차원 배열 뷰

\- `std::print` / `std::println` — 타입 안전 출력

\- `std::stacktrace` — 런타임 스택 추적

\- `std::start\_lifetime\_as` — 객체 생애 시작 제어

\- Deducing `this` — 명시적 객체 매개변수

\- `import std;` — 표준 라이브러리 모듈화



\### C++26

\- `std::indirect<T>` — 값 의미론을 가진 간접 소유 스마트 포인터

\- `std::hazard\_pointer` — Lock-free 메모리 재활용

\- `std::contracts` — 계약 기반 프로그래밍 (pre/post/assert)

\- `std::execution` — 비동기/병렬 실행 모델 (P2300)

\- `std::is\_sufficiently\_aligned` — 정렬 검사 유틸리티

\- Reflection (`std::meta`) — 컴파일 타임 반영 (예정)



\### 메모리 관리 (공통)

\- `std::pmr` — 다형성 메모리 리소스

&#x20; - `monotonic\_buffer\_resource`

&#x20; - `synchronized\_pool\_resource`

&#x20; - `unsynchronized\_pool\_resource`

\- `std::allocator\_traits` / `pointer\_traits`

\- `std::assume\_aligned`

\- Slab allocator 패턴



\---



\## 빌드 환경



| 항목 | 권장 사양 |

|------|-----------|

| 컴파일러 | GCC 14+ / Clang 17+ / MSVC 19.38+ |

| 표준 | `-std=c++23` 또는 `-std=c++26` |

| 빌드 시스템 | CMake 3.28+ |



```bash

\# 예시 빌드

cmake -B build -DCMAKE\_CXX\_STANDARD=23

cmake --build build

```



> C++26 일부 기능은 아직 실험적 지원 단계일 수 있습니다.  

> 컴파일러별 지원 현황은 \[cppreference — Compiler support](https://en.cppreference.com/w/cpp/compiler\_support)를 참고하세요.



\---



\## 디렉토리 구조



```

cpp-study/

├── cpp23/

│   ├── expected/

│   ├── mdspan/

│   ├── print/

│   ├── stacktrace/

│   ├── start\_lifetime\_as/

│   └── deducing\_this/

├── cpp26/

│   ├── indirect/

│   ├── contracts/

│   └── execution/

├── memory/

│   ├── pmr/

│   ├── allocator\_traits/

│   └── slab/

└── CMakeLists.txt

```



\---



\## 예제 목록



\### `std::expected` (C++23)



```cpp

\#include <expected>

\#include <string>



std::expected<int, std::string> parse(const std::string\& s) {

&#x20;   if (s.empty()) return std::unexpected("빈 문자열");

&#x20;   return std::stoi(s);

}



int main() {

&#x20;   auto result = parse("42");

&#x20;   if (result) {

&#x20;       // \*result == 42

&#x20;   } else {

&#x20;       // result.error() == "빈 문자열"

&#x20;   }

}

```



\### `std::indirect<T>` (C++26)



```cpp

\#include <indirect>



struct Node {

&#x20;   int value;

&#x20;   std::indirect<Node> next; // 재귀적 값 타입

};

```



\### `std::pmr::monotonic\_buffer\_resource`



```cpp

\#include <memory\_resource>

\#include <vector>



std::byte buf\[1024];

std::pmr::monotonic\_buffer\_resource pool{buf, sizeof(buf)};

std::pmr::vector<int> v{\&pool};

v.push\_back(1);

```



\---



\## 참고 자료



\- \[cppreference.com](https://en.cppreference.com)

\- \[ISO C++ 표준 문서](https://isocpp.org/std/the-standard)

\- \[Compiler Support for C++23/26](https://en.cppreference.com/w/cpp/compiler\_support)

\- \[P2300 — `std::execution`](https://wg21.link/p2300)

\- \[P1950 — `std::indirect`](https://wg21.link/p1950)



\---



> 이 저장소는 개인 학습 목적으로 작성되었습니다.  

> 예제 코드는 표준 문서 기반으로 작성되었으나, 일부는 컴파일러 지원 여부에 따라 동작하지 않을 수 있습니다.

