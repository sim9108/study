import std;
using namespace std;
using namespace std::filesystem;

void append(path const& lhs, const path& rhs) {
	path app = lhs / rhs;
	wstringstream ss;
	ss << L"path(" << lhs << L") /= path(" << rhs << L")";
	wcout << setw(40) << left << ss.str() << ";// path(" << app << L")" << endl;
}

auto main() -> int {	 
	// [root-name][root-directory][relative-path]
	
	// 1. rhs 전체를 특정할 수 있는 경우
	// rhs.is_absolute()
	// rhs.has_root_name() && rhs.root_name() != root_name()
	append("foo", "c:/bar");	
	append("d:foo", "c:bar");append("foo", "c:");
	

	// 2. rhs의 root-directory 이후를 특정할 수 있는 경우
	// rhs.has_root_directory()
	append("c:", "/"); append("foo", "/"); append("c:foo", "/bar");
	append("//host", "/foo"); append("//host/", "/foo");
	append(".", "/bar");

	// rhs 구조:[root-name][][relative-path]
	// rhs.has_root_name() && rhs.root_name() == root_name() => 결합시 중복된 root-name 소거 필요
	// !rhs.has_root_path()
	

	// 3-1. rhs가 lhs에 대한 상대 경로가 되기 위해 separator가 필요한 경우
	// !has_root_directory() && is_absolute()	
	// has_filename()
	append("foo", ""); append("c:/foo", ""); append("c:/foo", "bar");
	append("foo", "bar"); append("c:/foo", "c:bar");append("c:foo", "bar");
	append(".", "bar");

	// 3-2. rhs가 lhs에 대한 상대 경로가 되기 위해 separator가 필요없는 경우
	append("c:", ""); append("c:/folder/", "bar"); 
	append("c:", "c:bar"); append("c:/folder/", "c:bar");	 
	return 0;
}