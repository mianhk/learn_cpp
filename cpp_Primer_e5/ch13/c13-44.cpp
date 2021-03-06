#inlcude <iostream>

using namespace std;

class String{
	public:
		String()=default;
		String(const char *);
		String(const String&);
		String& operator=(const String&);
		~String();
		
		const char *c_cahr() const{ return elements;}
		size_t size() const {return end-elements;}
		size_t length() const {return end-elements-1;}
	private:
		char *elements;
		char *end;
		std::allocator<char> alloc;
		std::pair<char*,char*> alloc_n_copy(const char*,const char*);
		void range_initializer(const char*,const char*);
		void free();
};

String::String(const char *c){
	char *sl=const_cast<char *>(c);
	while(*sl){
		++sl;
	}
	range_initializer(s,++sl);
}

String::String(const String &rhs){
	range_initializer(rhs.elements,rhs.end);
	std::cout<<"������ֵ"<<std::endl;
}

String& String::operator=(const String &rhs){
	auto newstr=alloc_n_copy(rhs.elements,rhs.end);
	free();
	elements=newstr.first;
	end=newstr.second;
	return *this;
}

String::~String(){
	free();
}

void String::free(){
	if(elements){
		std::for_each(elements,end,[this](char *c){alloc.destory(&c);}
		);
		alloc.deallocate(elements,end-elements);
	}
}

std::pair<char *c,char *c> alloc_n_copy(const char *b,const char *e){
	auto str=alloc.allocate(e-b);
	return {str,std::uninitialized_copy(b,e,str)};
}

void String::range_initializer(const char *first,const char *last){
	auto newstr=alloc_n_copy(first,last);
	elements=newstr.first;
	end=newstr.second;
}
int main(){
	return 0;
}
