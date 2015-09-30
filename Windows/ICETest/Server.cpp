#include "PrintI.h"

int main(int argc, char** argv)
{
	Ice::CommunicatorPtr ic;

	//����ͨ����
	ic = Ice::initialize(argc, argv);

	//�����������������󶨶˿�
	Ice::ObjectAdapterPtr adapter = ic->createObjectAdapterWithEndpoints(
		"simplePrinterAdapter", "default -p 10000");

	Ice::ObjectPtr object = new PrinterI;

	//����Ice����ʵ����ָ����ʶ��
	adapter->add(object, ic->stringToIdentity("SimplePrinter"));

	//����������
	adapter->activate();

	//����ý���
	ic->waitForShutdown();
}