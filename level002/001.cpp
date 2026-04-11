import std;
using namespace std;
using namespace std::filesystem;

void view_pathname_spec(const path& p) {
	// pathname:[root-path][relative-path]
	// pathname:[root-name][root-directory][relative-path]
	// root-directory:
	//		directory-separator
	// directory-separator:
	//		preferred-separator[directory-separator]
	//		fallback-separator[directory-separator]
	// relative-path:
	//		filename
	//		filename directory-separator[relative-path]
	//      empty path
	cout << "full path:" << p << endl;
	cout << "\troot-name:" << p.root_name() << endl;
	cout << "\troot-directory:" << p.root_directory() << endl;
	cout << "\troot-path:" << p.root_path() << endl;
	cout << "\trelative-path:\n";
	for (auto const& subpath : p.relative_path()) {
		cout << "\t\t" << subpath << endl;
	}
	cout << "\tfilename:" << p.filename() << endl;
	cout << "\tstem:" << p.stem() << endl;
	cout << "\textension:" << p.extension() << endl;
}

auto main() -> int {
	view_pathname_spec("C:/AVerMedia/qwindowsvistastyle.dll");
	view_pathname_spec("//AssistCentralPro/qwindowsvistastyle.dll");
	view_pathname_spec(".profile");
	view_pathname_spec("//AssistCentralPro/..");
	view_pathname_spec("//AssistCentralPro/.");
	return 0;
}