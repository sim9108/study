import std;
using namespace std;
using namespace std::filesystem;
using namespace ranges;

auto main() -> int {
	error_code ec;
	directory_iterator files{ ".",directory_options::skip_permission_denied,ec };

	auto iter = ranges::find(
		directory_iterator{ ".",directory_options::skip_permission_denied,ec },
		default_sentinel,
		path(".") / "ConsoleApplication3.cpp",
		&directory_entry::path
	);

	println("Find:{:d}", iter != default_sentinel);

	if (ec) cout << ec.message() << endl;
	return 0;
}