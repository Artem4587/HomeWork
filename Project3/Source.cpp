#include <iostream>

class ClassA {
private:
	int num1;
	int num2;

public:
	ClassA(int a, int b) : num1(a), num2(b) {}

	friend int addAllFields(const ClassA& objA, const ClassB& objB); // ���������� ������������� �������
};

class ClassB {
private:
	int num3;
	int num4;

public:
	ClassB(int c, int d) : num3(c), num4(d) {}

	friend int addAllFields(const ClassA& objA, const ClassB& objB); // ���������� ������������� �������
};

// ������������� �������, ������������ ��� ���� �� ClassA � ClassB
int addAllFields(const ClassA& objA, const ClassB& objB) {
	return objA.num1 + objA.num2 + objB.num3 + objB.num4;
}

int main() {
	ClassA objA(10, 20);
	ClassB objB(30, 40);

	int sum = addAllFields(objA, objB);
	std::cout << "����� ���� �����: " << sum << std::endl; // �����: ����� ���� �����: 100

	return 0;
}