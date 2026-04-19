import std;
using namespace std;
using namespace std::filesystem;

auto main() -> int {
	auto p = path("C:/test.mp4");
	directory_entry entry{ p };
	cout << entry << endl;
	for (const directory_entry& item : directory_iterator("C:/")) {
		cout << item << endl;
	}
	return 0;
}