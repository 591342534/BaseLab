#include <Ice/Ice.h>
#include "../slice/print.h"

using namespace std;
using namespace Demo;

int main(int argc, char** argv)
{
	Ice::CommunicatorPtr ic;
	//����ͨ����
	ic = Ice::initialize(argc, argv);
	//���Ice�������SimplePrinter-�����ʶ����default -p 10000-Э����˿�
	Ice::ObjectPrx base = ic->stringToProxy("SimplePrinter:default -p 10000");
	//����ת��
	PrinterPrx printer = PrinterPrx::checkedCast(base);
	if (!printer) throw "Invalid proxy";
	//���ò���
	printer->printString("Hello World!");
}
