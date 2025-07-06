#include <iostream>
#include<string>
#include<cctype>

using namespace std;
//1. Use simple string class
string up(string& a) {
	string res=a;

	for (int i = 0; i < a.length(); i++) {
		if ('a' <= res[i]&& res[i] <= 'z') res[i] += ('A' - 'a');		//stirng�� +char����?
	}
	return res;											//���� ��ȯ �ȵ�. --> �Լ� ����� ������ ����Ǿ �ν��Ͻ� �Ҹ�!
}
string down(string& a) {
	string res=a;

	for (int i = 0; i < a.length(); i++) {
		if ('A' <= res[i] && res[i] <= 'Z') res[i] -= ('A' - 'a');		
	}
	return res;
}


int main(int argc, char * argv[]) {
	string s=argv[2];
	for (int i = 3; i < argc; i++) {
		s+=" ";
		s += argv[i];
	}
	if(string(argv[1])=="up") cout << "to upper: " << up(s) << endl;
	else if (string(argv[1]) =="down")cout << "to lower: " << down(s) << endl;

	//2. Use string class's functions
	cout << "substr: " << s.substr(2, 3) << endl;		
	cout << "append: " << s.append("IjK") << endl;		
	cout << "insert: " << s.insert(2, "C++") << endl;	
	cout << "replace: " << s.replace(6, 2, "EF") << endl;
	cout << "erase: " << s.erase(3, 2)<<endl;					
	
}
