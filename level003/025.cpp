import std;
using namespace std;

void stringbuf_test() {
    using char_type = stringbuf::char_type;
    using traits_type = stringbuf::traits_type;
       
    do {
        stringbuf buf{ ios_base::in | ios_base::out };

        // 쓰기
        string data{ "string " };
        char_type c[]("12345");        
        buf.sputn(data.c_str(), data.size());        
        buf.sputn(c, traits_type::length(c));
        
        // 읽기
        char_type temp1[5]{}, temp2[5]{};
        buf.sgetn(temp1, 5);
        buf.sgetn(temp2, 5);
        println("temp1:{:.5} temp2:{:.5}", temp1, temp2);

        println("in|out:{}", buf.view());
    } while (false);

    do {
        stringbuf buf{ ios_base::out };        
        // 쓰기
        string data{ "string " };
        char_type c[]("12345");
        buf.sputn(data.c_str(), data.size());        
        buf.sputn(c, traits_type::length(c));
        
        println("out:{}", buf.view());
    } while (false);
   
    do {
        stringbuf buf{ ios_base::in };
        buf.str(string("012345678901234567890"));

        // 읽기
        char_type temp1[5]{}, temp2[5]{};
        buf.sgetn(temp1, 5);
        buf.sgetn(temp2, 5);
        println("temp1:{:.5} temp2:{:.5}", temp1, temp2);

        println("in:{}", buf.view());
    } while (false);
    return;
}

void stringstream_test() {
    using stream_type = stringstream;
    using pos_type = stream_type::pos_type;
    using off_type = stream_type::off_type;
    using char_type = stream_type::char_type;

    stringstream ss{ "0123456789" };
    ss.seekg(pos_type{ 9 });
    ss.seekp(pos_type{ 0 });
    
    ss << ss.widen('A');
    char_type c{};
    ss >> c;

    println("{} {}", ss.view(), c);
}

void fstream_stringstream_test() {
    do {
        ofstream fo("test.txt");
        fo << "The most popular movies and TV shows on Netflix in the World.";
    } while (false);

    stringstream ss;
    do {        
        ifstream fi("test.txt");
        ss << fi.rdbuf();
    } while (false);
    println("{}", ss.view());
}

auto main() -> int {
    stringbuf_test();
    stringstream_test();
    fstream_stringstream_test();
    return 0;
}