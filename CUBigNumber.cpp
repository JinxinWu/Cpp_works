/*5.��Ʋ�ʵ��һ�����й��졢����*��/��%��>��<��>=����=��!=�������ȹ��ܵ��޷��Ŵ����ࡣ
��ʾ��Ϊ�������㣬�޷��Ŵ����ڲ��������ʮ����λʱ���õ�λ��ǰ����λ�ں�ķ�ʽ��
ȥ����λ�����0���޷��Ŵ�����Ӧ֧�ָ��ƺ͸�ֵ��*/
#include "CUBigNumber.h"

int main()
{
	CUBigNumber C1, C2;
	cin >> C1;
	cin	>> C2;
	//���ԱȽ������
	TestCompare(C1, C2);
	//���ԼӼ��˳��������
	TextOperation(C1, C2);
}