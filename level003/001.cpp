import std;

auto main() -> int {

    // <iostream> : 8 stream object: cin win cout wcout cerr werr clog wlog
    // <stdio.h>  : 3 FILE* handle : stdin stdout stderr
    // 
    // [input]
    // cin  ➡ buffer ⬅ stdin : cin.tie():&cout    
    // win  ➡ buffer ⬅ stdin : win.tie():&wcout
    // 
    // [output]
    // cout ➡ buffer ⬅ stdout  
    // wout ➡ buffer ⬅ stdout
    // 
    // cerr ➡ buffer ⬅ stderr: cerr.tie():&cout / cerr.flags() & unitbuf
    // werr ➡ buffer ⬅ stderr: werr.tie():&wout / werr.flags() & unitbuf
    // clog ➡ buffer ⬅ stderr       
    // wlog ➡ buffer ⬅ stderr

    // ios_base::sync_with_stdio(true)
    // iostream:obj ⇄ stdio FILE* handle:f
    // obj.rdbuf()->sputc(c) ⇄  fputc(f,c)
    // c = obj.rdbuf()->sbumpc() ⇄  c = fgetc(f)
    // obj.rdbuf()->sputbackc(c) ⇄  ungetc(c,f)
    // 
    // stream buffer과 stdio buffer를 동기화 구현 방법
    // C++ 스트림이 자신의 독립적인 버퍼를 갖지 않고, 
    // 모든 작업을 C의 stdio 함수를 통해 수행하게 만드는 것

    std::ios_base::sync_with_stdio(false);
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            std::cout << i << '\n';
        }
        else {
            std::printf("%d\n", i);
        }
    }

    return 0;
}