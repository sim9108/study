import std;
using namespace std;
using namespace std::filesystem;
using namespace ranges;

auto main() -> int {
	error_code ec;
	directory_iterator files{ ".",directory_options::skip_permission_denied,ec };

	auto range_files = files 
		| views::filter([](directory_entry const& f) {return f.is_regular_file(); })
		| views::transform([](directory_entry const& f) {return f.path().generic_string<char>(); })
		| to<vector<string>>();
	println("{}", range_files);

	if (ec) cout << ec.message() << endl;
	return 0;
}