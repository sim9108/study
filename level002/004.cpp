import std;
using namespace std;
using namespace std::filesystem;

void lexicall_relative(path const& lhs, const path& base) {
	// path lexically_normal() const;
	// path lexically_proximate(const path& base) const;
	path app = lhs.lexically_relative(base);
	wstringstream ss;
	ss << L"path(" << lhs << L").lexically_relative(" << base << L")";
	wcout << setw(40) << left << ss.str() << ";// path(" << app << L")" << endl;
}

auto main() -> int {	
	// [root-name][root-directory][relative-path]

	// 계산 불가능:path() 반환
	// root_name() != base.root_name() 
	// !has_root_directory() && base.has_root_directory()
	// is_absolute() != base.is_absolute() 	
	lexicall_relative("c:a/b", "d:a/b/c");		
	lexicall_relative("c:a", "c:/a");
		
	// auto [a, b] = mismatch(begin(), end(), base.begin(), base.end());
	
	// a==end() && b==base.end() : path(".") 반환
	// path()/path("..") 연산을 반복할 횟수 n 계산: "", ".", ".."
	// n<0: path() 반환	
	// n==0 && (a==end() || a->empty()): path(".") 반환	
	// path()/path("..")/path("..") n반복/path([a, end()]) 반환	
	lexicall_relative("a/b", "a/b");	
	lexicall_relative("a/d/e", "a/b/c/.././f");
	lexicall_relative("a/d/e", "a/../");
	lexicall_relative("a/", "a/./");
	lexicall_relative("a/d/e", "a/b/e/f");	
	return 0;
}