import std;
using namespace std;
using namespace std::filesystem;

auto main() -> int {
	const path p = path("C:\\AVerMedia\\AssistCentralPro\\styles\\qwindowsvistastyle.dll");
	cout <<"full path:" << p << endl;
	cout << "root-name:" << p.root_name()<<endl;
	cout << "root-directory:" << p.root_directory()<<endl;
	cout << "root-path:" << p.root_path() << endl;
	cout << "relative-path:\n";
	for (auto const& subpath : p.relative_path()) {
		cout << subpath << endl;
	}
	cout << "filename:" << p.filename() << endl;
	cout << "stem:" << p.stem() << endl;
	cout << "extension:" << p.extension() << endl;
	return 0;
}