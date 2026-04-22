import std;
using namespace std;
using namespace std::filesystem;

auto main() -> int {
	error_code ec;
	do {
		using enum copy_options;
		path base = path(".") / "mydir";
		path src = base / "project";
		path target = base / "newdir";

		remove_all(target, ec);
		if (ec) break;

		copy_options opt = recursive | skip_symlinks;
		//copy_options opt = recursive | directories_only;
		copy(src, target, opt, ec);
		if (ec) break;
	} while (false);
	if (ec) println("error:{}", ec.message());
	return 0;
}