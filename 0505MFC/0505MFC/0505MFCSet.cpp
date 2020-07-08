
// 0505MFCSet.cpp : CMy0505MFCSet ���ʵ��
//

#include "stdafx.h"
#include "0505MFC.h"
#include "0505MFCSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0505MFCSet ʵ��

// ���������� 2020��7��6��, 22:06

IMPLEMENT_DYNAMIC(CMy0505MFCSet, CRecordset)

CMy0505MFCSet::CMy0505MFCSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	column1 = L"";
	column2 = L"";
	column3 = L"";
	column4 = L"";
	column5 = L"";
	column6 = L"";
	column7 = L"";
	column8 = L"";
	m_nFields = 9;
	m_nDefaultType = snapshot;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMy0505MFCSet::GetDefaultConnect()
{
	return _T("DSN=\x5b66\x751f\x4fe1\x606f\x6570\x636e\x5e93;DBQ=C:\\USERS\\MI\\Documents\\\x5b66\x751f\x4fe1\x606f\x6570\x636e\x5e93.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;PWD=1804574837.;UID=admin;");
}

CString CMy0505MFCSet::GetDefaultSQL()
{
	return _T("[ѧ����Ϣ��]");
}

void CMy0505MFCSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[����]"), column1);
	RFX_Text(pFX, _T("[ѧ��]"), column2);
	RFX_Text(pFX, _T("[רҵ]"), column3);
	RFX_Text(pFX, _T("[�Ա�]"), column4);
	RFX_Text(pFX, _T("[��������]"), column5);
	RFX_Text(pFX, _T("[�ֻ�����]"), column6);
	RFX_Text(pFX, _T("[��ͥסַ]"), column7);
	RFX_Text(pFX, _T("[��Ƭ·��]"), column8);

}
/////////////////////////////////////////////////////////////////////////////
// CMy0505MFCSet ���

#ifdef _DEBUG
void CMy0505MFCSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMy0505MFCSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

