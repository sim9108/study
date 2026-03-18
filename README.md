\# 📚 C++23/C++26 스터디 예제

C++23 및 C++26 표준에서 새롭게 도입된 기능들을 직접 실행해보며 익히기 위한 예제 모음입니다.

\---



\## 소개



이 저장소는 C++23 및 C++26 표준 라이브러리와 언어 기능을 학습하기 위한 예제 코드를 담고 있습니다.  

각 예제는 표준 문서의 normative 텍스트를 기반으로 작성되었으며, 실제 동작을 확인할 수 있도록 구성되어 있습니다.



\---



\## 다루는 주제



\### C++23

\- `std::expected` — 오류 처리의 새로운 방식

\- `std::flat_map` / `std::flat_set` — 연속 메모리 기반 연관 컨테이너

\- `std::mdspan` — 다차원 배열 뷰

\- `std::print` / `std::println` — 타입 안전 출력

\- `std::stacktrace` — 런타임 스택 추적

\- `std::start_lifetime_as` — 객체 생애 시작 제어

\- Deducing `this` — 명시적 객체 매개변수

\- `import std;` — 표준 라이브러리 모듈화



\### C++26

\- `std::indirect<T>` — 값 의미론을 가진 간접 소유 스마트 포인터

\- `std::hazard_pointer` — Lock-free 메모리 재활용

\- `std::contracts` — 계약 기반 프로그래밍 (pre/post/assert)

\- `std::execution` — Sender/Receiver Model 실행 모델 (P2300)

\- `std::is_sufficiently_aligned` — 정렬 검사 유틸리티

\- reflection (`std::meta`) — 컴파일 타임 반영



\### 메모리 관리 (공통)

\- `std::pmr` — 다형성 메모리 리소스

&#x20; - `monotonic_buffer_resource`

&#x20; - `synchronized_pool_resource`

&#x20; - `unsynchronized_pool_resource`

\- `std::allocator\_traits` / `pointer\_traits`

\- `std::assume\_aligned`



> C++26 일부 기능은 아직 실험적 지원 단계일 수 있습니다.  

> 컴파일러별 지원 현황은 \[cppreference — Compiler support](https://en.cppreference.com/w/cpp/compiler\_support)를 참고하세요.




\## 참고 자료


\- \[cppreference.com](https://en.cppreference.com)


\---


> 이 저장소는 개인 학습 목적으로 작성되었습니다.  