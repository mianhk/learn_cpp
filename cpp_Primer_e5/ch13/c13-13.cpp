#include <iostream>
#include <vector>
using namespace std;
struct X{
	X(){cout<<"���캯��X()"<<endl;
	}
	X(const X&){cout<<"�������캯��X(const X&)"<<endl;
	}
	X& operator=(const X &rhs){
		cout<<"������ֵ�����=(const X &rhs)"<<endl;
	}
	~X(){
		cout<<"��������~X()"<<endl;
	}
};
void f1(X x){
}
void f2(X &x){
}
int main()
{
	cout<<"�ֲ�����"<<endl;
	X x;
	cout<<endl;
	cout<<"�����ò�������"<<endl;
	f1(x);
	cout<<endl;
	cout<<"���ò�������"<<endl;
	f2(x);
	cout<<endl;
	
	cout<<"��̬���䣺"<<endl;
	X *px=new X;
	cout<<endl;
	
	cout<<"���ӵ������У�"<<endl;
	vector<X> vx;
	vx.push_back(x);
	cout<<endl;
	
	cout<<"�ͷŶ�̬����"<<endl;
	delete px;
	cout<<endl;
	
	cout<<"��ӳ�ʼ���͸�ֵ��"<<endl;
	X y=x;
	y=x;
	cout<<endl;
	
	cout<<"���������"<<endl;
	cout<<endl;
	
	
	return 0;
}
	