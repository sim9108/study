import std;
using namespace std;
using namespace std::filesystem;

void f_status(const file_status& fst) {
	println("type:{:d} perm:{:#04X}",
		to_underlying(fst.type()), to_underlying(fst.permissions())
	);
}

void desc(path const& p) {
	error_code ec1{}, ec2{};
	file_status f1 = status(p, ec1);		
	 file_status f2 = symlink_status(p, ec2); // pathname resolution	
	f_status(f1);
	f_status(f2);

	if (ec1) {
		println("error1:{}", ec1.message());
	}
	if (ec2) {
		println("error2:{}", ec2.message());
	}
}

auto main() -> int {	
	// [root-name][root-directory][relative-path]
	desc("mydir/readme.txt");
	desc("mydir/sub1.lnk");


	error_code ec{};
	directory_entry entry{ "mydir/readme.txt" };
	println("file size:{}", entry.file_size());
	println("last_write_time:{}", entry.last_write_time());

	return 0;
}