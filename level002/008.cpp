import std;
using namespace std;
using namespace std::filesystem;

auto main() -> int {
	using enum directory_options;
	error_code ec;
	recursive_directory_iterator files{
		path(".")/"mydir"/"project",
		skip_permission_denied | follow_directory_symlink,
		ec
	};

	for (auto it = files; it != default_sentinel; ++it) {
		if (it->is_directory() && it->path().filename() == "skip") {
			it.disable_recursion_pending();
			continue;
		}

		println("path:{} depth:{}", it->path().string<char>(), it.depth());
	}

	if (ec) println("error:{}", ec.message());
	return 0;
}